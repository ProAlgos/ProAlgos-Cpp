/*
    Insertion sort
    --------------
    A simple sorting algorithm that builds the final sorted list of value one item at a time.
    It is more efficient than most other quadratic-time algorithms.

    Time complexity
    ---------------
    O(N^2), where N is the number of elements.

    Space complexity
    ----------------
    O(1).
*/

#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include <vector>
#include "utils.hpp"

using std::vector;

/*
    Insertion sort
    --------------
    Builds a sorted list by finding elements based on their value and placing them in the sorted list.
*/
void insertion_sort(vector<int>& values, const int order = 1, const bool to_show_state = false) {
    size_t i, j;
    int currentValue;

    for (i = 1; i < values.size(); i++) {
        j = i;
        currentValue = values[j];

        // 'order' is -1 for descending, so the inequality is reversed:
        while (j > 0 && (order * values[j-1] > order * currentValue)) {
            values[j] = values[j-1];
            j--;
        }
        values[j] = currentValue;

        if (to_show_state) {
            display_state(values);
        }
    }
}

#endif // INSERTION_SORT_HPP
