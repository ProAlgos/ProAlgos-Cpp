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

// Function for printing the optimal parenthesization of matrix chain product
void print_brackets(int begin, int end, const vector<vector<int>> &bracket, char &name)
{
    // If only one matrix left in current segment
    if (begin == end)
    {
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

void matrix_chain_order(const vector<int> &values)
{
    int size = values.size();
    vector<vector<int>> multiplications(size, vector<int>(size, 0));

    // bracket[i][j] stores optimal break point in
    // subexpression from i to j.
    vector<vector<int>> bracket(size, vector<int>(size, 0));

    /* multiplications[i,j] = Minimum number of scalar multiplications
    needed to compute the matrix A[i]A[i+1]...A[j] =
    A[i..j] where dimension of A[i] is p[i-1] x p[i] */

    for (int chain_length = 2; chain_length < size; chain_length++)
    {
        for (int i = 1; i < size - chain_length + 1; i++)
        {
            int j = i + chain_length - 1;
            multiplications[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int temp_mults = multiplications[i][k] + multiplications[k + 1][j] + values[i - 1] * values[k] * values[j];
                if (temp_mults < multiplications[i][j])
                {
                    multiplications[i][j] = temp_mults;

                    // Each entry bracket[i,j]=k shows
                    // where to split the product arr
                    // i,i+1....j for the minimum cost.
                    bracket[i][j] = k;
                }
            }
        }
    }

    // The first matrix is printed as 'A', next as 'B',
    // and so on
    char name = 'A';

    cout << "Optimal Parenthesization is : ";
    print_brackets(1, size - 1, bracket, name);
    cout << "\nOptimal Cost is : " << multiplications[1][size - 1] << endl;
}

// Driver code
int main()
{
    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    matrix_chain_order(vector<int>(arr, arr + n));
    return 0;
}
