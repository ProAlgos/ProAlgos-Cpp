/*
 * Jump Search Algorithm
 * ---------------------
 * A searching algorithm that finds the position of a target value
 * within a sorted vector. Returns "-1" if the element is not found.
 *
 * Time complexity
 * ---------------
 * O(root(n))
 *
 * Space complexity
 * ----------------
 * O(1)
 */
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int jumpSearch(vector<int> sortedVector, int searchValue){

    int size = sortedVector.size();
    int jumpSize = sqrt(size);  //size to jump by
    int prev = 0;

    while(sortedVector[min(jumpSize, size)-1] < searchValue) {  //start at first jump, keep jumping until too high

        prev = jumpSize;
        jumpSize += sqrt(size);

        if(prev >= size){  //not in vector
            return -1;
        }
    }

    while(sortedVector[prev] < searchValue) {  //linear search

        prev++;

        if(prev == min(jumpSize, size)){
            return -1;
        }
    }

    if(sortedVector[prev] == searchValue){ //index found
        return prev;
    }

    return -1;
}


#ifndef JUMP_SEARCH_TEST
int main() {
    vector<int> arr {3, 4, 5, 7, 88, 113, 238, 294, 296, 300};
    int value;

    cout << "Value to find?"  << endl;
    
    cin >> value;

    cout << jumpSearch(arr, value);

}
#endif ///JUMP_SEARCH_TEST