/*
    Bubble sort (also known as sinking sort):
    A simple sorting algorithm that repeatedly compares pairs of adjacent
    elements and swaps their positions if they are in the wrong order
*/

#include <iostream>
#include <vector>

#include "SortingUtils.h"

using namespace std;

void bubbleSort(vector<int>& values, const int order, const bool toShowState) {
    bool swapped;
    size_t i, j;

    for (i = 0; i < values.size() - 1; i++) {
        swapped = false;
        for (j = 0; i + j < values.size() - 1; j++) {
            // 'order' is -1 for descending, so the inequality is reversed:
            if (order * values[j] > order * values[j+1]) {
                swap(values[j], values[j+1]);
                swapped = true;

                if (toShowState)
                    displayState(values);
            }
        }
        if (!swapped)
            break;
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
    bubbleSort(values, order, toShowState);

    cout << "\nThe values in " << orderText << " order are :\n";
    displayState(values);

    return 0;
}
