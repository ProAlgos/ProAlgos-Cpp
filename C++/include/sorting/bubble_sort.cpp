@@ - 0, 0 + 1, 51 @@
/*
	Bubble sort
	-----------
	A simple sorting algorithm that repeatedly compares pairs of adjacent
	elements and swaps their positions if they are in the wrong order.
	Also known as sinking sort.

	Time complexity
	---------------
	O(N^2), where N is the number of elements.

	Space complexity
	----------------
	O(1).
*/

#include "bubble_sort.h"
#include "utils.hpp"

static void BubbleSort::bubble_sort(vector<int>& values, const int order = 1, const bool to_show_state = false) {
	size_t size;
	get_input_size(size);

	get_input_values(values, size);

	string order_text;
	get_order(order, order_text);

	get_whether_to_show_state(to_show_state);

	bool swapped;
	size_t i, j;

	for (i = 0; i < values.size() - 1; i++) {
		swapped = false;
		for (j = 0; i + j < values.size() - 1; j++) {
			// 'order' is -1 for descending, so the inequality is reversed:
			if (order * values[j] > order * values[j + 1]) {
				swap(values[j], values[j + 1]);
				swapped = true;

				if (to_show_state)
					display_state(values);
			}
		}
		if (!swapped)
			break;
	}

	display_state(values);
}
