#include "third_party/catch.hpp"
#include "algorithm/searching/linear_search.hpp"

using std::vector;
using std::string;

TEST_CASE("Base cases", "[searching][linear_search]") {
    REQUIRE(linear_search(0, vector<int>()) == -1);
    REQUIRE(linear_search(1, vector<int>({1})) == 0);
    REQUIRE(linear_search(5, vector<int>({0})) == -1);
}

TEST_CASE("Integer cases", "[searching][linear_search]") {
    REQUIRE(linear_search(5, vector<int>({0, -5, 25, 8, 5, 2, 6, 3})) == 4);
    REQUIRE(linear_search(-15, vector<int>({9, -15, 0, 3, 5})) == 1);
    REQUIRE(linear_search(0, vector<int>({1, 29, 6, 8, 5, 2, 0})) == 6);
    REQUIRE(linear_search(-0, vector<int>({0, -5, 25, 8, 5, 2, 6, 3})) == 0);
    REQUIRE(linear_search(0, vector<int>({1, 29, 6, 8, 5, 2})) == -1);
}


TEST_CASE("Mixed cases", "[searching][linear_search]") {
    REQUIRE(linear_search('a', vector<char>({'1', 'f', 'A', 'X', 'a'})) == 4);
    REQUIRE(linear_search(string("/"), vector<string>({"1", "/", "*", "-", "0"})) == 1);
    REQUIRE(linear_search(1.25, vector<double>({0.0, 6.15, 0.3, 1.25, 4})) == 3);
}
