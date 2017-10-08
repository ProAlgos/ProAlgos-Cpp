/*
    Fibonacci number
    -----------------
    Find the N-th Fibonacci number, given the value of N.
    (The Fibonacci sequence is characterized by the fact that every number
    after the first two is the sum of the two preceding ones.)

    Time complexity
    ---------------
    O(log N), where N is the term of the Fibonacci sequence to calculate

    Space complexity
    ----------------
    O(1).
*/

#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long int ULL;

const int MAX_N = 93;   // fibonacci(94) goes beyond the range of ULL

// Binary exponentiation (of matrix)
vector< vector<ULL> > pow_matrix(const vector< vector<ULL> > &matrix, const int n) {
    if (n == 1)
        return matrix;
    else if (n % 2 == 0) {
        // a ^ n = a ^ (n / 2) * a ^ (n / 2)
        vector< vector<ULL> > tmp_matrix = pow_matrix(matrix, n / 2);
        vector< vector<ULL> > sqr_tmp_matrix(2, vector<ULL> (2, 0));

        // matrix product
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    sqr_tmp_matrix[i][j] += tmp_matrix[i][k] * tmp_matrix[k][j];
        return sqr_tmp_matrix;
    }
    else {
        // a ^ n = a * a ^ (n - 1)
        vector< vector<ULL> > tmp_matrix = pow_matrix(matrix, n - 1);
        vector< vector<ULL> > sqr_tmp_matrix(2, vector<ULL> (2, 0));

        // matrix product
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    sqr_tmp_matrix[i][j] += tmp_matrix[i][k] * matrix[k][j];
        return sqr_tmp_matrix;
    }
}

ULL fibonacci(const int n) {
    vector< vector<ULL> > matrix = {{1, 1},
                                    {1, 0}};
    ULL fibo;   // F(n)

    if (n == 0 or n == 1)
        return n;   // since F(0) = 0, and F(1) = 1
    if (n == 2)
        return 1;   // F(2) = 1

    // recurrence formula (1 1)   (F(n - 1))   (  F(n)  )
    //                    (1 0) * (F(n - 2)) = (F(n - 1))
    matrix = pow_matrix(matrix, n - 2);
    fibo = matrix[0][0] + matrix[0][1];

    return fibo;
}

void getInput(int &n) {
    cout << "Enter the value for N (max. " << MAX_N << ") : ";
    cin >> n;

    if (n < 0 or n > MAX_N) {
        cout << "Invalid value! N should be between 0 and " << MAX_N << ".\n";
        getInput(n);
    }
}

#ifndef FIBONACCI_TEST
int main() {
    int n;
    getInput(n);

    cout << "\nFibonacci(" << n << ") = " << fibonacci(n) << "\n";

    return 0;
}
#endif
