#define JUMP_SEARCH_TEST

#include "third_party/catch.hpp"
#include "source/searching/jump_search.cpp"

TEST_CASE("Base cases", "[jump search]") {
    REQUIRE(jumpSearch(vector<int>({1}), 1) == 0);
    REQUIRE(jumpSearch(vector<int>({0}), -5) == -1);
}

TEST_CASE("Integer cases", "[jump search]") {
    REQUIRE(jumpSearch(vector<int>({-5, 2, 7, 25, 33, 77, 88, 102}), 33) == 4);
    REQUIRE(jumpSearch(vector<int>({-99, -88, -53, -3, -1}), -99) == 0);
    REQUIRE(jumpSearch(vector<int>({1, 6, 8, 13, 17, 21, 25}), 25) == 6);
    REQUIRE(jumpSearch(vector<int>({0, 5, 9, 44, 67}), 4) == -1);
}

#undef JUMP_SEARCH_TEST

