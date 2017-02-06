#include "stdafx.h"
#include "Logging.h"

#include <iostream>
#include "Util.h"

using std::wstring;

namespace MeteredConnection
{

    Logging::Logging()
    {
    }


    Logging::~Logging()
    {
    }

    void Logging::Initialize()
    {
        const auto logFilePath = Util::GetDataFolderPath() + L"Metered Connection.log";
        const size_t maxFileBytes = 1000_KB;
        const int maxFileCount = 3;
        plog::init(plog::Severity::debug, logFilePath.c_str(), maxFileBytes, maxFileCount);
    }

}