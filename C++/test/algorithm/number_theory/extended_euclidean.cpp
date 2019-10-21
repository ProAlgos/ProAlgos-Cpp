#include "third_party/catch.hpp"
#include "algorithm/number_theory/extended_euclidean.hpp"

TEST_CASE("Base cases", "[number_theory][extended_euclidean]") {
    std::array<int, 2> a {{1, 0}};
    REQUIRE(extended_euclidean(0, 0) == a);
    std::array<int, 2> b {{1, 0}};
    REQUIRE(extended_euclidean(1, 0) == b);
    std::array<int, 2> c {{0, 1}};
    REQUIRE(extended_euclidean(0, 1) == c);
    std::array<int, 2> d {{0, 1}};
    REQUIRE(extended_euclidean(1, 1) == d);
}

TEST_CASE("Positive cases", "[number_theory][extended_euclidean]") {
    std::array<int, 2> a {{1, -1}};
    REQUIRE(extended_euclidean(180, 150) == a);
    std::array<int, 2> b {{-28, 3}};
    REQUIRE(extended_euclidean(16, 150) == b);
    std::array<int, 2> c {{11, -6}};
    REQUIRE(extended_euclidean(17, 31) == c);
    std::array<int, 2> d {{-91, 27}};
    REQUIRE(extended_euclidean(170, 573) == d);
}

TEST_CASE("Negative cases", "[number_theory][extended_euclidean]") {
    std::array<int, 2> a {{15, 1}};
    REQUIRE(extended_euclidean(-3, 44) == a);
    std::array<int, 2> b {{71, 5}};
    REQUIRE(extended_euclidean(14, -199) == b);
    std::array<int, 2> c {{-7, 17}};
    REQUIRE(extended_euclidean(-441, -182) == c);
}
