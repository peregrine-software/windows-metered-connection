#pragma once
#include <string>

using std::wstring;

namespace MeteredConnection
{
    class Platform
    {
    public:
        Platform();
        ~Platform();

        static wstring GetProgramDataPath();
    };
}

