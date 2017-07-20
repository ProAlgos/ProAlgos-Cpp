#define FAST_POWER_TEST
#define CATCH_CONFIG_MAIN

#include "../catch.hpp"
#include "../../NumberTheory/FastPower.cpp"


TEST_CASE("Base cases", "[fast_power]") {
    //REQUIRE(fast_power(0,0) == undefined);
    REQUIRE(fast_power(0,1) == 0);
    REQUIRE(fast_power(1,0) == 1);
    REQUIRE(fast_power(1,1) == 1);
}

TEST_CASE("Normal cases", "[fast_power]") {
    REQUIRE(fast_power(2,2) == 4);
    REQUIRE(fast_power(2,4) == 16);
    REQUIRE(fast_power(3,4) == 81);
    REQUIRE(fast_power(7,9) == 40353607);
    REQUIRE(fast_power(15,10) == 576650390625);
}

TEST_CASE("Overflow cases", "[fast_power]") {
    REQUIRE(fast_power(2,100,1000000007) == 976371285);
    REQUIRE(fast_power(10,99,1000000007) == 22673271);
}

#undef FAST_POWER_TEST
