#include "third_party/catch.hpp"
#include "algorithm/dynamic_programming/0_1_knapsack.hpp"
using std::vector;

TEST_CASE("Base Cases", "[knapsack]") {
    REQUIRE(knapsack(10, 3, vector<LL>({11, 21, 31}), vector<LL>({1, 2, 3})) == 0);
}
TEST_CASE("Simple Cases", "[knapsack]") {
    REQUIRE(knapsack(50, 3, vector<LL>({10, 20, 30}), vector<LL>({60, 200, 220})) == 420);
    REQUIRE(knapsack(4, 5, vector<LL>({1, 2, 3, 2, 2}), vector<LL>({8, 4, 0, 5, 3})) == 13);
    REQUIRE(knapsack(4, 5, vector<LL>({1, 2, 3, 2, 2}), vector<LL>({11, 22, 11, 23, 24})) == 47);
}
