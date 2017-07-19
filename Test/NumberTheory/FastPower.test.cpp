#define FAST_POWER_TEST
#define CATCH_CONFIG_MAIN

#include "../catch.hpp"
#include "../../NumberTheory/FastPower.cpp"


TEST_CASE("Base cases", "[fast_power]") {
    //REQUIRE(fast_power(0,0) == undefined);
    REQUIRE(fast_power(0,1,ULLONG_MAX) == 0);
    REQUIRE(fast_power(1,0,ULLONG_MAX) == 1);
    REQUIRE(fast_power(1,1,ULLONG_MAX) == 1);
}

TEST_CASE("Normal cases", "[fast_power]") {
    REQUIRE(fast_power(2,2,ULLONG_MAX) == 4);
    REQUIRE(fast_power(2,4,ULLONG_MAX) == 16);
    REQUIRE(fast_power(3,4,ULLONG_MAX) == 81);
    REQUIRE(fast_power(7,9,ULLONG_MAX) == 40353607);
    REQUIRE(fast_power(15,10,ULLONG_MAX) == 576650390625);
}

TEST_CASE("Overflow cases", "[fast_power]") {
    REQUIRE(fast_power(2,100,1000000007) == 976371285);
    REQUIRE(fast_power(10,99,1000000007) == 22673271);
}

#undef FAST_POWER_TEST
