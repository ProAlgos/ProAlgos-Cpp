/*
    Insertion sort:
    A simple sorting algorithm that builds the final sorted array (or list)
    one item at a time
*/

#include <iostream>
#include <vector>

#include "SortingUtils.h"

using namespace std;

void insertionSort(vector<int>& values, const int order, const bool toShowState) {
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

        if (toShowState)
            displayState(values);
    }
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
    insertionSort(values, order, toShowState);

    cout << "\nThe values in " << orderText << " order are :\n";
    displayState(values);

    return 0;
}
