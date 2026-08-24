#ifndef _SYNCBREEZE_STRUCT_H_
#define _SYNCBREEZE_STRUCT_H_

struct _LIBPAL_SCA_NetTransport {
	signed __int64 vftable;
	signed __int32 field_8;
	signed __int32 field_C;
	signed __int64 NetLink;
	signed __int32 field_18;
	char field_1C;
	char field_1D;
	char field_1E;
	char field_1F;
	signed __int64 field_20;
	signed __int64 field_28;
	signed __int64 field_30;
	signed __int64 field_38;
	signed __int64 field_40;
	signed __int64 field_48;
	signed __int64 field_50;
	signed __int64 field_58;
	signed __int64 field_60;
	signed __int64 field_68;
	signed __int64 field_70;
	signed __int64 field_78;
	signed __int64 field_80;
	signed __int64 field_88;
	signed __int64 field_90;
	signed __int64 field_98;
	signed __int64 field_A0;
	signed __int64 field_A8;
	signed __int64 field_B0;
	signed __int64 field_B8;
	signed __int64 field_C0;
	signed __int64 field_C8;
	signed __int64 field_D0;
	signed __int64 field_D8;
	signed __int64 field_E0;
	signed __int64 field_E8;
	signed __int64 field_F0;
	signed __int64 field_F8;
	signed __int64 field_100;
	signed __int64 field_108;
	signed __int64 field_110;
	signed __int64 field_118;
	char field_120;
	char field_121;
	char field_122;
	char field_123;
	signed __int32 field_124;
	signed __int64 field_128;
	signed __int64 field_130;
	signed __int64 field_138;
	signed __int64 field_140;
	signed __int64 field_148;
	signed __int64 field_150;
	signed __int64 field_158;
	signed __int32 field_160;
	signed __int32 field_164;
	signed __int64 field_168;
	signed __int64 field_170;
	signed __int64 field_178;
	signed __int64 field_180;
	signed __int32 field_188;
	signed __int32 field_18C;
	signed __int32 field_190;
	signed __int32 field_194;
	signed __int32 field_198;
	signed __int32 field_19C;
	signed __int64 field_1A0;
	signed __int64 field_1A8;
};

struct _LIBPAL_SCA_ConfigObj {
	signed __int64 vftable;
	signed __int32 field_8;
	signed __int32 field_C;
	struct _LIBPAL_SCA_ConfigObj* field_10;
	struct _LIBPAL_SCA_ConfigObj* Next;
	signed __int64 field_20;
	signed __int32 field_28;
	signed __int32 field_2C;
	char* ConfigName;
	signed __int32 ConfigNameLength;
	signed __int32 field_3C;
	signed __int64 field_40;
	signed __int32 field_48;
	signed __int32 field_4C;
	signed __int64 field_50;
	signed __int64 field_58;
	signed __int64 FieldsList;
	signed __int64 field_68;
	signed __int32 field_70;
	signed __int32 field_74;
};

struct _LIBPAL_SCA_NetMessage {
	signed __int64 vftable;
	signed __int32 field_8;
	signed __int32 field_C;
	signed __int32 Command;
	signed __int32 field_14;
	char MessageName[64];
	struct _LIBPAL_SCA_ConfigObj ConfigObj;
};

struct _LIBSYNC_SCA_SyncBreezeClient {
	signed __int64 vftable;
	signed __int32 field_8;
	signed __int32 field_C;
	signed __int32 field_10;
	signed __int32 field_14;
	struct _LIBPAL_SCA_NetTransport NetTransport;
	struct _LIBPAL_SCA_NetMessage field_1C8;
	struct _LIBPAL_SCA_NetMessage field_298;
	char field_368;
	char field_369;
	char field_36A;
	char field_36B;
	signed __int32 field_36C;
	signed __int64 field_370;
	signed __int64 field_378;
	signed __int64 field_380;
	char field_388;
	char field_389;
	char field_38A;
	char field_38B;
	signed __int32 field_38C;
	signed __int64 field_390;
	signed __int64 field_398;
	signed __int64 field_3A0;
	signed __int64 field_3A8;
	signed __int64 field_3B0;
	signed __int64 field_3B8;
	signed __int64 field_3C0;
	signed __int64 field_3C8;
	signed __int64 field_3D0;
	signed __int64 field_3D8;
	signed __int64 field_3E0;
	signed __int64 field_3E8;
	signed __int64 field_3F0;
	signed __int64 field_3F8;
	signed __int64 field_400;
	signed __int64 field_408;
	signed __int64 field_410;
	signed __int64 field_418;
	signed __int64 field_420;
	signed __int64 field_428;
	signed __int64 field_430;
	signed __int64 field_438;
	signed __int64 field_440;
	signed __int64 field_448;
	signed __int64 field_450;
	signed __int64 field_458;
	signed __int64 field_460;
	signed __int64 field_468;
	signed __int64 field_470;
	signed __int64 field_478;
	signed __int64 field_480;
	signed __int16 field_488;
	signed __int16 field_48A;
	signed __int16 field_48C;
	signed __int16 field_48E;
	signed __int32 field_490;
	signed __int32 field_494;
};

