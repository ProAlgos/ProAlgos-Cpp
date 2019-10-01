#include "third_party/catch.hpp"
#include "algorithm/searching/interpolation_search.hpp"

using std::vector;
using std::string;

TEST_CASE("Base cases", "[searching][interpolation_search]") {
    REQUIRE(interpolation(0, vector<int>()) == -1);
    REQUIRE(interpolation(1, vector<int>({1})) == 0);
    REQUIRE(interpolation(5, vector<int>({0})) == -1);
}

TEST_CASE("Integer cases", "[searching][interpolation_search]") {
    REQUIRE(interpolation(33, vector<int>({-5, 2, 7, 25, 33, 77, 88, 102})) == 4);
    REQUIRE(interpolation(-99, vector<int>({-99, -88, -53, -3, -1})) == 0);
    REQUIRE(interpolation(25, vector<int>({1, 6, 8, 13, 17, 21, 25})) == 6);
    REQUIRE(interpolation(4, vector<int>({0, 5, 9, 44, 67})) == -1);
}

TEST_CASE("Mixed cases", "[searching][interpolation_search]") {
    REQUIRE(interpolation(44, vector<int>({0, 5, 9, 44, 67,75})) == 3);
    REQUIRE(interpolation(25, vector<int>({1, 6, 8, 13, 17, 21, 25})) == 6);
    REQUIRE(interpolation(4, vector<int>({0, 5, 9, 44, 67})) == -1);
    REQUIRE(interpolation(2.8, vector<double>({0.1, 0.15, 0.3, 1.1, 2.3, 2.8, 3.14})) == 5);
}
