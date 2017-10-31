/*
    Shell sort
    ----------
    An in-place comparison sort which starts by sorting pairs of elements far
    apart from each other, then progressively reducing the gap between elements
    to be compared. The time complexity depends on the gap sequence, which is
    floor(N / 2^K) in this implementation.

    Time complexity
    ---------------
    O(N^2), where N is the nubmer of elements.

    Space complexity
    ----------------
    O(1).
*/

#include <iostream>
#include <vector>

#include "sorting/utils.hpp"

using namespace std;

void shell_sort(vector<int>& values, const int order = 1, const bool to_show_state = false) {
    int n = values.size();
    int temp;
    int i, j;

    // gap sequence is n/2, n/4, n/8, ..., 1
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = values[i];
            j = i;
            while (j >= gap and values[j - gap] * order > temp * order) {
                values[j] = values[j - gap];
                j -= gap;
            }
            values[j] = temp;

            if (to_show_state)
                display_state(values);
        }
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

    shell_sort(values, order, to_show_state);

    cout << "\nThe values in " << order_text << " order are:\n";
    display_state(values);

    return 0;
}
