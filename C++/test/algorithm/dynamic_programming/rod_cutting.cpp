#include "third_party/catch.hpp"
#include "algorithm/dynamic_programming/rod_cutting.hpp"

TEST_CASE("Base cases", "[rod_cutting]") {
    REQUIRE(rod_cutting( { 20 } ) == 20);
    REQUIRE(rod_cutting( { 2, 3 } ) == 4);
    REQUIRE(rod_cutting( { 1, 2, 3, 4, 10 } ) == 10);
}

TEST_CASE("Simple cases", "[rod_cutting]") {
    REQUIRE(rod_cutting( { 1, 5, 8, 9, 10, 17, 17, 20 } ) == 22);
    REQUIRE(rod_cutting( { 3, 5, 8, 9, 10, 17, 17, 20 } ) == 24);
}

TEST_CASE("Large cases", "[rod_cutting]") {
    REQUIRE(rod_cutting( { 72, 92, 88, 7, 27, 37, 6, 6, 9, 43, 4, 45, 58, 43, 44, 69, 69, 
        5, 51, 49, 71, 26, 26, 34, 91, 61, 95, 68, 60, 62, 17, 90, 63, 5, 13, 52, 51, 56, 
        92, 18, 53, 59, 18, 75, 44, 52, 71, 3, 50, 2 } ) == 3600);
    REQUIRE(rod_cutting( { 1, 45, 59, 94, 24, 42, 71, 20, 46, 55, 6, 81, 95, 79, 21, 73, 
        7, 63, 2, 87, 36, 38, 4, 4, 6, 81, 97, 53, 97, 68, 88, 78, 24, 7, 4, 22, 73, 88, 
        71, 3, 34, 44, 31, 79, 54, 82, 55, 7, 56, 50 } ) == 1173);
    REQUIRE(rod_cutting( { 97, 76, 69, 52, 13, 67, 22, 30, 44, 29, 7, 35, 2, 15, 13, 59, 
        86, 95, 47, 44, 66, 58, 45, 93, 49, 94, 100, 74, 9, 72, 59, 19, 46, 64, 98, 25, 
        25, 87, 66, 6, 53, 92, 4, 18, 93, 35, 62, 32, 68, 19 } ) == 4850);
}
