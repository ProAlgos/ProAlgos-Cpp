/*
    Matrix Chain Multiplication
    ----------
    Given a series of matrices, to find the most efficient way to multiply the matrices together.
    The problem is to decide the order in which to multiply the matrices.

    Time complexity
    ---------------
    O(N^3), where N is the number of matrices.

    Space complexity
    ----------------
    O(N^2).
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

typedef unsigned long long int ULL;

// Function for printing the optimal parenthesization of matrix chain product
void print_brackets(int begin, int end, const vector<vector<int>>& bracket, char& name)
{
    if (begin == end)
    {
        // If only one matrix left in current segment
        cout << name++;
        return;
    }

    cout << "(";

    // Recursively put brackets around subexpression
    // from begin to bracket[begin][end].
    print_brackets(begin, bracket[begin][end], bracket, name);

    // Recursively put brackets around subexpression
    // from bracket[begin][end] + 1 to end.
    print_brackets(bracket[begin][end] + 1, end, bracket, name);
    cout << ")";
}

ULL matrix_chain_order(const vector<int>& values, vector<vector<int>>& bracket)
{
    size_t size = values.size();
    if (size <= 2) return 0;
    vector<vector<ULL>> multiplications(size, vector<ULL>(size, 0));

    // multiplications[i,j] = Minimum number of scalar multiplications
    // needed to compute the matrix A[i]A[i+1]...A[j] =
    // A[i..j] where dimension of A[i] is p[i-1] x p[i]

    for (size_t chain_length = 2; chain_length < size; chain_length++)
    {
        for (size_t i = 1; i < size - chain_length + 1; i++)
        {
            size_t j = i + chain_length - 1;
            multiplications[i][j] = INT_MAX;
            for (size_t k = i; k <= j - 1; k++)
            {
                ULL temp_mults = multiplications[i][k] + multiplications[k + 1][j] + values[i - 1] * values[k] * values[j];
                if (temp_mults < multiplications[i][j])
                {
                    multiplications[i][j] = temp_mults;

                    if(!bracket.empty()) {
                        // Each entry bracket[i,j]=k shows where to split the product values
                        // i,i+1....j for the minimum cost.
                        bracket[i][j] = k;
                    }
                }
            }
        }
    }

    return multiplications[1][size - 1];
}

ULL matrix_chain_order(const vector<int>& values)
{
    vector<vector<int>> bracket = vector<vector<int>>();
    return matrix_chain_order(values, bracket);
}

void get_num_matrices(size_t& num_matrices) {
    cout << "Enter the number of matrices : ";
    cin >> num_matrices;

    if ((int) num_matrices <= 1) {
        cout << "Invalid number of matrices! Try again.\n";
        get_num_matrices(num_matrices);
    }
}

void get_matrix_sizes(vector<int>& matrix_sizes, const size_t& num_matrices) {
    cout << "Enter " << num_matrices << " integers :";
    for (int& value: matrix_sizes)
        cin >> value;
    cin.ignore();
}

#ifndef MATRIX_MULTIPLICATION_TEST
int main()
{
    size_t size;
    get_num_matrices(size);

    vector<int> values(size);
    get_matrix_sizes(values, size);

    // bracket[i][j] stores optimal break point in subexpression from i to j.
    vector<vector<int>> bracket(size, vector<int>(size, 0));
    ULL cost = matrix_chain_order(values, bracket);
    cout << "Optimal Cost is : " << cost << endl;

    // The first matrix is printed as 'A', next as 'B' and so on
    char name = 'A';
    cout << "Optimal Parenthesization is : ";
    print_brackets(1, size - 1, bracket, name);
    cout << endl;
    return 0;
}
#endif
