#include "third_party/catch.hpp"
#include "algorithm/number_theory/primorial.hpp"

TEST_CASE("Base cases", "[primorial]") {
    REQUIRE(primorial(2) == 2);
}

TEST_CASE("Normal cases", "[primorial]") {
    REQUIRE(primorial(3) == 6);
    REQUIRE(primorial(5) == 30);
    REQUIRE(primorial(7) == 210);
    REQUIRE(primorial(11) == 2310);
    REQUIRE(primorial(13) == 30030);
    REQUIRE(primorial(MAX_P_N) == 614889782588491410);
}

TEST_CASE("Negative cases", "[primorial]") {
    REQUIRE(primorial(0) == 0);
    REQUIRE(primorial(1) == 0);
    REQUIRE(primorial(4) == 0);
    REQUIRE(primorial(8) == 0);
    REQUIRE(primorial(9) == 0);
    REQUIRE(primorial(12) == 0);
    REQUIRE(primorial(46) == 0);
    REQUIRE(primorial(UINT_MAX) == 0);
}

TEST_CASE("Wraparound cases", "[primorial]") {
    REQUIRE(primorial(53) == 0);
    REQUIRE(primorial(173) == 0);
}
