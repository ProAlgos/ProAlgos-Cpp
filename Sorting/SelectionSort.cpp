/*
    Selection sort:
    A simple in-place comparision sorting algorithm
*/

#include <iostream>
#include <vector>

#include "SortingUtils.h"

using namespace std;

void insertionSort(vector<int>& values, const int order, const bool toShowState) {
    size_t i, j;

    // index of either the current minimum or maximum value, depending on the order:
    size_t currentExtremeIndex;

    for (i = 0; i < values.size() - 1; i++) {
        currentExtremeIndex = i;
        j = i + 1;
        while (j < values.size()) {
            // 'order' is -1 for descending, so the inequality is reversed:
            if (order * values[j] < order * values[currentExtremeIndex])
                currentExtremeIndex = j;
            j++;
        }
        swap(values[i], values[currentExtremeIndex]);

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

    insertionSort(values, order, toShowState);

    cout << "\nThe values in " << orderText << " order are :\n";
    displayState(values);

    return 0;
}
