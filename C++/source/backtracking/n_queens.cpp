/*
    N-Queens problem
    ----------------
    Find a way to place N non-attacking queens on an N×N chessboard
	
    Time complexity
    ---------------
    O(N!), where N is the number of queens

    Space complexity
    ----------------
    O(1), constant amount of extra space
*/

#include <iostream>

using namespace std;

const int MaxQueens = 40;
bool board[MaxQueens][MaxQueens];

void initBoard(const size_t size) {
    size_t r, c;
    for (r = 0; r < size; r++)
        for (c = 0; c < size; c++)
            board[r][c] = false;
}

void showBoard(const size_t size) {
    size_t r, c;
    for (r = 0; r < size; r++) {
        for (c = 0; c < size; c++) {
            if (board[r][c])
                cout << 'Q';
            else
                cout << '.';
            cout << ' ';
        }
        cout << '\n';
    }
}

bool isSafe(const int row, const int col, const int size) {
    int r, c;
    // check along the column
    for (r = 0; r < size; r++)
        if (board[r][col])
            return false;

    // check along the row
    for (c = 0; c < col; c++)
        if (board[row][c])
            return false;

    // check diagonally
    for (c = col-1, r = row-1; c >= 0 && r >= 0; c--, r--)
        if (board[r][c])
            return false;
    for (c = col-1, r = row+1; c >= 0 && r < size; c--, r++)
        if (board[r][c])
            return false;

    return true;
}

bool canPlaceQueens(const size_t col, const size_t size) {
    if (col == size)
        return true;

    for (size_t row = 0; row < size; row++) {
        if (isSafe(row, col, size)) {
            board[row][col] = true;
            if (canPlaceQueens(col+1, size))
                return true;
            board[row][col] = false;
        }
    }

    return false;
}

int main() {
    int N;        // number of queens to place = N, size of board = NxN
    cout << "Enter the number of queens to place (max " << MaxQueens << ") : ";
    cin >> N;

    initBoard(N);

    if (canPlaceQueens(0, N)) {
        cout << "Found a way!\n";
        showBoard(N);
    }
    else
        cout << "Couldn\'t find a way to place " << N << " queens on a " << N << "x" << N << " board\n";

    return 0;
}
