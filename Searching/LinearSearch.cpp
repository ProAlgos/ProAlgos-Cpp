/* 
    Linear search:
    A search algorithm that walks sequentially through a list to find
    the position of a target value within a vector. 

    Time complexity: O(n), where n is the number of elements in the vector
    Space complexity: O(1), i.e. the algorithm does not require additional space
*/

#include <iostream>
#include <vector>

using namespace std;

int linearSearch(const int value, const vector<int>& searchVect) {
    
    for (unsigned int i = 0; i < searchVect.size(); i++) {
        if (searchVect.at(i) == value) {
            return i; // return the element in searchVect where value is found
        }
    }

    return -1; // return -1 because the value is not in searchVect
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
