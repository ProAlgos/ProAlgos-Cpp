/*
    Heap sort
    ---------
    A comparison-based sorting algorithm that uses an array-implemented heap to
    sort a list of integers.

    Time complexity
    ---------------
    O(N * log(N)), where N is the number of elements.

    Space complexity
    ----------------
    O(1).
*/

#ifndef HEAP_SORT_HPP
#define HEAP_SORT_HPP

#include <vector>
#include "utils.hpp"

using std::vector;

/*
    heapify
    -------
    Creates a max heap from a vector of integers.
*/
void heapify(vector<int>& heap, int parent, const int last) {
    int child = parent*2 + 1;
    while (child <= last) {    // travel down the children
        if (child + 1 <= last and heap[child + 1] > heap[child]) {
            child++;    // child is now the larger of its siblings
        }

        if (heap[parent] < heap[child]) {
            swap(heap[parent], heap[child]);    // if the parent is smaller, swap it with its child
        }

        parent = child;
        child = parent*2 + 1;
    }
}

/*
    sort
    ----
    Removes the largest element, replaces it with the last element, and calls
    heapify to recreate the max heap.
*/
void sort(vector<int> &heap, const int size, const bool to_show_state = false) {
    if (to_show_state) {
        cout << "\nPerforming heap sort on the heap...\n";
    }

    int last = size - 1;
    while (last >= 0) {
        swap(heap[0], heap[last]);
        last--;
        heapify(heap, 0, last);

        if (to_show_state) {
            display_state(heap);
        }
    }
}

/*
    make_heap
    ---------
    Makes an ordered heap by heapifying from highest indexed non-leaf node (curr_node)
    to the top node (heap[0]).
*/
void make_heap(vector<int>& heap, const int size, const bool to_show_state = false) {
    if (to_show_state)
        cout << "\nMaking initial heap...\n";

    for (int curr_node = size/2 - 1; curr_node >= 0; curr_node--) {
        heapify(heap, curr_node, size - 1);    //last_element = heap_size - 1

        if (to_show_state) {
            display_state(heap);
        }
    }

    if (to_show_state) {
        cout << "Initial heap has been made.\n";
    }
}

/*
    heap_sort
    ---------
    Combines the sorting and heapifying functionality into one function
*/
void heap_sort(vector<int>& values, const int order = 1, const bool to_show_state = false) {
    size_t size = values.size();
    make_heap(values, size, to_show_state);
    sort(values, size, to_show_state);

    // Reverse for descending, if necessary
    if (order == -1) {
        reverse(values.begin(), values.end());
    }
}

#endif // HEAP_SORT_HPP
