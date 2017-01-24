/*
    Quicksort:
    An efficient, comparison-based, in-place, divide and conquer sorting algorithm
*/

#include <algorithm>    // for swap()
#include <cstdlib>      // for rand(), srand()
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

void displayState(const vector<int>& valuesVect) {
    for (const int& value: valuesVect)
        cout << value << ' ';
    cout << '\n';
}

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

void quickSort(vector<int>& values, const int start, const int end, const int order, const bool askedToViewState) {
    if (start < end) {
        size_t pivotIndex = partition(values, start, end, order);

        // sort values to the left of pivot
        quickSort(values, start, pivotIndex-1, order, askedToViewState);

        // sort values to the right of pivot
        quickSort(values, pivotIndex+1, end, order, askedToViewState);

        if (askedToViewState)
            displayState(values);
    }
}

int main() {
    int size;
    cout << "Enter the input size : ";
    cin >> size;

    vector<int> inputVect(size);
    cout << "Enter " << size << " integers :\n";
    for (int& val: inputVect)
        cin >> val;
    cin.ignore();

    string orderInput;
    cout << "In which order should the values be sorted?\n[A]scending / [d]escending : ";
    getline(cin, orderInput);
    int order;
    if (orderInput[0] == 'd' or orderInput[0] == 'D') {
        order = -1;
        orderInput = "descending";
    }
    else {    // ascending order by default
        order = 1;
        orderInput = "ascending";
    }

    string answer;
    cout << "Would you like to view the state of the values after each iteration?\n[y]es / [N]o : ";
    getline(cin, answer);
    bool askedToViewState = false;        // by default, don't show state
    if (answer[0] == 'y' or answer[0] == 'Y')    // unless user asks for it
        askedToViewState = true;

    cout << '\n';
    srand(time(0));     // seed PRNG
    quickSort(inputVect, 0, size-1, order, askedToViewState);

    cout << "\nThe values in " << orderInput << " order are :\n";
    for (const int& val: inputVect)
        cout << val << " ";
    cout << "\n";

    return 0;
}
