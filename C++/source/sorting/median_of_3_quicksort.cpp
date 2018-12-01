/*
    Quicksort (median-of-3 partitioning)
    ----------
    Same as quick_sort.cpp except using median-of-3 partitioning.
    Time complexity
    ---------------
    Worst case (extremely rare): O(N^2)
    General worst case: O(N * log(N))
    where N is the number of elements.
    Space complexity
    ----------------
    O(1).
*/

#include "sorting/utils.hpp"

template<class T>
void display_state(const T* values, size_t beg, size_t end) {
    // since we're passing by value, this works fine
    for (; beg < end; beg++) {
        std::cout << values[beg] << ' ';
    }
    std::cout << std::endl;
}

/**
 * Works on [beg, end).
 */
template<class T>
size_t partition(T* arr, size_t beg, size_t end) {
    // median-of-3 pivot
    // pivot is swapped to the end of arr
#define QUICKSORT_SWAP(arr0, i1, i2) T tmp = arr0[i1]; \
    arr0[i1] = arr0[i2]; \
    arr0[i2] = tmp

    size_t mid = (beg + end) / 2;
    if (arr[beg] > arr[mid]) {
        QUICKSORT_SWAP(arr, beg, mid);
    }
    if (arr[beg] > arr[end - 1]) {
        QUICKSORT_SWAP(arr, beg, end - 1);
    }
    if (arr[mid] < arr[end - 1]) {
        QUICKSORT_SWAP(arr, mid, end - 1);
    }

    size_t pivot = arr[end - 1];
    size_t i = beg - 1;
    size_t j = end;

    // Hoare partitioning scheme.
    // Does not handle repeated elements efficiently
    // just textbook partition (almost)
    while (true) {
        // this is the same as
        // do {i++;} while (arr[i] < pivot);
        while (arr[++i] < pivot) {}

        while (arr[--j] > pivot) {}

        if (i >= j) {
            // I like it like this. Often it is return j;
            return i;
        }

        QUICKSORT_SWAP(arr, i, j);
    }

#undef QUICKSORT_SWAP
}

/**
 * Easy way to call: quicksort(c_style_array, 0, length_of_array);
 */
template<class T>
void quicksort(T* arr, size_t beg, size_t end, bool to_show_state = false) {
    if (end - beg <= 1) {
        return;
    }

    size_t ctr = partition(arr, beg, end);

    quicksort(arr, beg, ctr, to_show_state);
    quicksort(arr, ctr, end, to_show_state);

    if (to_show_state) {
        std::cout << "[" << beg << ", " << end << "): ";
        display_state<T>(arr, beg, end);
    }
}

int main() {
    size_t size;
    get_input_size(size);

    int* values = new int[size];
    std::cout << "\nEnter " << size << " integers :\n";
    for (size_t i = 0; i < size; i++) {
        std::cin >> values[i];
    }
    std::cin.ignore();

    bool to_show_state;
    get_whether_to_show_state(to_show_state);

    quicksort<int>(values, 0, size, to_show_state);

    std::cout << "\nThe values are:" << std::endl;
    display_state<int>(values, 0, size);

    delete[] values;

    return 0;
}
