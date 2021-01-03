#include "third_party/catch.hpp"
#include "algorithm/searching/jump_search.hpp"

using std::vector;
using std::string;

TEST_CASE("Base cases", "[searching][linear_search]") {
    REQUIRE(jump_search(0, vector<int>()) == -1);
    REQUIRE(jump_search(1, vector<int>({1})) == 0);
    REQUIRE(jump_search(5, vector<int>({0})) == -1);
}

TEST_CASE("Integer cases", "[searching][linear_search]") {
    REQUIRE(jump_search(5, vector<int>({0, 5, 25, 50, 60, 67, 80, 81})) == 1);
    REQUIRE(jump_search(-15, vector<int>({-45, -44, -33, -15, 0, 3, 5})) == 3);
    REQUIRE(jump_search(42, vector<int>({1, 2, 6, 8, 20, 22, 42})) == 6);
    REQUIRE(jump_search(-0, vector<int>({-12, -11, -5, -3, 0, 3, 6, 9})) == 4);
    REQUIRE(jump_search(0, vector<int>({1, 2, 3, 4, 5, 6})) == -1);
}