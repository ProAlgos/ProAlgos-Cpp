/*
    Ternary search
    --------------
    A searching algorithm that finds the index of a maximum (or minimum) value
    within an unimodal array.

    Time complexity
    ---------------
    O(log(N)), where N is the number of elements in the array.

    Space complexity
    ----------------
    O(1).
*/

#ifndef TERNARY_SEARCH_HPP
#define TERNARY_SEARCH_HPP

#include <iostream>
#include <vector>
#include <functional>

enum Pattern {
    ASCEND_THEN_DESCEND,
    DESCEND_THEN_ASCEND
};


/*
    ternary_search
    --------------
    If the values in the given array first ascend and then descend, this
    function finds the index of the maximum value. Otherwise, if they first
    descend and then ascend, it finds the index of the minimum value.
*/

template <typename T>
size_t ternary_search(const std::vector<T>& values, const Pattern& pattern) {
    // left and right are the edges of the interval of search
    size_t left = 0;
    size_t right = values.size() - 1;

    bool changed = true;
    size_t mid1, mid2;
    while (right - left > 1 and changed) {  // if the interval is not shrinking,
                                            // its size already equals O(1)
        changed = false;
        mid1 = left + (right - left) / 3;
        mid2 = right - (right - left) / 3;
        if ((pattern and values[mid1] < values[mid2])
            or (!pattern and values[mid1] > values[mid2])) {
            changed |= (right != mid2);
            right = mid2;
        }
        else {
            changed |= (left != mid1);
            left = mid1;
        }
    }

    T min_value = values[left];
    T max_value = values[left];
    size_t min_index = left;
    size_t max_index = left;
    for (size_t index = left + 1; index <= right; index++) {
        if (min_value > values[index]) {
            min_value = values[index];
            min_index = index;
        }
        if (max_value < values[index]) {
            max_value = values[index];
            max_index = index;
        }
    }

    return pattern == ASCEND_THEN_DESCEND ? max_index : min_index;
}

/*
    ternary_search given a function and an integral interval
    --------------------------------------------------------
    If the given function f first ascends and then descends (pattern == ASCEND_THEN_DESCEND)
    , this function finds the integral value x for which f(x) is maximum on the interval [start, end].
    Otherwise, this function finds the integral value x for which f(x) is minimum on the interval [start, end].
*/

template <typename F, typename T,
          std::enable_if_t<std::is_integral<T>::value, int> = 0>
T ternary_search(F f, T start, T end, const Pattern& pattern) {
    T start_third, end_third;

    // Shrink the search range by a third of the size at every iteration until
    // the distance between start and end is below 3.
    while ((end - start) > 2) {
        // Compute the points at one third and two thirds of the distance from start and end
        start_third = start + (end - start) / 3;
        end_third = end - (end - start) / 3;

        const bool end_bigger =  f(start_third) < f(end_third);
        // If the function is ascending then descending then if f(end_third) is bigger then f(start_third)
        // that means that the maximum of the function cannot be between start and start_third and thus
        // the search range can be reduced to start_third and end; if f(start_third) is bigger then the
        // that the maximum of the function cannot be between end_third and end and thus
        // the search range can be reduced to start and end_third
        // The behavior is reversed for a function descending and then ascending
        if ((ASCEND_THEN_DESCEND == pattern && end_bigger)
            || (DESCEND_THEN_ASCEND == pattern && !end_bigger)) {
            start = start_third;
        }
        else {
            end = end_third;
        }
    }

    // If start is equal to end, the extremum index was found
    if (start == end) {
        return start;
    }

    // Iterate through the shrank search range to find the extrema and their indexes
    auto max_value = f(end);
    auto min_value = f(end);
    T max_x = end;
    T min_x = end;
    for (T i = start; i < end ; ++i) {
        auto f_value = f(i);
        if (f_value > max_value) {
            max_value = f_value;
            max_x = i;
        }
        else if (min_value > f_value) {
            min_value = f_value;
            min_x = i;
        }
    }
    // If the function is ascending then descending, the maximum index should be returned otherwise the minimum index
    return pattern == ASCEND_THEN_DESCEND ? max_x : min_x;
}

/*
    ternary_search given a function and an floating point interval
    --------------------------------------------------------
    If the given function f first ascends and then descends (pattern == ASCEND_THEN_DESCEND)
    , this function finds the value x for which f(x) is maximum on the interval [start, end]
    with a tolerance of abs_precision (or when the algorithm stops converging). 
    Otherwise, this function finds the value x for which f(x) is minimum on the interval [start, end].
*/

template <typename F, typename T,
          std::enable_if_t<std::is_floating_point<T>::value, int> = 0>
T ternary_search(F f, T start, T end, const Pattern& pattern, const T abs_precision) {
    T start_third, end_third;
    bool changed = true;
    // Shrink the search range by a third of the size at every iteration until
    // the distance between start and end is below the desired_absolute precision
    // or the search range does not change anymore
    while (((end - start) > abs_precision) && changed) {
        // Compute the points at one third and two thirds of the distance from start and end
        start_third = start + (end - start) / 3.0;
        end_third = end - (end - start) / 3.0;

        const bool end_bigger =  f(start_third) < f(end_third);
        // If the function is ascending then descending then if f(end_third) is bigger then f(start_third)
        // that means that the maximum of the function cannot be between start and start_third and thus
        // the search range can be reduced to start_third and end; if f(start_third) is bigger then the
        // that the maximum of the function cannot be between end_third and end and thus
        // the search range can be reduced to start and end_third
        // The behavior is reversed for a function descending and then ascending
        if ((ASCEND_THEN_DESCEND == pattern && end_bigger)
            || (DESCEND_THEN_ASCEND == pattern && !end_bigger)) {
            changed = (start != start_third);
            start = start_third;
        }
        else {
            changed = (end != end_third);
            end = end_third;
        }
    }

    // returns the midpoint of the extrema index result range
    return (start + end) / 2.0;
}

#endif // TERNARY_SEARCH_HPP
