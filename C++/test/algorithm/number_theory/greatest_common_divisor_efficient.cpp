#include "third_party/catch.hpp"
#include "algorithm/number_theory/greatest_common_divisor_efficient.hpp"

TEST_CASE("Base cases", "[number_theory][greatest_common_divisor_efficient]") {
    REQUIRE(greatest_common_divisor_efficient(0, 1) == 1);
    REQUIRE(greatest_common_divisor_efficient(1, 0) == 1);
    REQUIRE(greatest_common_divisor_efficient(0, 3) == 3);
    REQUIRE(greatest_common_divisor_efficient(3, 0) == 3);
}

TEST_CASE("Prime cases", "[number_theory][greatest_common_divisor_efficient]") {
    REQUIRE(greatest_common_divisor_efficient(2, 17) == 1);
    REQUIRE(greatest_common_divisor_efficient(6, 53) == 1);
    REQUIRE(greatest_common_divisor_efficient(11, 4) == 1);
    REQUIRE(greatest_common_divisor_efficient(107, 18) == 1);
}

TEST_CASE("Positive cases", "[number_theory][greatest_common_divisor_efficient]") {
    REQUIRE(greatest_common_divisor_efficient(2, 5) == 1);
    REQUIRE(greatest_common_divisor_efficient(3, 6) == 3);
    REQUIRE(greatest_common_divisor_efficient(14, 21) == 7);
    REQUIRE(greatest_common_divisor_efficient(122, 256) == 2);
    REQUIRE(greatest_common_divisor_efficient(1448, 20932) == 4);
}

TEST_CASE("Negative cases", "[number_theory][greatest_common_divisor_efficient]") {
    REQUIRE(greatest_common_divisor_efficient(-2, 6) == 2);
    REQUIRE(greatest_common_divisor_efficient(-30, -69) == 3);
    REQUIRE(greatest_common_divisor_efficient(36, -144) == 36);
}
