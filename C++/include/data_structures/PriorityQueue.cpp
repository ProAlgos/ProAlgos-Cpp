/*
	Priority Queue
	--------------
	Implementing the priority queue using max-heap data structure
	Heap has two properties
	1. Structural property i.e structurally it is similar to complete binary tree.
	2. Max-heap property i.e Parent's priority is no smaller than children's priority(can be equal).

	PRIORITY IS THE HIGHEST FOR THE LARGEST VALUE (PRIORITY IS ALWAYS GREATER THAN ZER0)
	-----------------------------------------------------------------------------------

	Time complexity
    ---------------
    O(log N) - for insert(), Where N is number of items in priority queue
    O(log N) - for remove() , Where N is number of items in priority queue
    O(1) - for max() , constant amount of time
    
    Space complexity
    ----------------
    O(N) - Where N is number of items in priority queue
*/
#include "PriorityQueue.hpp"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <climits>

using namespace std;

/*
    Constructor
*/
PriorityQueue::PriorityQueue() {
	v.push_back(INT_MIN); // indices of vector start at 1 
}

void PriorityQueue::heapify_up(int position) {
	/* Function to restore the max-heap property while inserting new priorities in the priority Queue.
	   Variable "position" represent the position at which the heap property is violated */

	while (position > 1 && v[(position/2)] < v[position]) {

		swap(v[(position/2)], v[position]);
		position = position/2;
	}
}

void PriorityQueue::heapify_down(int position) {
	/* Function to restore the max-heap property while deleting priorities from the priority queue.
	   Variable position represent the position at which the heap property is violated */

	while(2*position <= static_cast<int>(v.size())-1) { // static_case<int> used to typecaste v.size() to return signed int value

		int child = 2*position;

		if(child < static_cast<int>(v.size())-1 && v[child] < v[child+1]) 
			child++;
		if(!(v[position] < v[child]))
			break;

		swap(v[position], v[child]);
		position = child;

	}
}

/*
	insert()
	Fucntion inserting the priorities in Priority Queue with the heapify_up() function.

*/		 
void PriorityQueue::insert(int priority) {

	v.push_back(priority);
	heapify_up(v.size()-1);
}

int PriorityQueue::max() {
	/*Function to return the maximum priority*/

	if (v.size() == 1) 
		return -1; // return -1 if priority queue is empty
	return v[1];
}

int PriorityQueue::remove() {
	/*Function to return the maximum priority which is recently remove from the priority queue*/

	if (v.size() == 1) 
		return -1; // return -1 if priority queue is empty

	int max;
	max = v[1];
	swap(v[1], v[v.size()-1]);
	v.pop_back();
	heapify_down(1);
	
	return max; // maximum priority remove from the priority queue
}
