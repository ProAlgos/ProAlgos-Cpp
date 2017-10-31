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

#include <iostream>
#include <vector>

#include "sorting/utils.hpp"

using namespace std;

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

    insertion_sort(values, order, to_show_state);

    cout << "\nThe values in " << order_text << " order are:\n";
    display_state(values);

    return 0;
}
