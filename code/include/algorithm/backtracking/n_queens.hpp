/*
    N queens problem
    ----------------
    Find a way to place N non-attacking queens on an N×N chessboard.

    Time complexity
    ---------------
    O(N!), where N is the number of queens.

    Space complexity
    ----------------
    O(N^2), where N is the number of queens.
*/

#ifndef N_QUEENS_HPP
#define N_QUEENS_HPP

#include <iostream>
#include <vector>

typedef std::vector<std::vector<bool>> Board;

const int MAX_QUEENS = 40;


/*
    NQueensSolver
    ------------
    Wrapper class for solving the N-Queens problem.
*/

class NQueensSolver {
    size_t N;
    bool is_solved;
    std::vector<Board> solutions;

public:
    NQueensSolver(const size_t);
    bool can_place_queens() const;
    size_t num_solutions() const;
    Board get_solution() const;
    std::vector<Board> get_solutions() const;
    void print_solution() const;
    void print_all_solutions() const;

private:
    void solve();
    bool place_queens(Board&, const size_t);
    bool is_safe(const Board&, const int, const int) const;
    void print_solution(const Board&) const;
};


/*
    Constructor
    -----------
*/

NQueensSolver::NQueensSolver(const size_t num_queens) {
    N = num_queens;
    is_solved = false;
    solve();
}


/*
    ==========================================================================
    Public interface
    ==========================================================================
*/


/*
    can_place_queens
    ----------------
    Returns whether it is possible to place N queens on an NxN chessboard.
*/

bool NQueensSolver::can_place_queens() const {
    return bool(solutions.size());
}


/*
    num_solutions
    -------------
    Returns the number of ways in which N queens can be placed on an NxN
    chessboard.
*/

size_t NQueensSolver::num_solutions() const {
    return solutions.size();
}


/*
    get_solution
    ------------
    Returns an NxN boolean matrix in which all N queens have been placed.
    The cells that are marked 'true' are where queens are placed, and all
    the other cells marked 'false' are empty.
*/

Board NQueensSolver::get_solution() const {
    return solutions[0];
}


/*
    get_solutions
    -------------
    Returns a list of NxN boolean matrices, all of which are valid solutions
    to the N-Queens problem. In each matrix, the cells that are marked 'true'
    are where queens are placed, and all the other cells marked 'false' are
    empty.
*/

std::vector<Board> NQueensSolver::get_solutions() const {
    return solutions;
}


/*
    print_solution
    --------------
    Prints a solution for the N-Queens problem. 'Q' is printed for a queen,
    and '.' is printed for an empty cell.
*/

void NQueensSolver::print_solution() const {
    print_solution(solutions[0]);
}


/*
    print_all_solutions
    -------------------
    Prints all possible solution for the N-Queens problem. 'Q' is printed for
    a queen, and '.' is printed for an empty cell.
*/

void NQueensSolver::print_all_solutions() const {
    for (const Board& board: solutions) {
        print_solution(board);
        std::cout << "\n";
    }
}


/*
    ==========================================================================
    Private methods
    ==========================================================================
*/


/*
    solve
    -----
    Calls the `place_queens` method that tries to place N queens on an NxN
    chessboard.
*/

void NQueensSolver::solve() {
    Board board(N, std::vector<bool>(N, false));
    place_queens(board, 0);
    is_solved = true;
}


/*
    place_queens
    ------------
    Tries to place the i-th queen on different rows along the (i-1)-th column,
    and if in that position the remaning queens can be successfully placed, it
    adds the arrangement to the list of solutions.
*/

bool NQueensSolver::place_queens(Board& board, const size_t col) {
    if (col == N)
        return true;     // all N queens have been placed

    for (size_t row = 0; row < N; row++) {
        if (is_safe(board, row, col)) {
            board[row][col] = true;
            if (place_queens(board, col + 1))
                solutions.push_back(board);
            board[row][col] = false;
        }
    }

    return false;
}


/*
    is_safe
    -------
    Checks whether a queen that is being placed at the given row and column
    will be safe from being attacked by other queens that have already been
    placed on the board.
*/

bool NQueensSolver::is_safe(const Board& board, const int row, const int col) const {
    int r, c;
    // check along the column
    for (r = 0; r < N; r++)
        if (board[r][col])
            return false;   // queen will be attacked along the column

    // check along the row
    for (c = 0; c < col; c++)
        if (board[row][c])
            return false;   // queen will be attacked along the row

    // check diagonally
    for (c = col-1, r = row-1; c >= 0 && r >= 0; c--, r--)
        if (board[r][c])
            return false;   // queen will be attacked along the main diagonal
    for (c = col-1, r = row+1; c >= 0 && r < N; c--, r++)
        if (board[r][c])
            return false;   // queen will be attacked along the minor diagonal

    return true;    // queen will be safe at this position
}


/*
    print_solution
    --------------
    Prints a given solved board. 'Q' is printed for a queen, and '.' is printed
    for an empty cell.
*/

void NQueensSolver::print_solution(const Board& board) const {
    size_t row, col;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (board[row][col])
                std::cout << 'Q';
            else
                std::cout << '.';
            std::cout << ' ';
        }
        std::cout << '\n';
    }
}

#endif  // N_QUEENS_HPP
