/*
    Counting sort (stable):
    An integer sorting algorithm that operates by counting the number of objects
    that have each distinct key value, and using arithmetic on those counts
    to determine the positions of each key value in the output sequence.

    Time complexity is O(n + k), where n is the number of elements in the input
    array and k is the range of input.
*/

#include <iostream>
#include <vector>

#include "SortingUtils.h"

using namespace std;

void counting_sort(vector<int> &values, const int order, const bool to_show_state) {

    int min_value = values[0];
    int max_value = values[0];

    // find minimum and maximum values in input vector
    for (const int &value : values) {
        if (value < min_value)
            min_value = value;
        else if (value > max_value)
            max_value = value;
    }

    // calculate unique values in input vector
    const int unique_values = max_value - min_value + 1;

    // calculate frequencies of each unique value in input vector
    // freq[0] is number of min_value occurencies and so on
    vector<int> freq(unique_values, 0);
    for (const int &value : values) {
        ++freq[value - min_value];
    }

    // start and end indices, for calculating cumulative frequency
    int start = 1;
    int end = freq.size();

    // if order is reversed, the indices are reversed too
    if (order == -1) {      // 'order' is -1 for descending, 1 for ascending
        start = freq.size() - 2;
        end = -1;
    }

    // calculate cumulative frequency
    // freq[i] is now the number of elements in the sorted array that are <= i
    for (int i = start; i != end; i += order) {
        freq[i] += freq[i - order];
    }

    // place values in sorted order
    vector<int> sorted(values.size());
    for (const int &value : values) {
        sorted[freq[value - min_value] - 1] = value;
        --freq[value - min_value];

        if (to_show_state)
            displayState(sorted);
    }

    values.assign(sorted.begin(), sorted.end());
}

int main() {
    size_t size;
    getInputSize(size);

    vector<int> values(size);
    getInputValues(values, size);

    int order;
    string orderText;
    getOrder(order, orderText);

    bool toShowState;
    getWhetherToShowState(toShowState);

    cout << '\n';
    counting_sort(values, order, toShowState);

    cout << "\nThe values in " << orderText << " order are :\n";
    displayState(values);

    return 0;
}
