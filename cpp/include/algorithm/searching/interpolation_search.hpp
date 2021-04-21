/*
    Interpolation Search
    -------------
    A similar algorithm to Binary Search. However, instead of always going for the middle element, 
    interpolation search may go to different locations according to the value of the key being searched.

    Time complexity
    ---------------
    O(log2(log2 n)): for the average case, 
    O(n) for the worst case (when items are distributed exponentially), 

    where n is the number of elements in the array.

    Space complexity
    ----------------
    O(1).
*/

#ifndef INTERPOLATION_SEARCH_HPP
#define INTERPOLATION_SEARCH_HPP

#include <vector>
/*
    interpolation_search
    -------------
    Firstly, the value of `pos` is calculated. it is the position where t
    he algorithm  will look for the value
    If it is a match, return the index and exit. 
    If the item is less than sorted_values[pos], calculate the probe position of the left sub-array. 
    Else calculate the same in the right sub-array.
    Repeat until a match is found or the sub-array reduces to zero. If so, return -1.
*/

template <typename T>
int interpolation_search(const T& value, const std::vector<T>& sorted_values) {
    // Find indexes of two corners
    int n = sorted_values.size();
    int l = 0, r = (n - 1);

    while (l <= r && value >= sorted_values[l] && value <= sorted_values[r]) {
        if (l == r) {
            if (sorted_values[l] == value) {
                return l;
            }
            return -1;          //since left and right are at the same index, and that index does not match with the value, it means the value does not exist.
        }

        // Probing the position
        int pos = l + (((double)(r - l) / (sorted_values[r] - sorted_values[l])) * (value - sorted_values[l]));        //uniform distribution kept in mind.

        if (sorted_values[pos] == value) {
            return pos;
        }

        if (sorted_values[pos] > value) {
            r = pos - 1;        //this means value is in left subarray
        } else {
            l = pos + 1;        //this means value is in right subarray
        }
    }
    return -1;                  // value not found
}

#endif // INTERPOLATION_SEARCH_HPP
