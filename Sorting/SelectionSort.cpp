/*
    Selection sort:
    A simple in-place comparision sorting algorithm
*/

#include <algorithm>    // for swap()
#include <iostream>
#include <vector>

using namespace std;

void displayState(const vector<int>& valuesVect) {
    for (const int& value: valuesVect)
        cout << value << ' ';
    cout << '\n';
}

void insertionSort(vector<int>& values, const int order, const bool askedToViewState) {
    size_t i, j;
    size_t currentExtremeIndex;   // index of either the current minimum or maximum value, depending on the order

    for (i = 0; i < values.size() - 1; i++) {
        currentExtremeIndex = i;
        j = i + 1;
        while (j < values.size()) {
            if (order * values[j] < order * values[currentExtremeIndex])    // 'order' is -1 for descending, so the inequality is reversed
                currentExtremeIndex = j;
            j++;
        }
        swap(values[i], values[currentExtremeIndex]);

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
    insertionSort(inputVect, order, askedToViewState);

    cout << "\nThe values in " << orderInput << " order are :\n";
    for (const int& val: inputVect)
        cout << val << " ";
    cout << "\n";

    return 0;
}
