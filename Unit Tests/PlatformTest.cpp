#include "catch.hpp"
#include "Platform.h"

#include "Logging.h"

SCENARIO("Static helpers") {
    GIVEN("Invariant helpers") {
        WHEN("I get the ProgramData path") {
            // TODO mock Win32 and inject expected path result, since the following won't always be true
            REQUIRE(MeteredConnection::Platform::GetProgramDataPath() == LR"(C:\ProgramData)");
        }
    }
}
