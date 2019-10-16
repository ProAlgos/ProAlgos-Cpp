/*
    Knight Problem
    ----------------
    Find whether knight can cover each cell of NXN chessboard or not.
    
*/

#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include <iostream>
#include <vector>

using namespace std;

/*
    KnightSolver
    ------------
    Wrapper class for solving the Knight problem.
*/

class KnightSolver{
    int N, R, C, moveDone;
    bool isSuccessful;
    vector <vector<int>> board;
    const int row[8] = {+2, +1, -1, -2, -2, -1, +1, +2}, col[8] = {+1, +2, +2, +1, -1, -2, -2, -1};

public:
    KnightSolver(const int n, const int r, const int c);
    bool isSolvable();
    vector <vector<int>> getSolution();

private:
    bool solveKnight();
    bool canPlace(const vector <vector<int>> &board, int n, int r,int c);
};


/*
    Constructor
    -----------
*/

KnightSolver::KnightSolver(const int n, const int r, const int c) {
    N = n;
    R = r;
    C = c;
    moveDone = 1;
    vector <vector<int>> Chessboard(n,vector <int> (n,0));
    board = Chessboard;
    board[r][c] = 1;
    isSuccessful = solveKnight();
}

/*
    isSolvable
    -----
    returns true if board is knight has successfully covered each cell, otherwise false
*/

bool KnightSolver::isSolvable(){
    return isSuccessful;
}

/*
    getSolution
    -----
    Returns the board
*/

vector <vector<int>> KnightSolver::getSolution(){
    return board;
}

/*
    solveKnight
    -----
    Solves the board and sets isSuccessful to true if knight can cover each cell of board. otherwise false
*/

bool KnightSolver::solveKnight(){
    if(moveDone==N*N){
        return true;
    }
    for(int i=0;i<8;i++){
        int r = R + row[i], c = C + col[i];
        if(canPlace(board, N, r, c)){
            board[r][c] = moveDone+1;
            R = r;
            C = c;
            if(solveKnight() == true) return true;
            board[r][c] = 0;
            R = r - row[i];
            C = c - col[i];
        }
    }
    return false;
}


/*
    canPlace
    ------------
    Checks if r and c lies on the boards and that they have not been covered up by knight before
*/

bool KnightSolver::canPlace(const vector <vector<int>> &board, int n, int r,int c) {
    if(r<0 || r>=n || c<0 || c>=n) return false;
    if(board[r][c]!=0) return false;
    return true;
}

#endif  // KNIGHT_HPP
