/*
    Various utility functions (for input, output etc.)
    used in programs that implement sorting algorithms
*/

#include <cstdlib>
#include <iostream>
#include <vector>

#define EXIT_INPUT_SIZE_IS_ZERO 2    // exit code for when input size is 0

using namespace std;

// Input utils:

void getInputSize(size_t& size) {
    cout << "Enter the input size : ";
    cin >> size;

    if ((int) size < 0) {
        cout << "Invalid input size! Try again.\n";
        getInputSize(size);
    } else if (size == 0) {
        cout << "Nothing to sort here.\n";
        exit(EXIT_INPUT_SIZE_IS_ZERO);
    }
}

void getInputValues(vector<int>& values, const size_t& size) {
    cout << "\nEnter " << size << " integers :\n";
    for (int& val: values)
        cin >> val;
    cin.ignore();
}

void getOrder(int& order, string& orderText ) {
    cout << "\nSorting order?\n";
    cout << "[A]scending / [d]escending : ";
    getline(cin, orderText);

    if (orderText[0] == 'd' or orderText[0] == 'D') {
        order = -1;
        orderText = "descending";
    } else {    // ascending order by default
        order = 1;
        orderText = "ascending";
    }
}

void getWhetherToShowState(bool& toShowState) {
    string answer;
    cout << "\nShow state of values after each iteration?\n";
    cout << "[y]es / [N]o : ";
    getline(cin, answer);

    toShowState = false;        // by default, don't show state
    if (answer[0] == 'y' or answer[0] == 'Y')    // unless user asks for it
        toShowState = true;
}

// Output utils:

void displayState(const vector<int>& values) {
    for (const int& val: values)
        cout << val << ' ';
    cout << '\n';
}

// Other utils:

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
