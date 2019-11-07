#define CATCH_CONFIG_MAIN
#include "third_party/catch.hpp"
#include "algorithm/dynamic_programming/coin_change.hpp"

using std::vector;

TEST_CASE("Base Cases", "[coin_change]") {
    REQUIRE(coin_change(vector<int>({1,2,3}), 3, 4) == 4);
}

TEST_CASE("Simple Cases", "[coin_change]") {
    REQUIRE(coin_change(vector<int>({2,5,3,6}), 4, 10) == 5);
    REQUIRE(coin_change(vector<int>({5,25,50}), 3, 1000) == 441);
    REQUIRE(coin_change(vector<int>({5,10,25,50}), 4, 3) == 0);
}