struct _LIBSPP_SCA_SpaceMonAction {
	signed __int64 vftable;
	signed __int32 field_8;
	signed __int32 field_C;
	signed __int32 ActionId;
	signed __int32 field_14;
	signed __int64 field_18;
	signed __int32 field_20;
	signed __int32 CondType;
	signed __int32 CondValue;
	signed __int32 CondUnits;
	signed __int32 RepStatus;
	char RepStatusString[260];
	signed __int32 SendEmail;
	signed __int32 EmailFormat;
	char EmailAddress[260];
	signed __int32 ExecuteCommand;
	signed __int32 CommandType;
	char CommandName[260];
	signed __int32 RepeatAction;
	signed __int32 RepeatTimeValue;
	signed __int32 RepeatTimeUnits;
	signed __int32 field_35C;
};

struct _LIBSPP_SCA_SpaceMonAction_ListItem {
	PVOID vftable;
	signed __int32 field_8;
	signed __int32 field_C;
	struct _LIBSPP_SCA_SpaceMonAction_ListItem* Next;
	struct _LIBSPP_SCA_SpaceMonAction_ListItem* Prev;
	signed __int32 ActionId;
	signed __int32 field_24;
	struct _LIBSPP_SCA_SpaceMonAction* SpaceMonAction;
	signed __int64 field_30;
};

struct _LIBSPP_SCA_SpaceMon {
	signed __int64 vftable;
	signed __int32 field_8;
	signed __int32 field_C;
	signed __int32 MonitorId;
	signed __int32 Enabled;
	char Path[260];
	signed __int32 Frequency;
	signed __int32 AutoDisable;
	signed __int32 MaxErrorCount;
	signed __int32 field_128;
	signed __int32 Status;
	signed __int32 RepStatus;
	char StatusString[260];
	signed __int64 UpdateTime;
	signed __int64 TotalSpace;
	signed __int64 FreeSpace;
	double FreeSpacePercent;
	signed __int32 ErrorCount;
	signed __int32 ReadOnly;
	signed __int64 SCA_List_SCA_SpaceMonAction_vftable;
	signed __int32 field_268;
	signed __int32 field_26C;
	struct _LIBSPP_SCA_SpaceMonAction_ListItem* FirstActionItem;
	struct _LIBSPP_SCA_SpaceMonAction_ListItem* LastActionItem;
	signed __int64 field_280;
	signed __int32 nActionItems;
	signed __int32 field_28C;
};

struct _LIBSYNC_SCA_SyncBreezeInterface {
	struct _LIBSYNC_SCA_SyncBreezeClient SyncBreezeClient;
};

typedef int (*type_SCA_InitSystem)(
	int Unused
);

typedef struct _LIBPAL_SCA_NetTransport* (*type_SCA_NetTransport_SCA_NetTransport)(
	struct _LIBPAL_SCA_NetTransport* NetTransport,								//pointer to struct
	PVOID NetLink																//put 0 here
);

//1 success, 0 fail
typedef int (*type_SCA_NetTransport_Connect)(
	struct _LIBPAL_SCA_NetTransport* NetTransport,
	char* addr,																	//hostname or ip of server
	unsigned short int port,													//port, usually 9121
	unsigned int timeout,														//put -1 here
	DWORD* error																//error code
);

//1 success, 0 fail
typedef int (*type_SCA_NetTransport_DeleteFileA)(
	struct _LIBPAL_SCA_NetTransport* NetTransport,
	char* FileName,																//path to file to be deleted
	DWORD* error
);

//1 success, 0 fail
typedef int (*type_SCA_NetTransport_UploadFile)(
	struct _LIBPAL_SCA_NetTransport* NetTransport,
	char* LocalFileName,														//file on your system to upload
	char* RemoteFileName,														//where to place file on server
	DWORD ControlFlags,															//put 0 here
	DWORD* error,
	PVOID ProgressObj															//put 0 here
);

