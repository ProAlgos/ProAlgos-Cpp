/*
    Linear search
    -------------
    A searching algorithm that finds the position of a target value within an
    array (sorted or otherwise).

    Time complexity
    ---------------
    O(N), where N is the number of elements in the array.

    Space complexity
    ----------------
    O(1).
*/

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
int linear_search(const T element, const vector<T>& values) {
    for (size_t i = 0; i < values.size(); i++)
        if (values[i] == element)   // it's a match!
            return i;       // return the index at which it was found

    return -1;  // when no match is found
}

#ifndef LINEAR_SEARCH_TEST
int main() {
    int element;
    cout << "Enter the element to search for : ";
    cin >> element;

    size_t size;
    cout << "Enter the input size : ";
    cin >> size;

    vector<int> input_values(size);
    cout << "Enter " << size << " integers:\n";
    for (int& value: input_values)
        cin >> value;

    int index = linear_search(element, input_values);
    cout << "\n";
    if (index != -1)
        cout << "Found " << element << " at index " << index << ".\n";
    else
        cout << "Did not find " << element << " among the input values.\n";

    return 0;
}
#endif  // LINEAR_SEARCH_TEST
