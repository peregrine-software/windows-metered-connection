#pragma once

#include <windows.h>

namespace MeteredConnection
{
    class Win32
    {
    public:
        Win32();
        ~Win32();

        static HRESULT SHGetKnownFolderPath(const GUID& rfid, DWORD dwFlags, HANDLE hToken, PWSTR *ppszPath);
    };
}

