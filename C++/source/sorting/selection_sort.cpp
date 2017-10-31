/*
    Selection sort
    --------------
    A simple in-place comparision-based sorting algorithm.
    It sorts a list by finding the smallest / largest element (depending on the
    sorting order) from the unsorted sublist and swapping it with the leftmost
    unsorted element, moving the sublist boundary one element to the right.

    Time complexity
    ---------------
    O(N^2), where N is the number of elements.

    Space complexity
    ----------------
    O(1).
*/

#include <iostream>
#include <vector>

#include "sorting/utils.hpp"

using namespace std;

void selection_sort(vector<int>& values, const int order = 1, const bool to_show_state = false) {
    size_t current_extreme_index;   // index of either the current minimum or
                                    // maximum value, depending on the order
    size_t i, j;
    for (i = 0; i < values.size() - 1; i++) {
        current_extreme_index = i;
        j = i + 1;
        while (j < values.size()) {
            // 'order' is -1 for descending, so the inequality is reversed:
            if (order * values[j] < order * values[current_extreme_index])
                current_extreme_index = j;
            j++;
        }
        swap(values[i], values[current_extreme_index]);

        if (to_show_state)
            display_state(values);
    }
}

int main() {
    size_t size;
    get_input_size(size);

    vector<int> values(size);
    get_input_values(values, size);

    int order;
    string order_text;
    get_order(order, order_text);

    bool to_show_state;
    get_whether_to_show_state(to_show_state);

    selection_sort(values, order, to_show_state);

    cout << "\nThe values in " << order_text << " order are:\n";
    display_state(values);

    return 0;
}
