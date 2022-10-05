#include "third_party/catch.hpp"
#include "algorithm/number_theory/euler_totient.hpp"

TEST_CASE("Base cases", "[euler_totient]") {
    REQUIRE(euler_totient(0) == 0);
    REQUIRE(euler_totient(1) == 1);
}

TEST_CASE("Normal cases", "[euler_totient]") {
    REQUIRE(euler_totient(2) == 1);
    REQUIRE(euler_totient(7) == 6);
    REQUIRE(euler_totient(16) == 8);
    REQUIRE(euler_totient(27) == 18);
    REQUIRE(euler_totient(50) == 20);
    REQUIRE(euler_totient(100) == 40);
    REQUIRE(euler_totient(9999) == 6000);
    REQUIRE(euler_totient(123456) == 41088);
}

TEST_CASE("Negative cases", "[euler_totient]") {
    REQUIRE(euler_totient(-1) == -1);
    REQUIRE(euler_totient(-10) == -1);
}