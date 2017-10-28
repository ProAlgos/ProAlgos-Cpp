/*
    Matrix chain multiplication
    ---------------------------
    Given a series of matrices, to find the most efficient way to multiply the matrices together.
    The problem is to decide the order in which to multiply the matrices.

    Time complexity
    ---------------
    O(N^3), where N is the number of matrices.

    Space complexity
    ----------------
    O(N^2), where N is the number of matrices.
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

typedef unsigned long long int ULL;

/*
    print_brackets
    --------------
    Prints the optimal parenthesization of matrix chain product.
*/
void print_brackets(int begin, int end, const vector<vector<int>>& bracket, char& matrix_name) {
    if (begin == end) {     // only one matrix left in current segment
        cout << matrix_name++;
        return;
    }

    cout << "(";

    // recursively put brackets around sub-expression
    // from `begin` to `bracket[begin][end]`
    print_brackets(begin, bracket[begin][end], bracket, matrix_name);
    // from `bracket[begin][end] + 1` to `end`.
    print_brackets(bracket[begin][end] + 1, end, bracket, matrix_name);

    cout << ")";
}


ULL matrix_chain_order(const vector<int>& matrix_sizes, vector<vector<int>>& bracket) {
    size_t num_matrices = matrix_sizes.size();

    if (num_matrices <= 2)
        return 0;

    // multiplications[i, j] is the minimum number of scalar multiplications
    // needed to compute the matrix:
    //      A[i] x A[i+1] x ... x A[j]
    vector<vector<ULL>> multiplications(num_matrices, vector<ULL>(num_matrices, 0));

    size_t i, j, k;
    for (size_t chain_length = 2; chain_length < num_matrices; chain_length++) {
        for (i = 1; i < num_matrices - chain_length + 1; i++) {
            j = i + chain_length - 1;
            multiplications[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                ULL temp_mults = multiplications[i][k]
                        + multiplications[k + 1][j]
                        + matrix_sizes[i - 1] * matrix_sizes[k] * matrix_sizes[j];
                if (temp_mults < multiplications[i][j]) {
                    multiplications[i][j] = temp_mults;

                    if(!bracket.empty()) {
                        // bracket[i,j] shows where to split the product values
                        // i..j for the minimum cost.
                        bracket[i][j] = k;
                    }
                }
            }
        }
    }

    return multiplications[1][num_matrices - 1];
}

ULL matrix_chain_order(const vector<int>& matrix_sizes) {
    vector<vector<int>> bracket;
    return matrix_chain_order(matrix_sizes, bracket);
}

void get_num_matrices(size_t& num_matrices) {
    cout << "Enter the number of matrices : ";
    cin >> num_matrices;

    if ((int) num_matrices <= 1) {
        cout << "Invalid number of matrices! Try again.\n";
        get_num_matrices(num_matrices);
    }
}

void get_matrix_sizes(vector<int>& matrix_sizes, size_t num_matrices) {
    cout << "Enter " << num_matrices << " dimensions (the row dimensions of the "
        << num_matrices - 1 << " matrices and the column dimension of the last"\
        " matrix in the chain):\n";
    for (int& value: matrix_sizes)
        cin >> value;
    cin.ignore();
}

#ifndef MATRIX_CHAIN_MULT_TEST
int main() {
    size_t num_matrices;
    get_num_matrices(num_matrices);

    vector<int> matrix_sizes(num_matrices + 1);
    get_matrix_sizes(matrix_sizes, num_matrices + 1);

    // bracket[i][j] stores optimal break point in sub-expression from i to j.
    vector<vector<int>> bracket(num_matrices + 1, vector<int>(num_matrices + 1, 0));
    ULL cost = matrix_chain_order(matrix_sizes, bracket);
    cout << "\nOptimal cost: " << cost << "\n";

    char matrix_name = 'A';     // matrices are named as A, B, C, ... so on
    cout << "Optimal parenthesization:\n";
    print_brackets(1, num_matrices, bracket, matrix_name);
    cout << "\n";

    return 0;
}
#endif  // MATRIX_CHAIN_MULT_TESTof
