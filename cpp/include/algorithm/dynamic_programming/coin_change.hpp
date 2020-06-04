/*
    Coin Change Algorithm
    ---------------------
    Given an unlimited amount of coins with different values, find the number of ways of making change for an given
    value using the coins.

    Time complexity
    ---------------
    O(M*N), where M is the number of coins with different values and N is the amount that we desired to change

    Space complexity
    ----------------
    O(M*N), where M is the number of coins with different values and N is the amount that we desired to change
*/

#ifndef COIN_CHANGE_HPP
#define COIN_CHANGE_HPP

#include <vector>

using std::vector;

int coin_change(const vector<int>& coin, int number_of_coins, int amount)
{
    if (number_of_coins == 0 && amount == 0) {
        return 1;
    } else if (number_of_coins == 0) {
        return 0;
    }

    int i, j;

    // Make a matrix of size (amount+1)*number_of_coins to tabulate the computed values
    // table[i][j] represents no.of ways in which an 'i' can be made with just j type of coins available
    vector<vector<int>> table (amount + 1, vector<int>(number_of_coins, 0));

    int current_in; // Stores the number of ways in which the amount can be changed including the current coin value
    int current_out; // Stores the number of ways in which the amount can be changed excluding the current coin value

    for (j = 0; j < number_of_coins; j++) {
        table[0][j] = 1;
    }

    // i represents the amount whose change is required
    // j represents the coin values available
    for (i = 1; i <= amount; i++) {
        for (j = 0; j < number_of_coins; j++) {
            // If the the value of current coin is less than or equal to total amount whose change is required
            // include this coin
            if (i >= coin[j]) {
                current_in = table[i - coin[j]][j];
            } else {
                current_in = 0;
            }


            if (j >= 1) {
                current_out = table[i][j - 1];
            } else {
                current_out = 0;
            }

            table[i][j] = current_in + current_out;
        }
    }

    return table[amount][number_of_coins - 1];
}

#endif // COIN_CHANGE_HPP
