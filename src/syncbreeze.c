#include "syncbreeze.h"
#include <stdio.h>

type_SCA_InitSystem SCA_InitSystem = 0;
type_SCA_NetTransport_SCA_NetTransport SCA_NetTransport_SCA_NetTransport = 0;
type_SCA_NetTransport_Connect SCA_NetTransport_Connect = 0;
type_SCA_NetTransport_DeleteFileA SCA_NetTransport_DeleteFileA = 0;
type_SCA_NetTransport_UploadFile SCA_NetTransport_UploadFile = 0;
type_SCA_NetTransport_DownloadFile SCA_NetTransport_DownloadFile = 0;
type_SCA_NetTransport_Destroy SCA_NetTransport_Destroy = 0;

type_SCA_SyncBreezeInterface_SCA_SyncBreezeInterface SCA_SyncBreezeInterface_SCA_SyncBreezeInterface = 0;
type_SCA_SyncBreezeClient_SCA_SyncBreezeClient SCA_SyncBreezeClient_SCA_SyncBreezeClient = 0;
type_SCA_SyncBreezeClient_Connect SCA_SyncBreezeClient_Connect = 0;
type_SCA_SyncBreezeInterface_Login SCA_SyncBreezeInterface_Login = 0;
type_SCA_SyncBreezeInterface_AddSpaceMonitor SCA_SyncBreezeInterface_AddSpaceMonitor = 0;
type_SCA_SyncBreezeClient_LoginEx2 SCA_SyncBreezeClient_LoginEx2 = 0;
type_SCA_SyncBreezeClient_Destroy SCA_SyncBreezeClient_Destroy = 0;

type_SCA_SpaceMon_SCA_SpaceMon SCA_SpaceMon_SCA_SpaceMon = 0;
type_SCA_SpaceMonAction_SCA_SpaceMonAction SCA_SpaceMonAction_SCA_SpaceMonAction = 0;
type_SCA_SyncBreezeClient_GetSpaceMonitorListObj SCA_SyncBreezeClient_GetSpaceMonitorListObj = 0;
type_SCA_SyncBreezeClient_DeleteSpaceMonitor SCA_SyncBreezeClient_DeleteSpaceMonitor = 0;

type_SCA_ConfigObj_Load SCA_ConfigObj_Load = 0;
type_SCA_ConfigObj_SCA_ConfigObj SCA_ConfigObj_SCA_ConfigObj = 0;
type_SCA_ConfigObj_Show SCA_ConfigObj_Show = 0;
type_SCA_ConfigObj_GetField_cci SCA_ConfigObj_GetField_cci = 0;

PVOID SCA_ListItem_SCA_SpaceMonAction_vftable = 0;

