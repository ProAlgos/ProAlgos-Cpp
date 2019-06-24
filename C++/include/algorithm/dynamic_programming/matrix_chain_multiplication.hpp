/*
    Matrix chain multiplication
    ---------------------------
    Given a sequence of matrices, find the most efficient way to multiply these
    matrices, by deciding the sequence of the matrix multiplications involved.

    Time complexity
    ---------------
    O(N^3), where N is the number of matrices.

    Space complexity
    ----------------
    O(N^2), where N is the number of matrices.
*/

#ifndef MATRIX_CHAIN_MULTIPLICATION_HPP
#define MATRIX_CHAIN_MULTIPLICATION_HPP

#include <climits>
#include <iostream>
#include <vector>

typedef unsigned long long int ull;


/*
    MatrixChainMultiplier
    ---------------------
    Wrapper class for solving the matrix chain multiplication problem.
*/

class MatrixChainMultiplier {
    std::vector<size_t> matrix_sizes;
    std::vector<std::vector<int>> parentheses;
    std::string parenthesized_result;
    ull cost;

    public:
        MatrixChainMultiplier();
        MatrixChainMultiplier(std::vector<size_t>);
        ull optimal_cost();
        std::string optimal_parenthesization();
    
    private:
        ull find_optimal_cost();
        void find_optimal_parenthesization(int, int, char&);
};


/*
    Default constructor
    -------------------
*/

MatrixChainMultiplier::MatrixChainMultiplier() {
    matrix_sizes = std::vector<size_t>();
    // parentheses[i][j] stores optimal break point in sub-expression from i to j
    parentheses = std::vector<std::vector<int>>();
    parenthesized_result = "";
    cost = 0;
}


/*
    Constructor
    -----------
    Takes a vector of unsigned integers, where the `i`th integer corresponds
    to the number of columns of the `i-1`th matrix and the number of rows of
    the `i`th matrix. Except for the first and last integers, which correspond
    to the number of rows in the first matrix and the number of columns in the
    last matrix respectively.
    
    Eg. for a chain of matrices sized:
        10x30, 30x20, 20x15, 15x35, 35x20, 20x40
    the dimension vector would be:
        {10, 30, 20, 15, 35, 20, 40}
*/

MatrixChainMultiplier::MatrixChainMultiplier(std::vector<size_t> dimensions) {
    if (dimensions.size() < 4) {
        // for the minimum of 3 matrices, 4 dimension values are required
        std::invalid_argument("You need to provide at least 4 dimension values"
            ", as there need to be atleast 3 matrices.");
    }
    else if (dimensions.size() > 27) {
        // a maximum of 26 matrices are supported (27 dimension values)
        std::invalid_argument("You can only provide at most 27 dimension values"
            ", since the maximum number of matrices supported is 26.");
    }

    for (size_t dimension: dimensions)
        if (dimension == 0) {
            std::invalid_argument("A dimension is zero, which is not a valid"
                "value.");
        }

    matrix_sizes = dimensions;
    // parentheses[i][j] stores optimal break point in sub-expression from i to j
    parentheses = std::vector<std::vector<int>>(dimensions.size(), std::vector<int>(dimensions.size(), 0));
    parenthesized_result = "";
    cost = 0;
}


/*
    ==========================================================================
    Public interface
    ==========================================================================
*/


/*
    optimal_cost
    ------------
    Returns the optimal cost 
*/

ull MatrixChainMultiplier::optimal_cost() {
    return cost ? cost : find_optimal_cost();
}


/*
    optimal_parenthesization
    ------------------------
    Returns a string that has the optimal parenthesization of matrix chain product.
*/

std::string MatrixChainMultiplier::optimal_parenthesization() {
    if (parenthesized_result == "") {
        char matrix_symbol = 'A';       // matrices are named as A, B, C, ...
        size_t start = 1, end = matrix_sizes.size() - 1;
        find_optimal_parenthesization(start, end, matrix_symbol);
    }

    return parenthesized_result;
}


/*
    ==========================================================================
    Private methods
    ==========================================================================
*/


/*
    find_optimal_cost
    -----------------
*/

ull MatrixChainMultiplier::find_optimal_cost() {
    size_t num_matrices = matrix_sizes.size();

    // mult_cost[i,j] is the minimum number of scalar multiplications
    // needed to compute the matrix:
    // A[i] x A[i+1] x ... x A[j]
    std::vector<std::vector<ull>> mult_cost(num_matrices, std::vector<ull>(num_matrices, 0));

    for (size_t chain_length = 2; chain_length < num_matrices; chain_length++) {
        for (size_t i = 1; i < num_matrices - chain_length + 1; i++) {
            size_t j = i + chain_length - 1;
            mult_cost[i][j] = INT_MAX;
            for (size_t k = i; k <= j - 1; k++) {
                ull cost = mult_cost[i][k]
                        + mult_cost[k + 1][j]
                        + matrix_sizes[i - 1] * matrix_sizes[k] * matrix_sizes[j];
                if (cost < mult_cost[i][j]) {
                    mult_cost[i][j] = cost;
                    parentheses[i][j] = k;
                }
            }
        }
    }

    return mult_cost[1][num_matrices - 1];
}


/*
    find_optimal_parenthesization
    -----------------------------
    Returns a string that has the optimal parenthesization of matrix chain product.
*/

void MatrixChainMultiplier::find_optimal_parenthesization(int begin, int end,
        char& matrix_symbol) {
    if (begin == end) {     // last matrix in the current segment
        parenthesized_result += matrix_symbol++;
        return;
    }

    parenthesized_result += '(';
    // recursively place the parentheses around the sub-expression
    // from `begin` to `parentheses[begin][end]`
    find_optimal_parenthesization(begin, parentheses[begin][end], matrix_symbol);
    // from `parentheses[begin][end] + 1` to `end`
    find_optimal_parenthesization(parentheses[begin][end] + 1, end, matrix_symbol);
    parenthesized_result += ')';
}

#endif // MATRIX_CHAIN_MULTIPLICATION_HPP
