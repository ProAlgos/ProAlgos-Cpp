/*
    Linear Search
    -----------
    A searching algorithm that finds the position of a target value
    within an array.

    Time complexity
    ---------------
    Worst-case 	O(n)
    Best-case 	O(1)
    Average 	O(n)        where N is the number of elements in the array.

    Space complexity
    ----------------
    O(1).
*/
#include<iostream>

using namespace std;
// Linearly search x in arr[].  If x is present then return its
// location,  otherwise return -1
int linearSearch(int arr[], int n, int x)
{
    int i;
    for (i=0; i<n; i++)
        if (arr[i] == x)
         return i;
    return -1;
}

int main(){
     int value;
    cout << "Enter the value to search for : ";
    cin >> value;

    int size;
    cout << "Enter the input size : ";
    cin >> size;

    int inputArr[size];
    cout << "Enter " << size << " integers :\n";
    for (int i=0;i<size;i++)
        cin >> inputArr[i];

     int index = linearSearch(inputArr, size, value);
    cout << "\n";

    if (index != -1)
        cout << "Found " << value << " at position " << (index + 1) << "\n";
    else
        cout << value << " is not present among the input values\n";

    return 0;

}
