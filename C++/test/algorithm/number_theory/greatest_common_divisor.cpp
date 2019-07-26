#include "third_party/catch.hpp"
#include "algorithm/number_theory/greatest_common_divisor.hpp"

TEST_CASE("Base cases", "[number_theory][greatest_common_divisor]") {
    REQUIRE(greatest_common_divisor(0, 1) == 1);
    REQUIRE(greatest_common_divisor(1, 0) == 1);
    REQUIRE(greatest_common_divisor(0, 3) == 3);
    REQUIRE(greatest_common_divisor(3, 0) == 3);
}

TEST_CASE("Prime cases", "[number_theory][greatest_common_divisor]") {
    REQUIRE(greatest_common_divisor(2, 17) == 1);
    REQUIRE(greatest_common_divisor(6, 53) == 1);
    REQUIRE(greatest_common_divisor(11, 4) == 1);
    REQUIRE(greatest_common_divisor(107, 18) == 1);
}

TEST_CASE("Positive cases", "[number_theory][greatest_common_divisor]") {
    REQUIRE(greatest_common_divisor(2, 5) == 1);
    REQUIRE(greatest_common_divisor(3, 6) == 3);
    REQUIRE(greatest_common_divisor(14, 21) == 7);
    REQUIRE(greatest_common_divisor(122, 256) == 2);
    REQUIRE(greatest_common_divisor(1448, 20932) == 4);
}

TEST_CASE("Negative cases", "[number_theory][greatest_common_divisor]") {
    REQUIRE(greatest_common_divisor(-2, 6) == 2);
    REQUIRE(greatest_common_divisor(-30, -69) == 3);
    REQUIRE(greatest_common_divisor(36, -144) == 36);
}
