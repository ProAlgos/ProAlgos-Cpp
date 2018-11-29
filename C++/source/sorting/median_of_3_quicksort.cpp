#include <iostream>

// for size_t
#include <string>

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
void quicksort(T* arr, size_t beg, size_t end) {
    if (end - beg <= 1) {
        return;
    }

    size_t ctr = partition(arr, beg, end);

    quicksort(arr, beg, ctr);
    quicksort(arr, ctr, end);
}
