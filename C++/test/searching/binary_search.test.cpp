#define BINARY_SEARCH_TEST

#include "third_party/catch.hpp"
#include "source/searching/binary_search.cpp"

TEST_CASE("Base cases", "[binary search]") {
    REQUIRE(binarySearch(1, vector<int>({1}), 0, 1) == 0);
    REQUIRE(binarySearch(5, vector<int>({0}), 0, 1) == -1);
}

TEST_CASE("Integer cases", "[binary search]") {
    REQUIRE(binarySearch(33, vector<int>({-5, 2, 7, 25, 33, 77, 88, 102}), 0, 7) == 4);
    REQUIRE(binarySearch(-99, vector<int>({-99, -88, -53, -3, -1}), 0, 4) == 0);
    REQUIRE(binarySearch(25, vector<int>({1, 6, 8, 13, 17, 21, 25}), 0, 6) == 6);
    REQUIRE(binarySearch(4, vector<int>({0, 5, 9, 44, 67}),0 ,4) == -1);
}

#undef BINARY_SEARCH_TEST

