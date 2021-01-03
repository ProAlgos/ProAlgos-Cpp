/*
    Jump search
    -------------
    A searching algorithm that finds the index of a target value within a
    sorted array using fixed step jumps to skip elements.

    Time complexity
    ---------------
    O(sqrt(N)), where N is the number of elements in the array.

    Space complexity
    ----------------
    O(1).
*/

#ifndef PROALGOS_CPP_JUMP_SEARCH_HPP
#define PROALGOS_CPP_JUMP_SEARCH_HPP

#include <vector>
#include <cmath>
#include <cstdio>

/*
    jump_search
    -------------
    Returns the index where a given element is found in an ascending sorted array.
    If the element is not found, it returns -1.
*/

template <typename T>
int jump_search(const T& element, const std::vector<T>& values){
    int stepSize = (int) sqrt(values.size());
    int prevIndex = 0;

    for (int i = 0; i < (int) values.size(); i+=stepSize){
        if(values[i] >= element){
            for(int j = prevIndex; j <= i; j++){
                if(values[j] == element){
                    return j;
                }
            }
            return -1;
        }
        prevIndex = i;
    }
    return -1;
}

#endif //PROALGOS_CPP_JUMP_SEARCH_HPP
