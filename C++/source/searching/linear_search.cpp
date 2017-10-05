/*
    Linear Search
    -------------
    A searching algorithm that finds the position of a target value
    within an array (sorted or otherwise).

    Time complexity
    --------------
    O(N), where N is the number of elements in the array

    Space Complexity
    --------------
    O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

size_t linear_search(const int value, const vector<int> &vect) {

    // Search all the elements in the array
    for(unsigned i = 0; i < vect.size(); i++) {
        // If the element at index i matches the target value
        // return the position i
        if(vect[i] == value) {
            return i + 1;
        }
    }

    // If no match is found, return -1
    return -1;
}

#ifndef LINEAR_SEARCH_TEST
int main() {
    int value;
    cout << "Enter the value to search for: ";
    cin >> value;

    int size;
    cout << "Enter the input size: ";
    cin >> size;

    vector<int> inputVect(size);
    cout << "Enter " << size << " integers: ";
    for(int& val: inputVect)
        cin >> val;

    int index = linear_search(value, inputVect);
    cout << "\n";
    if(index != -1)
        cout << "Found " << value << " at position " << index << "\n";
    else
        cout << value << " is not present among the input values\n";

    return 0;
}
#endif