/*
    Various utility functions (for input, output etc.)
    used in programs that implement sorting algorithms
*/

#ifndef UTILS_HPP
#define UTILS_HPP

#include <algorithm>    // swap, min, max, reverse
#include <cstdlib>      // exit
#include <iostream>
#include <vector>

#define EXIT_INPUT_SIZE_IS_ZERO 2    // exit code for when input size is 0

using std::cin;
using std::cout;
using std::string;
using std::swap;
using std::vector;

/*
    Input utils
    -----------
    get_input_size
    get_input_values
    get_order
    get_whether_to_show_state
*/

void get_input_size(size_t& size) {
    cout << "Enter the input size : ";
    cin >> size;

    if ((int) size < 0) {
        cout << "Invalid input size! Try again.\n";
        get_input_size(size);
    } else if (size == 0) {
        cout << "Nothing to sort here.\n";
        exit(EXIT_INPUT_SIZE_IS_ZERO);
    }
}

void get_input_values(vector<int>& values, const size_t& size) {
    cout << "\nEnter " << size << " integers :\n";
    for (int& val: values)
        cin >> val;
    cin.ignore();
}

void get_order(int& order, string& orderText ) {
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

void get_whether_to_show_state(bool& toShowState) {
    string answer;
    cout << "\nShow state of values after each iteration?\n";
    cout << "[y]es / [N]o : ";
    getline(cin, answer);

    toShowState = false;        // by default, don't show state
    if (answer[0] == 'y' or answer[0] == 'Y')    // unless user asks for it
        toShowState = true;
}

/*
    Output utils
    ------------
    display_state
*/

void display_state(const vector<int>& values) {
    for (const int& val: values)
        cout << val << ' ';
    cout << '\n';
}

#endif // UTILS_HPP
