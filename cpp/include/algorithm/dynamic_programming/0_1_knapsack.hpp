/*
    0-1 Knapsack Problem
    --------------------
    Given weights and values of n items, put these items in a knapsack
    of a fixed capacity to get the maximum total value in the knapsack.

    Time complexity
    ---------------
    O(N*C), where N is the number of items and C is the capacity of the knapsack.

    Space complexity
    ----------------
    O(N*C), the variables same as time complexity.

    Author
    ------
    Manas Gupta (@heisenberg-2505)
*/

#ifndef KNAPSACK_0_1_HPP
#define KNAPSACK_0_1_HPP

#include <algorithm>
#include <vector>

using std::vector;
typedef long long LL;

LL knapsack (LL capacity, LL numberOfItems, vector<LL> weights, vector<LL> values) {
    vector<vector<LL>> maxItems (numberOfItems + 1, vector<LL> (capacity + 1));
    for (LL i = 0; i <= numberOfItems; i++) {
        for (LL j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0) { // Base case.
                maxItems[i][j] = 0;
            } else if (weights[i - 1] <= j) { // Two cases -  if the element is included and if its not.
                maxItems[i][j] = std::max (values[i - 1] + maxItems[i - 1][j - weights[i - 1]], maxItems[i - 1][j]);
            } else { // If the weight of the current element is greater than the maximum weight.
                maxItems[i][j] = maxItems[i - 1][j];
            }
        }
    }
    return maxItems[numberOfItems][capacity];
}

#endif // KNAPSACK_0_1_HPP
