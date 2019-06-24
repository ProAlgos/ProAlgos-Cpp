/*
    Counting sort (stable)
    ----------------------
    An integer sorting algorithm that operates by counting the number of objects
    that have each distinct key value, and using arithmetic on those counts to
    determine the positions of each key value in the output sequence.

    Time complexity
    ---------------
    O(N + R), where N is the number of elements and R is the range of input.

    Space complexity
    ----------------
    O(N + K), where N is the number of elements and K the size of the frequency array.
*/

#ifndef COUNTING_SORT_HPP
#define COUNTING_SORT_HPP

#include <vector>
#include "utils.hpp"

using std::vector;

void counting_sort(vector<int>& values, const int order = 1, const bool to_show_state = false) {
    int min_value = values[0];
    int max_value = values[0];

    // Find minimum and maximum values in input vector
    for (int value: values) {
        if (value < min_value) {
            min_value = value;
        }
        else if (value > max_value) {
            max_value = value;
        }
    }

    // Calculate unique values in input vector
    const int unique_values = max_value - min_value + 1;

    // Calculate frequencies of each unique value in input vector
    // freq[0] is number of min_value occurrences and so on
    vector<int> freq(unique_values, 0);
    for (int value: values) {
        ++freq[value - min_value];
    }

    // Start and end indices, for calculating cumulative frequency
    long start = 1;
    long end = freq.size();

    // If order is reversed, the indices are reversed too
    if (order == -1) {      // 'order' is -1 for descending, 1 for ascending
        start = freq.size() - 2;
        end = -1;
    }

    // Calculate cumulative frequency:
    // freq[i] will now be the number of elements in the sorted array that are
    // less than or equal to value[i]
    for (long i = start; i != end; i += order) {
        freq[i] += freq[i - order];
    }

    // Place values in sorted order by iterating input vector in reversed order,
    // to maintain sorting stability
    vector<int> sorted(values.size());
    int value;
    for (auto iter = values.rbegin(); iter != values.rend(); ++iter) {
        value = *iter;
        sorted[freq[value - min_value] - 1] = value;
        --freq[value - min_value];

        if (to_show_state) {
            display_state(sorted);
        }
    }

    values.assign(sorted.begin(), sorted.end());
}

#endif // COUNTING_SORT_HPP
