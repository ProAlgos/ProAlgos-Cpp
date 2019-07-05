/*
    Merge sort
    ----------
    An efficient, comparison-based, divide and conquer sorting algorithm.
    It divides input array into two halves, recursively calls itself for the two halves and
    then merges the two sorted halves.

    Time complexity
    ---------------
    O(N * log(N)), where N is the number of elements.

    Space complexity
    ----------------
    O(N), where N is the number of elements.
    This space is used for merging two halves of the array.
*/

#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <vector>
#include "utils.hpp"

using std::vector;

// Merge sorted halves
void merge(vector<int>& values, const size_t start, const size_t end, const int order = 1) {
    size_t mid = (start + end) / 2;
    size_t index1 = start;
    size_t index2 = mid + 1;

    vector<int> temp_vect(end - start + 1);
    for (int& next_val: temp_vect) {
        if (index1 > mid) {
            // First part has ended, copy from the second part
            next_val = values[index2++];
        }
        else if (index2 > end) {
            // Second part has ended, copy from the first part
            next_val = values[index1++];
        }
        else {
            // Copy the value that's next in order
            // 'order' is -1 for descending, so the inequality is reversed:
            if (order * values[index1] < order * values[index2]) {
                next_val = values[index1++];
            }
            else {
                next_val = values[index2++];
            }
        }
    }

    size_t s = start;
    for (int sorted_value: temp_vect)
        values[s++] = sorted_value;
}

// Carry out merge sort
void merge_sort_range(vector<int>& values, const size_t start, const size_t end,
                      const int order = 1, const bool to_show_state = false) {
    if (start < end) {
        size_t mid = (start + end) / 2;

        merge_sort_range(values, start, mid, order, to_show_state);
        merge_sort_range(values, mid + 1, end, order, to_show_state);

        merge(values, start, end, order);

        if (to_show_state) {
            display_state(values);
        }
    }
}

// Wrapper function
void merge_sort(vector<int>& values, const int order = 1, const bool to_show_state = false) {
    size_t size = values.size();
    merge_sort_range(values, 0, size - 1, order, to_show_state);
}

#endif // MERGE_SORT_HPP
