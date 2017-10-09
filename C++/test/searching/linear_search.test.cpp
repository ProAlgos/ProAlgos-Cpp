#define LINEAR_SEARCH_TEST
#define CATCH_CONFIG_MAIN

#include "third_party/catch.hpp"
#include "source/searching/linear_search.cpp"

TEST_CASE("Base cases", "[linear search]") {
    REQUIRE(linear_search(1, vector<int>({1})) == 1);
    REQUIRE(linear_search(5, vector<int>({0})) == 0);
}

TEST_CASE("Integer cases", "[linear search]") {
    REQUIRE(linear_search(5, vector<int>({0, -5, 25, 8, 5, 2, 6, 3})) == 5);
    REQUIRE(linear_search(-15, vector<int>({9, -15, 0, 3, 5})) == 2);
    REQUIRE(linear_search(0, vector<int>({1, 29, 6, 8, 5, 2, 0})) == 7);
    REQUIRE(linear_search(-0, vector<int>({0, -5, 25, 8, 5, 2, 6, 3})) == 1);
    REQUIRE(linear_search(0, vector<int>({1, 29, 6, 8, 5, 2})) == 0);
}


TEST_CASE("Mixed cases", "[linear search]") {
    REQUIRE(linear_search('a', vector<char>({'1', 'f', 'A', 'X', 'a'})) == 5);
    REQUIRE(linear_search('/', vector<char>({'1', '/', '*', '-', '0'})) == 2);
    REQUIRE(linear_search(1.25, vector<float>({0.0, 6.15, 0.3, 1.25, 4})) == 4);
}
#undef LINEAR_SEARCH_TEST