#include "stdafx.h"
#include "Platform.h"

#include "Win32.h"
#include <atlbase.h>
#include <Shlobj.h>

namespace MeteredConnection
{
    Platform::Platform()
    {
    }


    Platform::~Platform()
    {
    }

    wstring Platform::GetProgramDataPath()
    {
        CComHeapPtr<WCHAR> pProgramDataPath;
        Win32::SHGetKnownFolderPath(FOLDERID_ProgramData, 0, NULL, &pProgramDataPath);
        wstring programDataPath{ pProgramDataPath };
        return programDataPath;
    }

}
