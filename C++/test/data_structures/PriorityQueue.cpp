/*
	Priority Queue
	--------------
	Implementing the priority queue using max-heap data structure
	Heap has two properties
	1. Structural property i.e structurally it is similar to complete binary tree
	2. Max(min)-heap property i.e Parent's priority is no smaller than children's priority or vice-versa.

	Time complexity
    ---------------
    O(log N) - for insert(), Where N is number of items
    O(log N) - for delmax() , Where N is number of items
    O(1) - for return_max() , constant amount of time
    
    Space complexity
    ----------------
    O(N) - Where N is number of items
*/

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <climits>

using namespace std;

std::vector<int> v; // vector to store the priorities with binary-max-heap property

void print() {

	if (v.size() == 1) 
		return ;

	cout << "Heap is - ";
	for (int i = 1; i < v.size(); ++i)
		 cout << v[i] << " ";
	cout << endl;
}

void heapify_up(int position) {
	/* Function to restore the max-heap property while inserting new priorities.
	   Variable "position" represent the position at which the heap property is violated */

	while (position > 1 && v[(position/2)] < v[position]) {

		swap(v[(position/2)], v[position]);
		position = position/2;
	}
}

void insert(int priority) {

	v.push_back(priority);
	heapify_up(v.size()-1);
}

int return_max() {
	/*Function to return the maximum priority*/

	if (v.size() == 1) 
		return -1;
	return v[1];
}

void heapify_down(int position) {
	/* Function to restore the max-heap property while deleting priorities.
	   Variable position represent the position at which the heap property is violated */

	while(2*position <= v.size()-1) {

		int child = 2*position;

		if(child < v.size()-1 && v[child] < v[child+1]) 
			child++;
		if(!(v[position] < v[child]))
			break;

		swap(v[position], v[child]);
		position = child;

	}
}

int delmax() {

	if (v.size() == 1) return -1;

	int max = v[1];
	swap(v[1], v[v.size()-1]);
	v.pop_back();
	heapify_down(1);
	
	return max;
}

int main()
{
	int choice, priority, max_priority, del_max_priority;
	v.push_back(INT_MIN); // indices start at 1 

	while(1){

		print();
		cout << "Enter your choice for following operations\
				 \n1. To insert in the priority queue\
				 \n2. To return the maximum priority \
				 \n3. To delete the maximum priority \
				 \n4. To exit\n";

		cin >> choice;

		if (choice == 1) {

			cout << "Enter the priority\n";
			cin >> priority;
			insert(priority);
		}

		else if (choice == 2) {
			
			max_priority = return_max();
			if (max_priority == -1)
				cout << "Heap is empty\n";
			else {

				cout << "The maximum priority  is: " << max_priority;
				cout << "\n";
			}
		}

		else if (choice == 3) {

			del_max_priority = delmax();
			if (del_max_priority == -1)
				cout << "Heap is empty\n";
			else{
					
				cout << "The deleted priority is: " << del_max_priority;
				cout << endl;
			}
		}

		else if (choice == 4)
			exit(0);

		else
			cout << "Invalid choice...Enter again\n";
				
	}


	return 0;
}