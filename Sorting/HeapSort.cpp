/*
    Heap Sort :
    Uses an array-implemented heap to sort a list of integers.
    This is a comparison based sorting algorithm which separates the input into a
    sorted and unsorted region and iteratively shrinks the unsorted region by taking
    the maximum(or minimum if descending order) element and moving it to the sorted region.
    It uses the heap data structure (implemented using a vector here) to find the maximum or minimum.

    Time complexity:
    O(N * log(N)), where N is the number of integers to be sorted.

    Space complexity:
    O(1).
*/
#include <iostream>
#include <vector>

#include "SortingUtils.h"

using namespace std;

//creates max heap when ascending and min heap when descending
void heapify(vector<int> &heap, int parent, const int size, const int order, const bool showState){
	int child = parent*2 + 1;
    while (child<size){    // travels down children
        if (showState) displayState(heap);

	    if ((order * heap[child]) < (order * heap[child+1]) and (child+1 < size)){
	    	child++;	// child is now the larger of the parent's children
                        // or the smaller if the the order is descending
	    }
	    if ((order * heap[parent]) < (order * heap[child])){
	    	swap(heap[parent],heap[child]);
            // if the parent is smaller(order==ascending) or larger(order==descending), then swap
	    }

	parent = child;
	child = parent*2 + 1;

	if (showState) displayState(heap);
	}
}
//removes largest/smallest node, replaces it and reheapifies with new heap.
void heapsort(vector<int> &heap, const int size, const int order, const bool showState){
	int last = size;

	while (last > 0){
	    swap(heap[0], heap[last-1]);
	    last--;
	    heapify(heap,0,last, order, showState);
	}
}
//Makes ordered heap by "heapify"ing from highest indexed non-leaf node(curr_node) to the top node, index[0]
void make_heap(vector<int> &heap, const int size, const int order, const bool showState){
	for (int curr_node = (size/2) - 1; curr_node >= 0;curr_node--){
	    heapify(heap, curr_node, size, order, showState);

	    if (showState) displayState(heap);
	}
}
int main(){
	size_t size;
	getInputSize(size);

	vector<int> values(size);
	getInputValues(values, size);

	int order;
	string orderText;
	getOrder(order, orderText);

	bool showState;
	getWhetherToShowState(showState);
	if (showState) cout << endl << "Showing stages of making heap" << endl;
	make_heap(values, size, order, showState);
	if (showState){
	    cout << "Initial heap has been made" << endl << endl;
	    cout <<"Now showing state during heapify operation" << endl;
	}

	heapsort(values, size, order, showState);

	cout << endl << "The result in " + orderText + " order is as follows : " << endl;
	displayState(values);

	return 0;
}
