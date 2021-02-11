/*
    Optimal coin game strategy
    --------------------
   Given an array A of coins in size N, A = {c1, c2, ... , cN} and each ci in A is a coin with some greater than zero value.
   You and an opponent plays a turns based game where in each turn a player removes the first or last coin in A and put it in their pocket.
   The game ends when A is empty.
   Determine the maximal value that will be in your pocket after the game ends if you play the first turn and both you and your opponent plays optimaly

    Time complexity
    ---------------
    O(N*N), where N is the number of coins in A.

    Space complexity
    ----------------
    O(N*N), the variables same as time complexity.

    Author
    ------
    Ephi Frankel (@ephi)
*/

#ifndef OPTIMAL_COIN_GAME_SRATEGY_HPP
#define OPTIMAL_COIN_GAME_SRATEGY_HPP

#include <algorithm>
#include <vector>

using namespace std;
typedef long long LL;
class OptimalCoinGameSolver {
public:
    OptimalCoinGameSolver(vector<LL> coins) : arr(coins) 
    {
    }
    LL solve() {
        int n = arr.size();
        vector<vector<LL>> F(n, vector<LL>(n));
        for (int j = 0; j < n; ++j) {
            for (int i = j; i < n; ++i) {
                F[i][j] = 0;
            }
        }
        int i = 0, j = 0, cntr = 0;
        while (cntr < n) {
            F[i][j] = max(
                arr[i] + min(getValidCellValue(F, i + 2, j), getValidCellValue(F, i + 1, j - 1)),
                arr[j] + min(getValidCellValue(F, i, j - 2), getValidCellValue(F, i + 1, j - 1))
            );
            ++i;
            ++j;
            if (j == n) {
                ++cntr;
                i = 0;
                j = cntr;
            }
        }
        return F[0][n - 1];
    }
private:
    LL getValidCellValue(vector<vector<LL>>& F, int i ,int j) {
        int n = F.size();
        if (i >= n || i < 0 || j >= n || j < 0) return 0;
        return F[i][j];
    }
    vector<LL> arr;

};

#endif // OPTIMAL_COIN_GAME_SRATEGY_HPP
