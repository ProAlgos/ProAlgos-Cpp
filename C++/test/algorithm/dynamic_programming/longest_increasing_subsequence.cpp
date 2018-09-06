#include "third_party/catch.hpp"
#include "algorithm/dynamic_programming/longest_increasing_subsequence.hpp"

TEST_CASE("Base Cases", "[LIS]") {
  REQUIRE(lis(std :: vector < int > ({10, 22, 9, 33, 21, 50, 41, 60}),8) == 5);
}
TEST_CASE("Simple Cases", "[LIS]") {
  REQUIRE(lis(std :: vector < int > ({2, 5, 3, 7, 11, 8, 10, 13, 6}),9) == 6);
  REQUIRE(lis(std :: vector < int > ({58, 10, 45, -1, 100}),5) == 3);
  REQUIRE(lis(std :: vector < int > ({-5, 22, 9, 33, 21, 1, 41, 60 }),8) == 5);
  REQUIRE(lis(std :: vector < int > ({-5, 22, 9, -5, 21, 1, -8, 60 }),8) == 4);
  REQUIRE(lis(std :: vector < int > ({-5, 21, 1, -8, 60}),5) == 3);
}
