#include "third_party/catch.hpp"
#include "algorithm/dynamic_programming/weighted_activity_selection.hpp"

TEST_CASE("Base cases", "[weighted_activity]") {
    REQUIRE(weighted_activity( { 1 }, { 2 }, { 3 } ) == 3);
    REQUIRE(weighted_activity( { 1 }, { 1 }, { 4 } ) == 4);
    REQUIRE(weighted_activity( { 1, 3 }, { 3, 5 }, { 1, 2 } ) == 3);
    REQUIRE(weighted_activity( { 1, 3 }, { 4, 5 }, { 4, 5 } ) == 5);
    REQUIRE(weighted_activity( { 1, 3 }, { 4, 5 }, { 5, 4 } ) == 5);
}

TEST_CASE("Medium cases", "[weighted_activity]") {
    REQUIRE(weighted_activity( { 1, 3, 6, 2}, 
                               { 2, 5, 19, 100 }, 
                               { 50, 20, 100, 200 } ) == 250);
    REQUIRE(weighted_activity( { 5, 3, 10, 8, 3, 8, 8, 8, 10, 10 }, 
                               { 6, 5, 11, 9, 9, 9,10, 9, 11, 11 }, 
                               { 10, 4, 10, 5, 8, 5, 4, 3, 2, 1  } ) == 29);
    REQUIRE(weighted_activity( { 70, 92, 100, 53, 72, 42, 6 }, 
                               { 212, 202, 252, 151, 351, 241, 277 }, 
                               { 177, 122, 313, 17, 396, 197, 403 } ) == 403);
    REQUIRE(weighted_activity( { 186, 33, 109, 99, 133, 96, 188, 40, 60, 42, 199, 194 }, 
                               { 307, 128, 297, 395, 384, 186, 264, 151, 264, 288, 389, 338 }, 
                               { 378, 70, 470, 16, 463, 24, 341, 444, 367, 366, 227, 195 } ) == 822);
}
