#include "third_party/catch.hpp"
#include "algorithm/dynamic_programming/weighted_activity_selection.hpp"

TEST_CASE("Base cases", "[weighted_activity]") {
    REQUIRE(weighted_activity( { 1 }, { 2 }, { 3 } ) == 3);
    REQUIRE(weighted_activity( { 1, 3 }, { 3, 5 }, { 1, 2 } ) == 3);
}

TEST_CASE("Medium cases", "[weighted_activity]") {
    REQUIRE(weighted_activity( { 1, 3, 6, 2}, 
                               { 2, 5, 19, 100 }, 
                               { 50, 20, 100, 200 } ) == 250);
    REQUIRE(weighted_activity( { 5, 3, 10, 8, 3, 8, 8, 8, 10, 10 }, 
                               { 6, 5, 11, 9, 9, 9,10, 9, 11, 11 }, 
                               { 10, 4, 10, 5, 8, 5, 4, 3, 2, 1  } ) == 29);
}
