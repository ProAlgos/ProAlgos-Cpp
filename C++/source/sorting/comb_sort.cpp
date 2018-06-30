/*
	Comb Sort by Cole Severson
	---------
	A sorting algorithm desinged to improve upon bubble sort by by eliminating small values        that start near the end of the list.

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

#include "sorting/utils.hpp"

void comb_sort(vector<int>& input, const int order = 1, const bool to_show_state = true){
	unsigned int gap = input.size();
	double shrink_factor = 1.3; //suggested as the optimal size
	bool sorted = false;

	while(!sorted){
		gap = (gap / shrink_factor); //This should automatically floor bc it is an int
		
		sorted = false;
		if(gap == 1 || gap == 0)
			sorted = true;

		for(int i = 0; i + gap < input.size(); i++){
			if(order * input[i] > order * input[i+gap]){
				swap(input[i], input[i+gap]);
				sorted = false;
			}
		
			if(to_show_state)
				display_state(input);
		}
		
	}
	
}

int main() {
	size_t size;
	get_input_size(size);

	vector<int> input(size);
	get_input_values(input, size);
	
	int order;
	string order_text;
	get_order(order, order_text);

	bool to_show_state;
	get_whether_to_show_state(to_show_state);

	comb_sort(input, order, to_show_state);

	std::cout<< "\nThe values in " << order_text << " order are:\n";
	display_state(input);

	return 0;
}
