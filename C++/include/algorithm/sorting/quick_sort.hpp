/*
    Quick sort
    ----------
    An efficient, comparison-based, in-place, divide and conquer sorting algorithm.
    It picks an element as pivot, partitions the given array around the picked
    pivot and then recursively calls itself on those partitions.

    Time complexity
    ---------------
    Absolute worst case: O(N^2)
    Expected worst case: O(N * log(N))
    where N is the number of elements.

    Space complexity
    ----------------
    O(1).
*/

#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include <cstdlib>      // rand(), srand()
#include <ctime>        // time()
#include <vector>
#include "utils.hpp"

using std::vector;

// Partition set based on pivot
size_t partition(vector<int>& values, const size_t start, const size_t end, const int order = 1) {
    // Choose a random index between start & end
    size_t random_index = start + (rand() % (end - start + 1));

    // Swap the value there with the first value in given range
    swap(values[random_index], values[start]);

    // Make that value the pivot element
    int pivot = values[start];

    size_t i = start + 1;
    for (size_t j = start + 1; j <= end; j++)  {
            // Place elements which are less than the pivot on one side,
            // and those which are greater on the other
        if (order * values[j] < order * pivot) {
            swap(values[i], values[j]);
            i++;
        }
    }

    // Place the pivot in its proper place
    swap(values[start], values[i-1]);

    return i-1;     // pivot's index
}

// Carry out quick sort algorithm
void quick_sort_internal(vector<int>& values, const int start, const int end, const int order = 1,
                const bool to_show_state = false) {
    if (start < end) {
        size_t pivot_index = partition(values, start, end, order);

        // Sort values to the left of pivot
        quick_sort_internal(values, start, pivot_index-1, order, to_show_state);

        // Sort values to the right of pivot
        quick_sort_internal(values, pivot_index+1, end, order, to_show_state);

        if (to_show_state) {
            display_state(values);
        }
    }
}

// Wrapper function
void quick_sort(vector<int>& values, const int order = 1, const bool to_show_state = false) {
    srand(time(0));     // seed PRNG
    size_t size = values.size();
    quick_sort_internal(values, 0, size - 1, order, to_show_state);
}

#endif // QUICK_SORT_HPP
