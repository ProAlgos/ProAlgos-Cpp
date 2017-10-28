#define MATRIX_CHAIN_MULT_TEST
#define CATCH_CONFIG_MAIN

#include "third_party/catch.hpp"
#include "source/dynamic_programming/matrix_chain_mult.cpp"


TEST_CASE("Base cases", "[matrix_chain_mult] [matrix_chain_order]") {
    REQUIRE(matrix_chain_order(vector<int>({1})) == 0);
    REQUIRE(matrix_chain_order(vector<int>({20, 30})) == 0);
}

TEST_CASE("Normal cases", "[matrix_chain_mult] [matrix_chain_order]") {
    REQUIRE(matrix_chain_order(vector<int>({40, 30, 20, 10, 30})) == 30000);
    REQUIRE(matrix_chain_order(vector<int>({100, 20, 50, 90})) == 270000);
    REQUIRE(matrix_chain_order(vector<int>({20, 30, 50, 70, 40, 30, 100, 30, 55, 20})) == 333000);
}

#undef MATRIX_CHAIN_MULT_TEST
