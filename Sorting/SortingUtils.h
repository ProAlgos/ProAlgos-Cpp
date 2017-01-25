/*
    Various utility functions (for input, output etc.)
    used in programs that implement sorting algorithms
*/

#ifndef IOSTREAM_H
#include <iostream>
#endif

#ifndef VECTOR_H
#include <vector>
#include <cstdlib>

#endif
#define EXIT_CODE_ERROR -1
using namespace std;

// Input utils:

void getInputSize(size_t& size) {
    cout << "Enter the input size : ";
    cin >> size;
    if(size <0) {
        cout << "Invalid input size! Try again.\n";
        getInputSize(size);
    }else if(size == 0) {
        cout << "There is nothing to sort here\n";
        exit(EXIT_CODE_ERROR );
    }
}

void getInputValues(vector<int>& values, const size_t& size) {
    cout << "Enter " << size << " integers :\n";
    for (int& val: values)
        cin >> val;
    cin.ignore();
}

void getOrder(int& order, string& orderText ) {
    cout << "In which order should the values be sorted?\n";
    cout << "[A]scending / [d]escending : ";
    getline(cin, orderText);

    if (orderText[0] == 'd' or orderText[0] == 'D') {
        order = -1;
        orderText = "descending";
    }
    else {    // ascending order by default
        order = 1;
        orderText = "ascending";
    }
}

void getWhetherToShowState(bool& toShowState) {
    string answer;
    cout << "Would you like to view the state of the values after each iteration?\n";
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
