#include "stdafx.h"
#include "MeteredConnectionService.h"


MeteredConnectionService::MeteredConnectionService(SERVICE_STATUS_HANDLE serviceStatusHandle)
    :_serviceStatusHandle(serviceStatusHandle)
{
    _serviceStatus = GetInitialServiceStatus();
    Start();
}


MeteredConnectionService::~MeteredConnectionService()
{
}

DWORD WINAPI MeteredConnectionService::HandlerEx(DWORD control, DWORD eventType, void *eventData, void *context)
{
    switch (control)
    {
    case SERVICE_CONTROL_SHUTDOWN:
        Stop();
        break;
    case SERVICE_CONTROL_STOP:
        Stop();
        break;
    default:
        ::OutputDebugString(L"Metered Connection - HandlerEx - Other control");
        ReportStatus();
    }
    return NO_ERROR;
}

SERVICE_STATUS MeteredConnectionService::GetInitialServiceStatus()
{
    SERVICE_STATUS serviceStatus = {};
    serviceStatus.dwCurrentState = SERVICE_START_PENDING;
    serviceStatus.dwServiceType = SERVICE_WIN32_OWN_PROCESS;
    serviceStatus.dwControlsAccepted = constants::AcceptedControls; // OK to accept because init is fast
    serviceStatus.dwWin32ExitCode = NO_ERROR;
    serviceStatus.dwCheckPoint = 0;
    serviceStatus.dwWaitHint = 0;
    return serviceStatus;
}

void MeteredConnectionService::Start() {
     ::OutputDebugString(L"Metered Connection - Start");
    _serviceStatus.dwCurrentState = SERVICE_RUNNING;
    ReportStatus();
}

void MeteredConnectionService::Stop() {
    ::OutputDebugString(L"Metered Connection - Stop");
    _serviceStatus.dwCurrentState = SERVICE_STOPPED;
    ReportStatus();
}

void MeteredConnectionService::ReportStatus()
{
    SetServiceStatus(_serviceStatusHandle, &_serviceStatus);
}