typedef int (*type_SCA_NetTransport_DownloadFile)(
	struct _LIBPAL_SCA_NetTransport* NetTransport,
	char* RemoteFileName,
	char* LocalFileName,
	DWORD ControlFlags,
	DWORD* error,
	PVOID ProgressObj
);

//do not call it. for some reasons it is going to crash your app
typedef void (*type_SCA_NetTransport_Destroy)(
	struct _LIBPAL_SCA_NetTransport* NetTranspor
);

typedef struct _LIBSYNC_SCA_SyncBreezeInterface* (*type_SCA_SyncBreezeInterface_SCA_SyncBreezeInterface)(
	struct _LIBSYNC_SCA_SyncBreezeInterface* SyncBreezeInterface
);

typedef struct _LIBSYNC_SCA_SyncBreezeClient* (*type_SCA_SyncBreezeClient_SCA_SyncBreezeClient)(
	struct _LIBSYNC_SCA_SyncBreezeClient* SyncBreezeClient						//pointer to struct
);

typedef int (*type_SCA_SyncBreezeClient_Connect)(
	struct _LIBSYNC_SCA_SyncBreezeClient* SyncBreezeClient,
	char* addr,																	//hostname or ip of server
	unsigned short int port,													//port, usually 9121
	unsigned int timeout,														//put -1 here
	DWORD* error																//error code
);

typedef int (*type_SCA_SyncBreezeInterface_Login)(
	struct _LIBSYNC_SCA_SyncBreezeInterface* SyncBreezeInterface,
	char* UserName,
	char* Password,
	int* LoginStatus,															//out
	int* ClientUserId,															//out
	int* Permissions,															//out
	int* LicenseStatus,															//out
	char* LicenseStatusString,													//out
	int LicenseStatusStringLength												//size of previous argument buffer
);

typedef int (*type_SCA_SyncBreezeInterface_AddSpaceMonitor)(
	struct _LIBSYNC_SCA_SyncBreezeInterface* SyncBreezeInterface,
	struct _LIBSPP_SCA_SpaceMon* SpaceMon
);

typedef int (*type_SCA_SyncBreezeClient_LoginEx2)(
	struct _LIBSYNC_SCA_SyncBreezeClient* SyncBreezeClient,
	struct _LIBPAL_SCA_ConfigObj* LoginData,
	struct _LIBPAL_SCA_ConfigObj** LoginResults
);

typedef void (*type_SCA_SyncBreezeClient_Destroy)(
	struct _LIBSYNC_SCA_SyncBreezeClient* SyncBreezeClient
);

typedef struct _LIBSPP_SCA_SpaceMon* (*type_SCA_SpaceMon_SCA_SpaceMon)(
	struct _LIBSPP_SCA_SpaceMon* SpaceMon
);

typedef struct _LIBSPP_SCA_SpaceMonAction* (*type_SCA_SpaceMonAction_SCA_SpaceMonAction)(
	struct _LIBSPP_SCA_SpaceMonAction* SpaceMonAction
);

typedef int (*type_SCA_SyncBreezeClient_GetSpaceMonitorListObj)(
	struct _LIBSYNC_SCA_SyncBreezeClient* SyncBreezeClient,
	struct _LIBPAL_SCA_ConfigObj** MonitorListConfig,
	int AddRuntimeData
);

typedef int (*type_SCA_SyncBreezeClient_DeleteSpaceMonitor)(
	struct _LIBSYNC_SCA_SyncBreezeClient* SyncBreezeClient,
	int MonitorId
);

typedef int (*type_SCA_ConfigObj_Load)(
	struct _LIBPAL_SCA_ConfigObj* ConfigObj,
	char* ConfigFilePath,
	char* SCOMPSYS,
	DWORD* error
);

typedef struct _LIBPAL_SCA_ConfigObj* (*type_SCA_ConfigObj_SCA_ConfigObj)(
	struct _LIBPAL_SCA_ConfigObj* ConfigObj,
	struct _LIBPAL_SCA_ConfigObj* TemplateConfigObj
);

typedef int (*type_SCA_ConfigObj_Show)(
	struct _LIBPAL_SCA_ConfigObj* ConfigObj,
	int PrintConfigName
);

typedef int (*type_SCA_ConfigObj_GetField_cci)( //config, char, char, int
	struct _LIBPAL_SCA_ConfigObj* ConfigObj,
	char* FieldName,
	char* Value,
	int ValueLength
);

#endif
