#pragma once
#include "Platform.h"

using std::wstring;

namespace MeteredConnection
{
    constexpr size_t operator""_KB(unsigned long long kilobytes) {
        return
            (kilobytes > (SIZE_MAX / 1024u))
            ? throw std::invalid_argument("Too many bytes for size_t")
            : static_cast<size_t>(1024u * kilobytes);
    }

    class Util
    {
    public:
        Util();
        ~Util();

        static wstring GetDataFolderPath()
        {
            auto programDataFolder = Platform::GetProgramDataPath();
            auto meteredConnectionFolder = programDataFolder + LR"(\Metered Connection\)";
            return meteredConnectionFolder;
        }
    };
}

