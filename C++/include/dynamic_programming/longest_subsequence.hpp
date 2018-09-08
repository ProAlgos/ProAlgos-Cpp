#ifndef LONGEST_SUBSEQUENCE
#define LONGEST_SUBSEQUENCE

#include <iostream>
#include <vector>

#include <./utils.hpp>

int longest_subsequence(vector<int>& input, order = 1, const bool to_show_state = false) {//order of 1 means increasing subsequence, -1 for decreasing subsequence
    int elements = input.size();//number of elements in the vector
	
	if(elements == 1 || elements == 0) 
		return elements;//base case
 
    int array[elements];//array to store the longest increasing subsequence at each location, this can then be used to backtrack and find what was the longest sequence
    int max = 0; //max represents current largest size 

    for (int i = 0; i < elements; i++)
        array[i] = 1; //default value

	for(int i = 1; i < elements; i++)
		for(int j = 0; j < i; j++)
			if(((input[i] - input[j]) * order > 0) && array[i] < array[j]+1)//if the value is greater than or less than and that element in the array has more elements in its subsequence
				array[i] = array[i] + 1;

	for(int i = 0; i < elements; i++)
		if (array[i] > max)
			max = array[i];

	if(to_show_state) { //if this is true print out the subsequence

	}

	return max;  
}; 

#endif