int syncbreeze_init() {
	HMODULE hLibpal = LoadLibraryA("libpal.dll");
	if (!hLibpal) {
		printf("LoadLibraryA(libpal.dll) failed: %d\n", GetLastError());
		return -1;
	}
	SCA_InitSystem = (type_SCA_InitSystem)GetProcAddress(hLibpal, "?SCA_InitSystem@@YAHK@Z");
	SCA_NetTransport_SCA_NetTransport = (type_SCA_NetTransport_SCA_NetTransport)GetProcAddress(hLibpal, "??0SCA_NetTransport@@QEAA@PEAVSCA_NetLink@@@Z");
	SCA_NetTransport_Connect = (type_SCA_NetTransport_Connect)GetProcAddress(hLibpal, "?Connect@SCA_NetTransport@@QEAAHPEBDGKPEAK@Z");
	SCA_NetTransport_DeleteFileA = (type_SCA_NetTransport_DeleteFileA)GetProcAddress(hLibpal, "?DeleteFileA@SCA_NetTransport@@QEAAHPEBDPEAK@Z");
	SCA_NetTransport_UploadFile = (type_SCA_NetTransport_UploadFile)GetProcAddress(hLibpal, "?UploadFile@SCA_NetTransport@@QEAAHPEBD0KPEAKPEAVSCA_ProgressObj@@@Z");
	SCA_NetTransport_DownloadFile = (type_SCA_NetTransport_DownloadFile)GetProcAddress(hLibpal, "?DownloadFile@SCA_NetTransport@@QEAAHPEBD0KPEAKPEAVSCA_ProgressObj@@@Z");
	SCA_NetTransport_Destroy = (type_SCA_NetTransport_Destroy)GetProcAddress(hLibpal, "?Destroy@SCA_NetTransport@@UEAAXXZ");
	SCA_ConfigObj_Load = (type_SCA_ConfigObj_Load)GetProcAddress(hLibpal, "?Load@SCA_ConfigObj@@QEAAHPEBD0PEAK@Z");
	SCA_ConfigObj_SCA_ConfigObj = (type_SCA_ConfigObj_SCA_ConfigObj)GetProcAddress(hLibpal, "??0SCA_ConfigObj@@IEAA@PEAV0@@Z");
	SCA_ConfigObj_Show = (type_SCA_ConfigObj_Show)GetProcAddress(hLibpal, "?Show@SCA_ConfigObj@@QEAAHH@Z");
	SCA_ConfigObj_GetField_cci = (type_SCA_ConfigObj_GetField_cci)GetProcAddress(hLibpal, "?GetField@SCA_ConfigObj@@QEAAHPEBDPEADK@Z");

	if (!(SCA_InitSystem || 0)) {
		printf("libpal.dll functions resolving failed\n");
		return -1;
	}

	HMODULE hLibsync = LoadLibraryA("libsync.dll");
	if (!hLibsync) {
		printf("LoadLibraryA(libsync.dll) failed: %d\n", GetLastError());
		return -1;
	}
	SCA_SyncBreezeInterface_SCA_SyncBreezeInterface = (type_SCA_SyncBreezeInterface_SCA_SyncBreezeInterface)GetProcAddress(hLibsync, "??0SCA_SyncBreezeInterface@@QEAA@XZ");
	SCA_SyncBreezeClient_SCA_SyncBreezeClient = (type_SCA_SyncBreezeClient_SCA_SyncBreezeClient)GetProcAddress(hLibsync, "??0SCA_SyncBreezeClient@@QEAA@XZ");
	SCA_SyncBreezeClient_Connect = (type_SCA_SyncBreezeClient_Connect)GetProcAddress(hLibsync, "?Connect@SCA_SyncBreezeClient@@QEAAHPEBDGKPEAK@Z");
	SCA_SyncBreezeInterface_Login = (type_SCA_SyncBreezeInterface_Login)GetProcAddress(hLibsync, "?Login@SCA_SyncBreezeInterface@@QEAAHPEBD0PEAK111PEADK@Z");
	SCA_SyncBreezeInterface_AddSpaceMonitor = (type_SCA_SyncBreezeInterface_AddSpaceMonitor)GetProcAddress(hLibsync, "?AddSpaceMonitor@SCA_SyncBreezeInterface@@QEAAHPEAVSCA_SpaceMon@@@Z");
	SCA_SyncBreezeClient_GetSpaceMonitorListObj = (type_SCA_SyncBreezeClient_GetSpaceMonitorListObj)GetProcAddress(hLibsync, "?GetSpaceMonitorListObj@SCA_SyncBreezeClient@@UEAAHPEAPEAVSCA_ConfigObj@@K@Z");
	SCA_SyncBreezeClient_DeleteSpaceMonitor = (type_SCA_SyncBreezeClient_DeleteSpaceMonitor)GetProcAddress(hLibsync, "?DeleteSpaceMonitor@SCA_SyncBreezeClient@@UEAAHK@Z");
	SCA_SyncBreezeClient_LoginEx2 = (type_SCA_SyncBreezeClient_LoginEx2)GetProcAddress(hLibsync, "?LoginEx2@SCA_SyncBreezeClient@@UEAAHPEAVSCA_ConfigObj@@PEAPEAV2@@Z");
	SCA_SyncBreezeClient_Destroy = (type_SCA_SyncBreezeClient_Destroy)GetProcAddress(hLibsync, "??1SCA_SyncBreezeClient@@UEAA@XZ");

	HMODULE hLibspp = LoadLibraryA("libspp.dll");
	if (!hLibspp) {
		printf("LoadLibraryA(libspp.dll) failed: %d\n", GetLastError());
		return -1;
	}
	SCA_SpaceMon_SCA_SpaceMon = (type_SCA_SpaceMon_SCA_SpaceMon)GetProcAddress(hLibspp, "??0SCA_SpaceMon@@QEAA@XZ");
	SCA_SpaceMonAction_SCA_SpaceMonAction = (type_SCA_SpaceMonAction_SCA_SpaceMonAction)GetProcAddress(hLibspp, "??0SCA_SpaceMonAction@@QEAA@XZ");
	SCA_ListItem_SCA_SpaceMonAction_vftable = (PVOID)((char*)hLibspp + 0x2748F8); //(1802748F8) //0x262E78 (0x180262E78)

	SCA_InitSystem(0);

	return 0;
}
