#include "third_party/catch.hpp"
#include "algorithms/searching/binary_search.hpp"


TEST_CASE("Base cases", "[binary search]") {
    REQUIRE(binary_search(1, vector<int>({1}), 0, 1) == 0);
    REQUIRE(binary_search(5, vector<int>({0}), 0, 1) == -1);
}

TEST_CASE("Integer cases", "[binary search]") {
    REQUIRE(binary_search(33, vector<int>({-5, 2, 7, 25, 33, 77, 88, 102}), 0, 7) == 4);
    REQUIRE(binary_search(-99, vector<int>({-99, -88, -53, -3, -1}), 0, 4) == 0);
    REQUIRE(binary_search(25, vector<int>({1, 6, 8, 13, 17, 21, 25}), 0, 6) == 6);
    REQUIRE(binary_search(4, vector<int>({0, 5, 9, 44, 67}),0 ,4) == -1);
}

TEST_CASE("Mixed cases", "[linear search]") {
    REQUIRE(binary_search('d', vector<char>({'a', 'b', 'c', 'd', 'e'})) == 3);
    REQUIRE(binary_search(std::string("2"), vector<std::string>({"1", "2", "3", "4", "5"})) == 1);
    REQUIRE(binary_search(2.8, vector<double>({0.1, 0.15, 0.3, 1.1, 2.3, 2.8, 3.14})) == 5);
}
