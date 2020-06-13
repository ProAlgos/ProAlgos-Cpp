#include "third_party/catch.hpp"
#include "algorithm/number_theory/primorial.hpp"

TEST_CASE("Base cases", "[primorial]") {
    // primorial
    REQUIRE(primorial(0) == 1);
    REQUIRE(primorial(1) == 2);
    REQUIRE(primorial(2) == 6);

    // primorial_natural
    REQUIRE(primorial_natural(0) == 1);
    REQUIRE(primorial_natural(1) == 1);
    REQUIRE(primorial_natural(2) == 2);
}

TEST_CASE("Edge cases", "[primorial]") {
    // primorial
    // MAX_N = 15
    REQUIRE(primorial(MAX_N) == 614889782588491410);
    REQUIRE(primorial(MAX_N + 1) == 0);
    REQUIRE(primorial(UINT_MAX) == 0);

    // primorial_natural
    // MAX_N_NATURAL = 52
    REQUIRE(primorial_natural(MAX_N_NATURAL) == 614889782588491410);
    REQUIRE(primorial_natural(MAX_N_NATURAL + 1) == 0);
    REQUIRE(primorial_natural(UINT_MAX) == 0);
}

TEST_CASE("Normal cases", "[primorial]") {
    // primorial
    REQUIRE(primorial(4) == 210);
    REQUIRE(primorial(11) == 200560490130);
    REQUIRE(primorial(14) == 13082761331670030);

    // primorial_natural
    REQUIRE(primorial_natural(9) == 210);
    REQUIRE(primorial_natural(19) == 9699690);
    REQUIRE(primorial_natural(46) == 13082761331670030);
}
