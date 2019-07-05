/*
    Ternary search
    --------------
    A searching algorithm that finds the index of a maximum (or minimum) value
    within an unimodal array.

    Time complexity
    ---------------
    O(log(N)), where N is the number of elements in the array.

    Space complexity
    ----------------
    O(1).
*/

#ifndef TERNARY_SEARCH_HPP
#define TERNARY_SEARCH_HPP

#include <iostream>
#include <vector>

enum Pattern {
    ASCEND_THEN_DESCEND,
    DESCEND_THEN_ASCEND
};


/*
    ternary_search
    --------------
    If the values in the given array first ascend and then descend, this
    function finds the index of the maximum value. Otherwise, if they first
    descend and then ascend, it finds the index of the minimum value.
*/

template <typename T>
size_t ternary_search(const std::vector<T>& values, const Pattern& pattern) {
    // left and right are the edges of the interval of search
    size_t left = 0;
    size_t right = values.size() - 1;

    bool changed = true;
    size_t mid1, mid2;
    while (right - left > 1 and changed) {  // if the interval is not shrinking,
                                            // its size already equals O(1)
        changed = false;
        mid1 = left + (right - left) / 3;
        mid2 = right - (right - left) / 3;
        if ((pattern and values[mid1] < values[mid2])
            or (!pattern and values[mid1] > values[mid2])) {
            changed |= (right != mid2);
            right = mid2;
        }
        else {
            changed |= (left != mid1);
            left = mid1;
        }
    }

    T min_value = values[left];
    T max_value = values[left];
    size_t min_index = left;
    size_t max_index = left;
    for (size_t index = left + 1; index <= right; index++) {
        if (min_value > values[index]) {
            min_value = values[index];
            min_index = index;
        }
        if (max_value < values[index]) {
            max_value = values[index];
            max_index = index;
        }
    }

    return pattern == ASCEND_THEN_DESCEND ? max_index : min_index;
}

#endif // TERNARY_SEARCH_HPP
