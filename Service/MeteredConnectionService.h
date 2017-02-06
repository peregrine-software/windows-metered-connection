#pragma once

namespace MeteredConnection
{
    class MeteredConnectionService
    {
    public:
        MeteredConnectionService(SERVICE_STATUS_HANDLE serviceStatusHandle);
        ~MeteredConnectionService();

        DWORD WINAPI HandlerEx(DWORD control, DWORD eventType, void *eventData, void *context);

    private:
        struct constants
        {
            static constexpr DWORD AcceptedControls{
                SERVICE_ACCEPT_STOP
                | SERVICE_ACCEPT_SHUTDOWN
                //| SERVICE_ACCEPT_TIMECHANGE
            };
        };

        SERVICE_STATUS_HANDLE _serviceStatusHandle = 0;
        SERVICE_STATUS _serviceStatus = {};

        SERVICE_STATUS GetInitialServiceStatus();
        void Start();
        void Stop();
        void ReportStatus();


    };

}
