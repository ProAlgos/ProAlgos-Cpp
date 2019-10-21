/*
    Fibonacci number
    -----------------
    Find the N-th Fibonacci number, given the value of N.
    (The Fibonacci sequence is characterized by the fact that every number
    after the first two is the sum of the two preceding ones.)

    Time complexity
    ---------------
    O(log(N)), where N is the term of the Fibonacci sequence to calculate.

    Space complexity
    ----------------
    O(1).
*/

#ifndef FIBONACCI_EFFICIENT_HPP
#define FIBONACCI_EFFICIENT_HPP

#include <vector>

using std::vector;

typedef unsigned long long int ULL;

const int MAX_N = 93;   // fibonacci(94) goes beyond the range of ULL


// Product of two matrices. Their sizes must be [n, m] and [m, p]
vector<vector<ULL>> matrix_product(const vector<vector<ULL>> &first_matrix, const vector<vector<ULL>> &second_matrix) {
    // Example: If First[n, m] and Second[m, p], then their product will be Product[n, p]
    vector<vector<ULL>> product_of_matrices(first_matrix.size(), vector<ULL> (second_matrix[0].size()));

    for (size_t i = 0; i < first_matrix.size(); i++) // For previous example i:0..n-1
        for (size_t j = 0; j < second_matrix[0].size(); j++) // For previous example j:0..p-1
            for (size_t k = 0; k < second_matrix.size(); k++) // For previous example k:0..m-1
                product_of_matrices[i][j] += first_matrix[i][k] * second_matrix[k][j];
    return product_of_matrices;
}


// Binary exponentiation (of matrix)
vector<vector<ULL>> pow_matrix(const vector< vector<ULL> > &matrix, const int n) {
    if (n == 1)
        return matrix;

    vector<vector<ULL>> tmp_matrix;
    vector<vector<ULL>> product_of_matrices;
    if (n % 2 == 0) {
        tmp_matrix = pow_matrix(matrix, n / 2);     // a ^ n = a ^ (n / 2) * a ^ (n / 2)
        product_of_matrices = matrix_product(tmp_matrix, tmp_matrix);
    }
    else {
        tmp_matrix = pow_matrix(matrix, n - 1);     // a ^ n = a ^ (n - 1) * a
        product_of_matrices = matrix_product(tmp_matrix, matrix);
    }
    return product_of_matrices;
}


ULL fibonacci(const int n) {
    if (n > MAX_N)
        return -1;

    if (n == 0 or n == 1)
        return n;   // since F(0) = 0, and F(1) = 1
    if (n == 2)
        return 1;   // F(2) = 1

    // recurrence formula (1 1)   (F(n - 1))   (  F(n)  )
    //                    (1 0) * (F(n - 2)) = (F(n - 1))
    vector<vector<ULL>> matrix = {
        {1, 1},
        {1, 0}
    };
    matrix = pow_matrix(matrix, n - 2);
    ULL fn = matrix[0][0] + matrix[0][1];   // F(n)

    return fn;
}

#endif // FIBONACCI_EFFICIENT_HPP
