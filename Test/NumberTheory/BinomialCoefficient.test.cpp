#define CATCH_CONFIG_MAIN
#define TEST

#include "../catch.hpp"
#include "../../NumberTheory/BinomialCoefficient.cpp"

TEST_CASE("Base cases", "[BinomialCoefficient]") {
    REQUIRE(BinomialCoefficient(0, 0) == 1);
    REQUIRE(BinomialCoefficient(1, 1) == 1);
    REQUIRE(BinomialCoefficient(1, 0) == 1);
    REQUIRE(BinomialCoefficient(0, 1) == 0);
    REQUIRE(BinomialCoefficient(729, 0) == 1);
    REQUIRE(BinomialCoefficient(729, 729) == 1);
    REQUIRE(BinomialCoefficient(0, 729) == 0);
    REQUIRE(BinomialCoefficient(729, 1234567) == 0);


}

TEST_CASE("Normal cases", "[BinomialCoefficient]") {
    REQUIRE(BinomialCoefficient(10,2) == 45);
    REQUIRE(BinomialCoefficient(40,20) == 137846528820L);
    REQUIRE(BinomialCoefficient(100,97) == 161700);
    REQUIRE(BinomialCoefficient(200,10) == 22451004309013280UL);
    REQUIRE(BinomialCoefficient(50,35) == 2250829575120L);

}

TEST_CASE("Overflow cases", "[BinomialCoefficient]") {
    REQUIRE(BinomialCoefficient(100,50) == 1184508333840160104UL);
    REQUIRE(BinomialCoefficient(128,70) == 14909021253410748352UL);

}

