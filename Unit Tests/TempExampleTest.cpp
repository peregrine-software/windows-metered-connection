#include "catch.hpp"
#include "TempExample.h"

SCENARIO("TempExample (placeholder for catch unit tests)") {
    GIVEN("A TempExample instance") {
        TempExample example{};
        WHEN("I Double some numbers") {
            REQUIRE(example.Double(0) == 0);
            REQUIRE(example.Double(1) == 2);
        }
    }
}
