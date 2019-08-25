#include "third_party/catch.hpp"
#include "include/algorithms/dynamic_programming/longest_decreasing_subsequence.hpp"

using std::vector;

TEST_CASE("Base cases", "[longest_decreasing_subsequence]") {
	REQUIRE(longest_decreasing_subsequence(vector<int>({}) == 0);
	REQUIRE(longest_decreasing_subsequence(vector<int>({1}) == 1);
	REQUIRE(longest_decreasing_subsequence(vector<int>({11}) == 1);
}

TEST_CASE("Test cases", "[longest_decreasing_subsequence]") {
	REQUIRE(longest_decreasing_subsequence(vector<int>({1,2,3,4,0}) == 2);
	REQUIRE(longest_decreasing_subsequence(vector<int>({10,12,11,9,8,5,6,2}) == 7);
	REQUIRE(longest_decreasing_subsequence(vector<int>({1,2,3,4,5,6,7,8,9,10}) == 1);
}
