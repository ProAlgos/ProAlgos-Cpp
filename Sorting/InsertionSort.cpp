/*
    Insertion sort:
    A simple sorting algorithm that builds the final sorted array (or list) one item at a time
*/

#include <iostream>
#include <vector>

using namespace std;

void displayState(const vector<int>& valuesVect) {
    for (const int& value: valuesVect)
        cout << value << ' ';
    cout << '\n';
}

void insertionSort(vector<int>& values, int order, bool askedToViewState) {
    size_t i, j;
    int currentValue;

    for (i = 1; i < values.size(); i++) {
        j = i;
        currentValue = values[j];

        while (j > 0 && (order * values[j-1] > order * currentValue)) {    // 'order' is -1 for descending, so the inequality is reversed
            values[j] = values[j-1];
            j--;
        }
        values[j] = currentValue;

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
