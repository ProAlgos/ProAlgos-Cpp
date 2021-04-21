#include "third_party/catch.hpp"
#include "algorithm/searching/interpolation_search.hpp"

using std::vector;
using std::string;

TEST_CASE("Base cases", "[searching][interpolation_search]") {
    REQUIRE(interpolation_search(0, vector<int>()) == -1);
    REQUIRE(interpolation_search(1, vector<int>({1})) == 0);
    REQUIRE(interpolation_search(5, vector<int>({0})) == -1);
}

TEST_CASE("Integer cases", "[searching][interpolation_search]") {
    REQUIRE(interpolation_search(31, vector<int>({-4, 3, 4, 17, 31, 47, 98, 118})) == 4);
    REQUIRE(interpolation_search(-50, vector<int>({-100, -50, 0, 50, 100})) == 1);
    REQUIRE(interpolation_search(42, vector<int>({-19, 3, 18, 29, 42, 51, 74})) == 4);
    REQUIRE(interpolation_search(100, vector<int>({0, 55, 69, 104, 200})) == -1);
}
