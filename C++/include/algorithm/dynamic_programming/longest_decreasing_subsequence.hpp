#ifndef LONGEST_DECREASING_SUBSEQUENCE
#define LONGEST_DECREASING_SUBSEQUENCE

/*
Longest Decreasing Subsequence
---------------------
This algorithm finds the longest decreasing  subsequence in a sequence of numbers
It follows the principals of dynamic programming

Time complexity
----------------
O(n logn) where n is the number of elements in the initial list

Space complexity
---------------
O(n)

*/

#include <iostream>
#include <vector>

int longest_decreasing_subsequence(std::vector<int>& input,  const bool to_show_state = true) {//order of 1 means increasing subsequence, -1 for decreasing subsequence
    int elements = input.size();//number of elements in the vector
	
	if (elements == 1 || elements == 0) {
		return elements;//base case
 	}
    int array[elements];//array to store the longest increasing subsequence at each location, this can then be used to backtrack and find what was the longest sequence
    int max = 0; //max represents current largest size 

    for (int i = 0; i < elements; i++) {
        array[i] = 1; //default value
    }
	for (int i = 1; i < elements; i++) {
		for (int j = 0; j < i; j++) {
			if ((input[j] - input[i] > 0) && array[i] < array[j] + 1) {//if the value is greater than or less than and that element in the array has more elements in its subsequence
				array[i]++;
            }
        }
    }
	for (int i = 0; i < elements; i++) {
		if (array[i] > max) {
			max = array[i];
        }
    }

	if (to_show_state) { //if this is true print out the subsequence
		std::vector<int> sub;//this vector will be populated with the ordered subsequence
		int counter = max;
		for (int i = elements - 1; i > -1; i--) {
			if (array[i] == counter)
				if (counter == max) {//the last value in the sequence will have the highest value
					sub.push_back(input.at(i));
					counter--;	
				}else if (input.at(i) - sub.at(sub.size() - 1)  > 0) {
					sub.push_back( input.at(i));
					counter--;
				}
		}	

		for (int i = max-1; i > -1; i--) {
            std::cout << sub.at(i) << ", ";
        }

	    std::cout << std::endl;
    }
	
	
	return max;  
}; 

#endif
