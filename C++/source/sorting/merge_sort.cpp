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

#include <iostream>
#include <vector>

#include "sorting/utils.hpp"

using namespace std;

void merge(vector<int>& values, const size_t start, const size_t end, const int order = 1) {
    size_t mid = (start + end) / 2;
    size_t index1 = start;
    size_t index2 = mid + 1;

    vector<int> temp_vect(end - start + 1);
    for (int& next_val: temp_vect) {
        if (index1 > mid)       // first part has ended, copy from the second part
            next_val = values[index2++];
        else if (index2 > end)  // second part has ended, copy from the first part
            next_val = values[index1++];
        else {          // copy the value that's next in order
            // 'order' is -1 for descending, so the inequality is reversed:
            if (order * values[index1] < order * values[index2])
                next_val = values[index1++];
            else
                next_val = values[index2++];
        }
    }

    size_t s = start;
    for (int sorted_value: temp_vect)
       values[s++] = sorted_value;
}

void merge_sort(vector<int>& values, const size_t start, const size_t end,
        const int order = 1, const bool to_show_state = false) {
    if (start < end) {
        size_t mid = (start + end) / 2;

        merge_sort(values, start, mid, order, to_show_state);
        merge_sort(values, mid + 1, end, order, to_show_state);

        merge(values, start, end, order);

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

    merge_sort(values, 0, size-1, order, to_show_state);

    cout << "\nThe values in " << order_text << " order are:\n";
    display_state(values);

    return 0;
}
