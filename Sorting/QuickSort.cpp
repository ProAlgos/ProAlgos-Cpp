/*
    Quicksort:
    An efficient, comparison-based, in-place, divide and conquer sorting algorithm
*/

#include <cstdlib>      // for rand(), srand()
#include <ctime>        // for time()
#include <iostream>
#include <vector>

#include "SortingUtils.h"

using namespace std;

size_t partition(vector<int>& values, const size_t start, const size_t end, const int order) {
    // choose a random index between start & end
    size_t randomIndex = start + (rand() % (end - start + 1));

    // swap the value there with the first value in given range
    swap(values[randomIndex], values[start]);

    // make that value the pivot element
    int pivot = values[start];

    size_t i = start + 1;
    for (size_t j = start + 1; j <= end; j++)  {
        /*
            place elements which are less than the pivot on one side,
            and those which are greater on the other
        */
        if (order * values[j] < order * pivot) {
            swap(values[i], values[j]);
            i++;
        }
    }

    // place the pivot in its proper place
    swap(values[start], values[i-1]);

    return i-1;     // pivot's index
}

void quickSort(vector<int>& values, const int start, const int end, const int order, const bool toShowState) {
    if (start < end) {
        size_t pivotIndex = partition(values, start, end, order);

        // sort values to the left of pivot
        quickSort(values, start, pivotIndex-1, order, toShowState);

        // sort values to the right of pivot
        quickSort(values, pivotIndex+1, end, order, toShowState);

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
    srand(time(0));     // seed PRNG
    quickSort(values, 0, size-1, order, toShowState);

    cout << "\nThe values in " << orderText << " order are :\n";
    displayState(values);

    return 0;
}
