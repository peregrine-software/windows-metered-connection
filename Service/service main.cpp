// Metered Connection Scheduler.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MeteredConnectionService.h"


const TCHAR* serviceName = _T("Metered Connection Scheduler");


DWORD WINAPI ServiceControlHandlerEx(DWORD control, DWORD eventType, void *eventData, void *context);
void WINAPI ServiceMain(DWORD argc, LPTSTR *argv);

std::unique_ptr<MeteredConnection::MeteredConnectionService> g_pMeteredConnectionService;


int __cdecl _tmain(int argc, TCHAR *argv[])
{
    const int serviceCount = 1;
    const int entryCountIncludingNullTerminator = serviceCount + 1;
    TCHAR* nameIgnoredDueToOwnProcessServiceType = _T("");

    SERVICE_TABLE_ENTRY serviceTable[entryCountIncludingNullTerminator] = {};
    serviceTable[0].lpServiceName = nameIgnoredDueToOwnProcessServiceType;
    serviceTable[0].lpServiceProc = ServiceMain;

    ::OutputDebugString(L"Metered Connection - StartServiceCtrlDispatcher");

    const BOOL started = StartServiceCtrlDispatcher(&serviceTable[0]);
    ::OutputDebugString(L"Metered Connection - Service all done");
    if (started == FALSE)
    {
        DWORD e = GetLastError();
        // TODO Log error
        ::OutputDebugString(L"Metered Connection - but there was an error");
        return e;
    }
    else
    {
        return NO_ERROR;
    }
}

void WINAPI ServiceMain(DWORD argc, LPTSTR *argv) {
    SERVICE_STATUS_HANDLE statusHandle = RegisterServiceCtrlHandlerEx(serviceName, &ServiceControlHandlerEx, NULL);
    if (statusHandle != 0)
    {
        g_pMeteredConnectionService = std::make_unique<MeteredConnection::MeteredConnectionService>(statusHandle);
    }
}

DWORD WINAPI ServiceControlHandlerEx(DWORD control, DWORD eventType, void *eventData, void *context)
{
    if (!g_pMeteredConnectionService)
    {
        ::OutputDebugString(L"Metered Connection - Error null ptr");
        return NO_ERROR; // Should never happen, but if MeteredConnectionService is already cleaned up then oh well
    }

    ::OutputDebugString(L"Metered Connection - HandlerEx");

    auto result = g_pMeteredConnectionService->HandlerEx(control, eventType, eventData, context);

    bool myWorkHereIsDone = (control == SERVICE_CONTROL_SHUTDOWN || control == SERVICE_CONTROL_STOP);
    if (myWorkHereIsDone)
    {
        g_pMeteredConnectionService.reset();
    }

    return result;
}
