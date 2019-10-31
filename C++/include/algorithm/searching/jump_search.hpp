/*
    Jump search
    -------------
    A searching algorithm that finds the index of a target value within a
    sorted array by jumping ahead by fixed steps or skipping some elements in place of searching all elements.

    Time complexity
    ---------------
    O(√n), where N is the number of elements in the array.

    Space complexity
    ----------------
    O(1).
*/

#ifndef JUMP_SEARCH_HPP
#define JUMP_SEARCH_HPP

#include <vector>
#include <cmath>

/*
    jump_search
    -------------
    Jump Search is a searching algorithm for sorted arrays. 
    The basic idea is to check fewer elements (than linear search) 
    by jumping ahead by fixed steps or skipping some elements in 
    place of searching all elements
*/
using namespace std;
template <typename T>
int jump_search(const T& value, const std::vector<T>& sorted_values) {
    // block size
    int n=sorted_values.size();
    int step = std::sqrt(n); 
    int prev = 0; 
    while (sorted_values[min(step, n)-1] < value) 
    { 
        prev = step; 
        step += std::sqrt(n); 
        if (prev >= n) 
            return -1; 
    } 
    while (sorted_values[prev] < value) 
    { 
        prev++; 
        if (prev == min(step, n)) 
            return -1; 
    } 
    if (sorted_values[prev] == value) 
        return prev; 
  
    return -1; 
}


#endif // JUMP_SEARCH_HPP