#pragma once

// Header doesn't conform to everything in Microsoft static code analysis. Ignore.
#pragma warning(push)
#pragma warning(disable : 26491 26481 26485)
#include "plog/Log.h"
#pragma warning(pop)

// We also need to suppress a warning in the log macros
#define M_LOGD __pragma(warning(suppress : 26493))  LOGD


namespace MeteredConnection
{
    class Logging
    {
    public:
        Logging();
        ~Logging();

        enum class Type
        {
            Debug,
            File
        };

        static void Initialize();
    };

}