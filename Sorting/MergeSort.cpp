/*
    Merge sort:
    An efficient, comparison-based, divide and conquer sorting algorithm
*/

#include <iostream>
#include <vector>

#include "SortingUtils.h"

using namespace std;

void merge(vector<int>& values, const size_t start, const size_t end, const int order) {
    size_t mid = (start + end) / 2;
    size_t index1 = start;
    size_t index2 = mid + 1;

    vector<int> tempVect(end - start + 1);
    for (int& nextVal: tempVect) {
        if (index1 > mid)       // first part has ended, copy from the second part
            nextVal = values[index2++];
        else if (index2 > end)  // second part has ended, copy from the first part
            nextVal = values[index1++];
        else {          // copy the value that's next in order
            // 'order' is -1 for descending, so the inequality is reversed:
            if (order * values[index1] < order * values[index2])
                nextVal = values[index1++];
            else
                nextVal = values[index2++];
        }
    }

    size_t s = start;
    for (const int& sortedVal: tempVect)
       values[s++] = sortedVal;
}

void mergeSort(vector<int>& values, const size_t start, const size_t end, const int order, const bool toShowState) {
    if (start < end) {
        size_t mid = (start + end) / 2;

        mergeSort(values, start, mid, order, toShowState);
        mergeSort(values, mid+1, end, order, toShowState);

        merge(values, start, end, order);

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
    mergeSort(values, 0, size-1, order, toShowState);

    cout << "\nThe values in " << orderText << " order are :\n";
    displayState(values);

    return 0;
}
