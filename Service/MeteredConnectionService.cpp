#include "stdafx.h"
#include "MeteredConnectionService.h"

#include "Logging.h"

namespace MeteredConnection
{
    MeteredConnectionService::MeteredConnectionService(SERVICE_STATUS_HANDLE serviceStatusHandle)
        :_serviceStatusHandle(serviceStatusHandle)
    {
        Logging::Initialize();
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
            M_LOGD << "Metered Connection - HandlerEx - Other control";
            ReportStatus();
        }
        return NO_ERROR;
    }

    SERVICE_STATUS MeteredConnectionService::GetInitialServiceStatus()
    {
        SERVICE_STATUS serviceStatus = {};
        serviceStatus.dwCurrentState = SERVICE_START_PENDING;
        serviceStatus.dwServiceType = SERVICE_WIN32_OWN_PROCESS;
        serviceStatus.dwControlsAccepted = constants::AcceptedControls;
        serviceStatus.dwWin32ExitCode = NO_ERROR;
        serviceStatus.dwCheckPoint = 0;
        serviceStatus.dwWaitHint = 0;
        return serviceStatus;
    }

    void MeteredConnectionService::Start() {
        M_LOGD << "MeteredConnectionService - Start";
        _serviceStatus.dwCurrentState = SERVICE_RUNNING;
        ReportStatus();
    }

    void MeteredConnectionService::Stop() {
        M_LOGD << "MeteredConnectionService - Stop";
        _serviceStatus.dwCurrentState = SERVICE_STOPPED;
        ReportStatus();
    }

    void MeteredConnectionService::ReportStatus()
    {
        SetServiceStatus(_serviceStatusHandle, &_serviceStatus);
    }

}