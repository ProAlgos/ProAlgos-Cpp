#include "third_party/catch.hpp"
#include "algorithm/number_theory/perfect_number_check.hpp"

TEST_CASE("Normal cases"){
    REQUIRE(is_perfect(1) == true);
    REQUIRE(is_perfect(2) == false);
    REQUIRE(is_perfect(6) == true);
    REQUIRE(is_perfect(28) == true);
    REQUIRE(is_perfect(49) == false);
    REQUIRE(is_perfect(495) == false);
    REQUIRE(is_perfect(496) == true);
    REQUIRE(is_perfect(8128) == true);
}
