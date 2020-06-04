/*
	Comb Sort by Cole Severson
	---------
	A sorting algorithm designed to improve upon bubble sort by by eliminating small values that start near the end of
	the list.

	Time Complexity
	---------------
	O(N^2), worst case where N is the number of elements
	O(N^2/2^p), average case where p is the number of increments and N is the number of elements

	Space Complexity
	----------------
	O(1)
*/

#include <iostream>
#include <vector>

#include "./utils.hpp"

unsigned int get_next_gap(unsigned int gap) {
    double shrink_factor = 1.3; // approximation of optimal factor
    gap = floor(gap / shrink_factor);

    // Prevent gap from dropping below 1
    if (gap < 1) {
        gap = 1;
    }
    return gap;
}

void comb_sort (vector<int>& input, const int order = 1, const bool to_show_state = false) {
    unsigned int gap = input.size();
    bool swapped = true;

    // Continue while gap is larger than one or there was a swap on previous iteration
    while (gap > 1 || swapped) {
        gap = get_next_gap(gap);
        swapped = false;
        for (int i = 0; i + gap < input.size(); i++) {
            if (order * input[i] > order * input[i+gap]) {
                swap(input[i], input[i+gap]);
                swapped = true;
            }
            if (to_show_state) {
                display_state(input);
            }
        }
    }
}
