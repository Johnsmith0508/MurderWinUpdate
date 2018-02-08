// MurderWinUpdate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <tchar.h>
#include <strsafe.h>
#include <aclapi.h>
#include <stdio.h>
#pragma comment(lib, "advapi32.lib")

LPCWSTR serviceName = L"wuauserv";
LPSERVICE_STATUS servStat = NULL;
SERVICE_STATUS_PROCESS ssp;
void __stdcall DoStopSvc()
{
    SC_HANDLE scMan =  OpenSCManager( NULL , NULL , SC_MANAGER_ALL_ACCESS );
    SC_HANDLE service = OpenService( scMan , L"wuauserv" , SC_MANAGER_ALL_ACCESS );
    BOOL svcCtrl = ControlService( service , SERVICE_CONTROL_STOP , (LPSERVICE_STATUS) &ssp);
    CloseServiceHandle( service );
    CloseServiceHandle( scMan );
}

int APIENTRY _tWinMain( HINSTANCE hInstance , HINSTANCE hPrevInstance , LPTSTR lpCmdLine , int nCmdShow )
{
    DoStopSvc();
    return 0;
}

