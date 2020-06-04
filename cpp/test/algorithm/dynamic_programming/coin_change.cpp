#define CATCH_CONFIG_MAIN
#include "third_party/catch.hpp"
#include "algorithm/dynamic_programming/coin_change.hpp"

using std::vector;

TEST_CASE("Base Cases", "[coin_change]") {
    REQUIRE(coin_change(vector<int>({}), 0, 0) == 1);
    REQUIRE(coin_change(vector<int>({}), 0, 3) == 0);
    REQUIRE(coin_change(vector<int>({1}), 1, 0) == 1);
    REQUIRE(coin_change(vector<int>({7}), 1, 7) == 1);
}

TEST_CASE("Simple Cases", "[coin_change]") {
    REQUIRE(coin_change(vector<int>({2,5,3,6}), 4, 10) == 5);
    REQUIRE(coin_change(vector<int>({5,25,50}), 3, 1000) == 441);
    REQUIRE(coin_change(vector<int>({5,10,25,50}), 4, 3) == 0);
    REQUIRE(coin_change(vector<int>({1,14,23,45}), 4, 234) == 239);
    REQUIRE(coin_change(vector<int>({1,3,5,7,11,13}), 6, 121) == 30447);
    REQUIRE(coin_change(vector<int>({4,5,6}), 3, 7) == 0);
    REQUIRE(coin_change(vector<int>({1,1,1}), 3, 123) == 7750);
    REQUIRE(coin_change(vector<int>({1,1,2,2,4,4}), 6, 37) == 21032);
    REQUIRE(coin_change(vector<int>({4,5,6}), 3, 7) == 0);
    REQUIRE(coin_change(vector<int>({2,4,8,16,32,64,128,256,512,1024}), 10, 1000) == 26338428);
}
