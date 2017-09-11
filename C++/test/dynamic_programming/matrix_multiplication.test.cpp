#define MATRIX_MULTIPLICATION_TEST
#define CATCH_CONFIG_MAIN

#include "third_party/catch.hpp"
#include "source/dynamic_programming/matrix_multiplication.cpp"

vector<vector<int>> bracket;

TEST_CASE("Base cases", "[matrix_chain_order]") {
    bracket = vector<vector<int>>(1, vector<int>(1,0));
    REQUIRE(matrix_chain_order(vector<int>({1}), bracket) == 0);
    bracket = vector<vector<int>>(2, vector<int>(2,0));
    REQUIRE(matrix_chain_order(vector<int>({20, 30}), bracket) == 0);
}

TEST_CASE("Normal cases", "[matrix_chain_order]") {
    bracket = vector<vector<int>>(5, vector<int>(5,0));
    REQUIRE(matrix_chain_order(vector<int>({40, 30, 20, 10, 30}), bracket) == 30000);
    bracket = vector<vector<int>>(4, vector<int>(4,0));
    REQUIRE(matrix_chain_order(vector<int>({100, 20, 50, 90}), bracket) == 270000);
    bracket = vector<vector<int>>(10, vector<int>(10,0));
    REQUIRE(matrix_chain_order(vector<int>({20, 30, 50, 70, 40, 30, 100, 30, 55, 20}), bracket) == 333000);
}

#undef MATRIX_MULTIPLICATION_TEST
