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

#ifndef LINEAR_SEARCH_HPP
#define LINEAR_SEARCH_HPP

#include <vector>

/*
    linear_search
    -------------
    Returns the index where a given element is found in an array. If the
    element is not found, it returns -1.
*/

template <typename T>
int linear_search(const T& element, const std::vector<T>& values) {
    for (size_t i = 0; i < values.size(); i++)
        if (values[i] == element)   // it's a match!
            return i;       // return the index at which it was found

    return -1;  // no match is found
}

#endif // LINEAR_SEARCH_HPP
