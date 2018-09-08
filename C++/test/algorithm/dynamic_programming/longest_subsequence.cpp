#include "third_party/catch.hpp"
#include "algorithms/dynamic_programming/longest_subsequence.hpp"

using namespace std;

TEST_CASE("Base cases", "[longest_subsequence]"){
	REQUIRE(longest_subsequence(vector<int>({0})) == 1);
	REQUIRE(longest_subsequence(vector<int>({})) == 0);
}

TEST_CASE("non Base cases", "[longest_subsequence]"){
	REQUIRE(longest_subsequence(vector<int>({0, 1, 2, 3})) == 4);
	REQUIRE(longest_subsequence(vector<int>({2, 1, 2, 3, 4})) == 4);
	REQUIRE(longest_subsequence(vector<int>({5, 4, 6, 3, 10, 8})) == 3);
}
