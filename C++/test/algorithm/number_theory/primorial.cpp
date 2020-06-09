#include "third_party/catch.hpp"
#include "algorithm/number_theory/primorial.hpp"

TEST_CASE("Base cases", "[primorial]") {
    REQUIRE(primorial_Pn(2) == 2);
    REQUIRE(primorial_n(1) == 2);
}

TEST_CASE("Normal cases", "[primorial]") {
    REQUIRE(primorial_Pn(3) == 6);
    REQUIRE(primorial_Pn(5) == 30);
    REQUIRE(primorial_Pn(7) == 210);
    REQUIRE(primorial_Pn(11) == 2310);
    REQUIRE(primorial_Pn(13) == 30030);
    REQUIRE(primorial_Pn(MAX_P_N) == 614889782588491410); // MAX_P_N = 47
    REQUIRE(primorial_n(2) == 6);
    REQUIRE(primorial_n(3) == 30);
    REQUIRE(primorial_n(4) == 210);
    REQUIRE(primorial_n(5) == 2310);
    REQUIRE(primorial_n(6) == 30030);
    REQUIRE(primorial_n(MAX_N) == 614889782588491410); // MAX_N = 15
}

TEST_CASE("Negative cases", "[primorial]") {
    REQUIRE(primorial_Pn(0) == 0);
    REQUIRE(primorial_Pn(1) == 0);
    REQUIRE(primorial_Pn(4) == 0);
    REQUIRE(primorial_Pn(8) == 0);
    REQUIRE(primorial_Pn(9) == 0);
    REQUIRE(primorial_Pn(12) == 0);
    REQUIRE(primorial_Pn(46) == 0);
    REQUIRE(primorial_n(0) == 0);
}

TEST_CASE("Wraparound cases", "[primorial]") {
    REQUIRE(primorial_Pn(MAX_P_N + 1) == 0);
    REQUIRE(primorial_Pn(53) == 0);
    REQUIRE(primorial_Pn(173) == 0);
    REQUIRE(primorial_Pn(UINT_MAX) == 0);
    REQUIRE(primorial_n(MAX_N + 1) == 0);
    REQUIRE(primorial_n(40) == 0);
}
