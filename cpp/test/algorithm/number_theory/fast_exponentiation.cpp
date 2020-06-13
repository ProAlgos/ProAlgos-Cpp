#include "third_party/catch.hpp"
#include "algorithm/number_theory/fast_exponentiation.hpp"

TEST_CASE("Base cases", "[fast_exp]") {
    // fast_exp(0, 0) is undefined
    REQUIRE(fast_exp(0, 1) == 0);
    REQUIRE(fast_exp(1, 0) == 1);
    REQUIRE(fast_exp(1, 1) == 1);
}

TEST_CASE("Normal cases", "[fast_exp]") {
    REQUIRE(fast_exp(2, 2) == 4);
    REQUIRE(fast_exp(2, 4) == 16);
    REQUIRE(fast_exp(3, 4) == 81);
    REQUIRE(fast_exp(6, 7) == 279936);
    REQUIRE(fast_exp(7, 9) == 40353607);
    REQUIRE(fast_exp(27, 8) == 282429536481);
    REQUIRE(fast_exp(15, 10) == 576650390625);
    REQUIRE(fast_exp(1543, 5) == 8746405945515943U);

}

TEST_CASE("Automatic modulo cases", "[fast_exp]") {
    REQUIRE(fast_exp(10, 99) == 22673271);
    REQUIRE(fast_exp(2, 100) == 976371285);
    REQUIRE(fast_exp(256, 128) == 812734592);
    REQUIRE(fast_exp(1366, 768) == 85977610);
}
