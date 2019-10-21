/*
	Comb Sort by Cole Severson
	---------
	A sorting algorithm desinged to improve upon bubble sort by by eliminating small values that start near the end of 
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

void comb_sort (vector<int>& input, const int order = 1, const bool to_show_state = false) {
    unsigned int gap = input.size();
    double shrink_factor = 1.3; // suggested as the optimal size
    bool sorted = false;

    while (!sorted) {
        gap /= shrink_factor; // this should automatically floor bc it is an int
        sorted = false;
        if (gap == 1 || gap == 0) {
            sorted = true;
	}
			for (int i = 0; i + gap < input.size(); i++) {
				if (order * input[i] > order * input[i+gap]) {
					swap(input[i], input[i+gap]);
					sorted = false;
				}
				if (to_show_state) {
					display_state(input);
				}
			}
    }
}
