/*
    Binary Search
    -----------
    A searching algorithm that finds the position of a target value
    within a sorted array.

    Time complexity
    ---------------
    O(log(N)), where N is the number of elements in the array.

    Space complexity
    ----------------
    O(1).
*/

#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const int value, const vector<int>& sortedVect, const int low, const int high) {
    int mid = (low + high) / 2;

    if (value == sortedVect[mid])
        return mid;
    else if (low <= high) {
        if (value < sortedVect[mid]) {
            // value must be between indices low and mid-1, if exists
            return binarySearch(value, sortedVect, low, mid-1);
        }
        else if (value > sortedVect[mid]) {
            // value must be between indices mid-1 and high, if exists
            return binarySearch(value, sortedVect, mid+1, high);
        }
    }

    return -1;
}

int main() {
    int value;
    cout << "Enter the value to search for : ";
    cin >> value;

    int size;
    cout << "Enter the input size : ";
    cin >> size;

    vector<int> inputVect(size);    // supposedly sorted values
    cout << "Enter " << size << " integers in ascending order :\n";
    for (int& val: inputVect)
        cin >> val;

    int index = binarySearch(value, inputVect, 0, size-1);
    cout << "\n";
    if (index != -1)
        cout << "Found " << value << " at position " << (index + 1) << "\n";
    else
        cout << "Either " << value << " is not present among the input values, or the values aren\'t sorted\n";

    return 0;
}
