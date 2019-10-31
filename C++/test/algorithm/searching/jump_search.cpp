#include "third_party/catch.hpp"
#include "algorithm/searching/jump_search.hpp"

using std::vector;
using std::string;
using std::cmath;

TEST_CASE("Base cases", "[searching][jump_search]") {
    REQUIRE(jump_search(0, vector<int>()) == -1);
    REQUIRE(jump_search(1, vector<int>({1})) == 0);
    REQUIRE(jump_search(5, vector<int>({0})) == -1);
}

TEST_CASE("Integer cases", "[searching][jump_search]") {
    REQUIRE(jump_search(33, vector<int>({-5, 2, 7, 25, 33, 77, 88, 102})) == 4);
    REQUIRE(jump_search(-99, vector<int>({-99, -88, -53, -3, -1})) == 0);
    REQUIRE(jump_search(25, vector<int>({1, 6, 8, 13, 17, 21, 25})) == 6);
    REQUIRE(jump_search(4, vector<int>({0, 5, 9, 44, 67})) == -1);
}

TEST_CASE("Mixed cases", "[searching][jump_search]") {
    REQUIRE(jump_search('d', vector<char>({'a', 'b', 'c', 'd', 'e'})) == 3);
    REQUIRE(jump_search(string("2"), vector<string>({"1", "2", "3", "4", "5"})) == 1);
    REQUIRE(jump_search(2.8, vector<double>({0.1, 0.15, 0.3, 1.1, 2.3, 2.8, 3.14})) == 5);
}