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
#include <bits/stdc++.h>

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
    int size = values.size();
    if (size <= 2) return 0;
    vector<vector<ULL>> multiplications(size, vector<ULL>(size, 0));

    // multiplications[i,j] = Minimum number of scalar multiplications
    // needed to compute the matrix A[i]A[i+1]...A[j] =
    // A[i..j] where dimension of A[i] is p[i-1] x p[i]

    for (int chain_length = 2; chain_length < size; chain_length++)
    {
        for (int i = 1; i < size - chain_length + 1; i++)
        {
            int j = i + chain_length - 1;
            multiplications[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                ULL temp_mults = multiplications[i][k] + multiplications[k + 1][j] + values[i - 1] * values[k] * values[j];
                if (temp_mults < multiplications[i][j])
                {
                    multiplications[i][j] = temp_mults;

                    // Each entry bracket[i,j]=k shows where to split the product values
                    // i,i+1....j for the minimum cost.
                    bracket[i][j] = k;
                }
            }
        }
    }

    return multiplications[1][size - 1];
}

void get_input_size(size_t& size) {
    cout << "Enter the input size : ";
    cin >> size;

    if ((int) size <= 1) {
        cout << "Invalid input size! Try again.\n";
        get_input_size(size);
    }
}

void get_input_values(vector<int>& values, const size_t& size) {
    cout << "Enter " << size << " integers :";
    for (int& val: values)
        cin >> val;
    cin.ignore();
}

#ifndef MATRIX_MULTIPLICATION_TEST
int main()
{
    size_t size;
    get_input_size(size);

    vector<int> values(size);
    get_input_values(values, size);
    
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
