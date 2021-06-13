/*
    Interpolation search
    --------------------
    Interpolation search is an improvement over binary search for
    instances where the values in a sorted array are uniformly distributed.

    Binary search always goes to the middle element whereas interpolation
    search may go to different positions according to the value of being
    searched. For example, if the value is closer to the last element,
    interpolation search is likely to start search towards the end of the
    array.

    Time complexity
    ---------------
    Average case: O(log2(log2(N)))
    Worst case: O(N) [when items are distributed exponentially]
    where N is the number of elements in the array.

    Space complexity
    ----------------
    O(1).
*/

#ifndef INTERPOLATION_SEARCH_HPP
#define INTERPOLATION_SEARCH_HPP

#include <vector>

/*
    interpolation_search
    --------------------
    In a loop, calculate the value of `pos` using the probe position formula:
    a. If it is a match, return the index.
    b. If `value` is less than `sorted_values[pos]`, calculate the probe
       position of the left sub-array. Otherwise calculate the same in the
       right sub-array.
    c. Repeat until a match is found or the sub-array reduces to zero. Return
       -1 if no match is found.
*/
template <typename T>
int interpolation_search(const T& value, const std::vector<T>& sorted_values) {
    int left = 0, right = sorted_values.size() - 1;

    while (left <= right and value >= sorted_values[left] and value <= sorted_values[right]) {
        if (left == right) {
            if (sorted_values[left] == value) {
                return left;
            }
            // value was not found, since `left` and `right` are the same index
            // and the value does not exist at that index
            return -1;
        }

        // calculate the probe position (assuming uniform distribution of values)
        float slope = (float)(sorted_values[right] - sorted_values[left]) / (right - left)
        int pos = left + (value - sorted_values[left]) / slope;

        if (sorted_values[pos] == value) {
            return pos;
        }
        else if (value < sorted_values[pos]) {
            right = pos - 1;    // value might be in the left subarray
        }
        else {
            left = pos + 1;     // value might be in the right subarray
        }
    }

    return -1;  // value was not found
}

#endif  // INTERPOLATION_SEARCH_HPP
