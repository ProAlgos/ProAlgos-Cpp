/*
    Kadane's Algorithm
    ------------------
    Used for finding the contiguous subarray within a one-dimensional array
    of integers which has the largest sum.

    Time complexity
    ---------------
    O(N), where N is the number of elements in the original array.

    Space complexity
    ----------------
    O(1)
*/

#ifndef KADANE_HPP
#define KADANE_HPP

#include <tuple>
#include <vector>

using std::tuple;
using std::make_tuple;
using std::vector;

/*
    maximum_subarray
    ---------------
    Takes an array of integers as an argument and computes the maximum sum that
    can be computed from any (contiguous) subarray of that array. Uses Kadane's
    Algorithm, which employs dynamic programming.

    Return value
    ------------
    tuple<int, size_t, size_t>, in which int is the maximum subarray value and
    size_t to size_t represents the indices of the passed subarray that sum to
    that value.
*/

#define kadane maximum_subarray

tuple<int, size_t, size_t> maximum_subarray(const vector<int> &values)
{
    int maxSum, currentSum;
    size_t nextStart, start, end;

    maxSum = currentSum = values[0];
    nextStart = start = end = 0;
    for (size_t i = 1; i < values.size(); i++) {
        currentSum += values[i];

        if (currentSum < values[i]) {
            currentSum = values[i];
            nextStart = i;
        }

        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = nextStart;
            end = i;
        }
    }

    return make_tuple(maxSum, start, end);
}

#endif // KADANE_HPP
