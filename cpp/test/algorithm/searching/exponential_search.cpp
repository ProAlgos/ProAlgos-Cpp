#include "third_party/catch.hpp"
#include "algorithm/searching/exponential_search.hpp"

using std::vector;
using std::string;

TEST_CASE("Base cases", "[searching][exponential_search]") {
    REQUIRE(exponential_search(2, vector<int>({0})) == -1);
    REQUIRE(exponential_search(0, vector<int>()) == -1);
    REQUIRE(exponential_search(1, vector<int>({1})) == 0);
}
    

TEST_CASE("Integer cases", "[searching][exponential_search]") {
    REQUIRE(exponential_search(57, vector<int>({-3, 4, 6, 11, 25, 57, 68, 92})) == 5);
    REQUIRE(exponential_search(-34, vector<int>({-99, -34, -28, -23, -16})) == 1);
    REQUIRE(exponential_search(98, vector<int>({1, 16, 28, 33, 57, 61, 98})) == 6);
    REQUIRE(exponential_search(4, vector<int>({0, 5, 9, 40, 57})) == -1);
}

TEST_CASE("Mixed cases", "[searching][exponential_search]") {
    REQUIRE(exponential_search('c', vector<char>({'a', 'b', 'c', 'd', 'e'})) == 3);
    REQUIRE(exponential_search(string("3"), vector<string>({"1", "2", "3", "4", "5"})) == 1);
    REQUIRE(exponential_search(0.15, vector<double>({0.01, 0.15, 0.23, 1.19, 2.13, 2.68, 3.04})) == 5);
}
