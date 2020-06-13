#include "third_party/catch.hpp"
#include "algorithm/number_theory/binomial_coefficient.hpp"

TEST_CASE("Base cases", "[binomial_coefficient]") {
    REQUIRE(binomial_coefficient(0, 0) == 1);
    REQUIRE(binomial_coefficient(0, 1) == 0);
    REQUIRE(binomial_coefficient(1, 0) == 1);
    REQUIRE(binomial_coefficient(1, 1) == 1);

    REQUIRE(binomial_coefficient(0, 729) == 0);
    REQUIRE(binomial_coefficient(729, 0) == 1);
    REQUIRE(binomial_coefficient(729, 729) == 1);
    REQUIRE(binomial_coefficient(729, 1234567) == 0);
}

TEST_CASE("Normal cases", "[binomial_coefficient]") {
    REQUIRE(binomial_coefficient(10, 2) == 45);
    REQUIRE(binomial_coefficient(40, 20) == 137846528820L);
    REQUIRE(binomial_coefficient(50, 35) == 2250829575120L);
    REQUIRE(binomial_coefficient(100, 97) == 161700);
    REQUIRE(binomial_coefficient(200, 10) == 22451004309013280UL);
}

TEST_CASE("Overflow cases", "[binomial_coefficient]") {
    REQUIRE(binomial_coefficient(100, 50) == 1184508333840160104UL);
    REQUIRE(binomial_coefficient(128, 70) == 14909021253410748352UL);
}
