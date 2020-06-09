#include "third_party/catch.hpp"
#include "algorithm/number_theory/primorial.hpp"

TEST_CASE("Base cases", "[primorial]") {
    REQUIRE(primorial_Pn(2) == 2);
}

TEST_CASE("Normal cases", "[primorial]") {
    REQUIRE(primorial_Pn(3) == 6);
    REQUIRE(primorial_Pn(5) == 30);
    REQUIRE(primorial_Pn(7) == 210);
    REQUIRE(primorial_Pn(11) == 2310);
    REQUIRE(primorial_Pn(13) == 30030);
    REQUIRE(primorial_Pn(MAX_P_N) == 614889782588491410); // MAX_P_N = 47
}

TEST_CASE("Negative cases", "[primorial]") {
    REQUIRE(primorial_Pn(0) == 0);
    REQUIRE(primorial_Pn(1) == 0);
    REQUIRE(primorial_Pn(4) == 0);
    REQUIRE(primorial_Pn(8) == 0);
    REQUIRE(primorial_Pn(9) == 0);
    REQUIRE(primorial_Pn(12) == 0);
    REQUIRE(primorial_Pn(46) == 0);
    REQUIRE(primorial_Pn(UINT_MAX) == 0);
}

TEST_CASE("Wraparound cases", "[primorial]") {
    REQUIRE(primorial_Pn(53) == 0);
    REQUIRE(primorial_Pn(173) == 0);
}
