/*
    Shell sort
    ----------
    An in-place comparison sort which starts by sorting pairs of elements far
    apart from each other, then progressively reducing the gap between elements
    to be compared. The time complexity depends on the gap sequence, which is
    floor(N / 2^K) in this implementation.

    Time complexity
    ---------------
    O(N^2), where N is the number of elements.

    Space complexity
    ----------------
    O(1).
*/

#ifndef SHELL_SORT_HPP
#define SHELL_SORT_HPP

#include <vector>
#include "utils.hpp"

using std::vector;

void shell_sort(vector<int>& values, const int order = 1, const bool to_show_state = false) {
    size_t size = values.size();

    // gap sequence is n/2, n/4, n/8, ..., 1
    for (size_t gap = size / 2; gap > 0; gap /= 2) {
        for (size_t i = gap; i < size; i++) {
            int temp = values[i];
            size_t j = i;
            while (j >= gap and values[j - gap] * order > temp * order) {
                values[j] = values[j - gap];
                j -= gap;
            }
            values[j] = temp;

            if (to_show_state) {
                display_state(values);
            }
        }
    }
}

#endif // SHELL_SORT_HPP
