/*
    Exponential search
    -------------
    It is a searching algorithm whose name arises as a result of the algorithm jumping elements 
    with steps equal to exponents of 2.
    
    Time complexity
    ---------------
    O(log(N)), where N is the number of elements in the array.

    Space complexity
    ----------------
    O(log(N)).
*/

#ifndef EXPONENTIAL_SEARCH_HPP
#define EXPONENTIAL_SEARCH_HPP

#include <vector>
#include <algorithm>

/*
    exponential_search
    -------------
    Exponential Search is a searching algorithm which is also known as finger search, it searches 
    for an element in a sorted array by jumping 2^i elements every iteration where i represents the value 
    of loop control variable, and then verifying if the search element is present between last jump and the current jump.
*/

template <typename T>
int exponential_search(const T& value, const std::vector<T>& sorted_values,
        const int low, const int high) {
    int mid = low + (high - low) / 2;

    if (value == sorted_values[mid])
        return mid;
    else if (low <= high) {
        if (value < sorted_values[mid]) {
            // value must be between indices low and mid-1, if exists
            return exponential_search(value, sorted_values, low, mid - 1);
        }
        else if (value > sorted_values[mid]) {
            // value must be between indices mid+1 and high, if exists
            return exponential_search(value, sorted_values, mid + 1, high);
        }
    }

    return -1;
}


template <typename T>
int exponential_search(const T& value, const std::vector<T>& sorted_values) {
    if (sorted_values.size() == 0)
        return -1;
    
    int i = 1;
    while (i < sorted_values.size() && sorted_values[i] <= value)
        i = i*2;
 
    //  Call exponential search for the found range.
    int n= sorted_values.size();
    return exponential_search(value, sorted_values, i/2, std::min(i, n-1));
}

#endif // EXPONENTIAL_SEARCH_HPP
