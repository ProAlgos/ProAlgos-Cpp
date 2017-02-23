/* 
    Linear search:
    A search algorithm that walks sequentially through a list to find
    the position of a target value within a vector. 

    Time complexity: O(N), where N is the number of elements in the vector
    Space complexity: O(1), i.e. the algorithm requires a constant amount of additional space
*/

#include <iostream>
#include <vector>

using namespace std;

int linearSearch(const int value, const vector<int>& searchVect) {
    
    for (size_t i = 0; i < searchVect.size(); i++) {
        if (searchVect.at(i) == value) {
            return i; // index at which the value is found
        }
    }

    return -1; // when the value is not found
}
    
int main() {
    int searchValue;
    cout << "Enter the value to search for : ";
    cin >> searchValue;

    int size;
    cout << "Enter the input size : ";
    cin >> size;

    vector<int> inputVect(size); // establish new vector, pass size to default constructor to allocate space

    cout << "Enter " << size << " integers : \n";
    for (int& val: inputVect)
        cin >> val;

    int index = linearSearch(searchValue, inputVect);
    cout << "\n";
    if (index != -1)
        cout << "Found " << searchValue << " at position " << (index + 1) << "\n";
    else
        cout << searchValue << " is not present among the input values.\n";

    return 0;
}       
