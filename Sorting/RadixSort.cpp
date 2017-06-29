/*
    Radix sort
    ----------
    An efficient, key-index-based, comparision based sorting algorithm.
  	It sorts based on the keys obtained on each index of the numbers to be sorteed.

    Time complexity
    ---------------
    O(D * N), where N is the number of keys, D is the number of digits in input integers.

    Space complexity
    ----------------
    O(N), where N is the number of elements and B is the base for representing the numbers(10 in case of decimal system)
    This space is used for count sorting each key and temporarily creating a sorted array.
*/

#include <iostream>
#include <vector>
#include "SortingUtils.hpp"

using namespace std;

//No. of elements to be sorted
size_t SIZE;

//order is set to 1 if the sorting is done in ascending order, -1 if the sorting is done in descending order
int order;

//These factors depend on whether the sorting is needed to be done in ascending or descending order
int mult_factor = 1;
int add_factor = 0;

//The setFactors function sets the above factors
void setFactors() {
    if(order==-1) {
        mult_factor = -1;
        add_factor = 9;
    }
}

//This function performs count sort on digits extracted from the numbers based on the scaling factor
void count_sort(vector<int>& values, const size_t SIZE, int I, const int order, const bool to_show_state) {
	int counter[10] = {0};
	int* output = (int*)malloc(SIZE*sizeof(int));
	for(int i = 0; i < SIZE; i++)
		counter[add_factor + (mult_factor * ((values[i]/I) % 10))]++;
	for(int i = 1; i < 10; i++)
		counter[i] += counter[i - 1];
	for(int i = SIZE - 1; i >= 0; i--) {
		output[counter[add_factor + (mult_factor * ((values[i]/I) % 10))] - 1] = values[i];
		counter[add_factor + (mult_factor * ((values[i]/I) % 10))]--;
	}

	for(int i = 0; i < SIZE; i++)
		values[i] = output[i];

    if(to_show_state) {
        cout << "Printing the current state..." << endl;
        for (int i = 0; i < SIZE; i++) {
            cout << values[i] << "\t";
        }
        cout << endl;
    }
}

//This function returns the maximum value in the vector
int getMaxVal(vector<int> values, size_t SIZE) {
	int max_val = values[0];
	for (int i=1; i < SIZE; i++) {
		if (values[i] > max_val)
			max_val = values[i];
	}
	return max_val;
}

//The function implements radix sort by repeatedly calling count sort for different scaling factors.
void radix_sort(vector<int>& values, const size_t SIZE, const int order, const bool to_show_state) {
	int m = getMaxVal(values, SIZE);
	for (int i = 1; m/i > 0; i *= 10) {
		count_sort(values, SIZE, i, order, to_show_state);
	}
}

int main() {
	get_input_size(SIZE);

    vector<int> values(SIZE);
	get_input_values(values, SIZE);

	string order_text;
	get_order(order, order_text);

	bool to_show_state;
	get_whether_to_show_state(to_show_state);

    setFactors();
	radix_sort(values, SIZE, order, to_show_state);

	cout << "\nThe values in " << order_text << " order are:" << endl;
	display_state(values);

	return 0;
}
