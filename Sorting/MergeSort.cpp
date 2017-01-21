/*
    Merge sort:
    An efficient, comparison-based, divide and conquer sorting algorithm
*/

#include <iostream>
#include <vector>

using namespace std;

void displayState(const vector<int>& valuesVect) {
    for (const int& value: valuesVect)
        cout << value << ' ';
    cout << '\n';
}

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

void mergeSort(vector<int>& values, const size_t start, const size_t end, const int order, const bool askedToViewState) {
    if (start < end) {
        size_t mid = (start + end) / 2;

        mergeSort(values, start, mid, order, askedToViewState);
        mergeSort(values, mid+1, end, order, askedToViewState);

        merge(values, start, end, order);

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
    mergeSort(inputVect, 0, size-1, order, askedToViewState);

    cout << "\nThe values in " << orderInput << " order are :\n";
    for (const int& val: inputVect)
        cout << val << " ";
    cout << "\n";

    return 0;
}
