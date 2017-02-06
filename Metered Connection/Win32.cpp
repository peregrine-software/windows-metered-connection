#include "stdafx.h"
#include "Win32.h"

#include <Shlobj.h>

namespace MeteredConnection
{
    Win32::Win32()
    {
    }


    Win32::~Win32()
    {
    }

    HRESULT Win32::SHGetKnownFolderPath(const GUID& rfid, DWORD dwFlags, HANDLE hToken, PWSTR *ppszPath)
    {
        return ::SHGetKnownFolderPath(rfid, dwFlags, hToken, ppszPath);
    }

}
