/*
    Priority Queue
    --------------
    Implementing the priority queue using max-heap data structure
    Heap has two properties
    1. Structural property i.e structurally it is similar to complete binary tree.
    2. Max-heap property i.e Parent's priority is no smaller than children's priority(can be equal).

    PRIORITY IS THE HIGHEST FOR THE LARGEST VALUE (PRIORITY IS ALWAYS GREATER THAN ZER0)
    -----------------------------------------------------------------------------------
*/

#include "priority_queue.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>

using namespace std;

/*
    Constructor
*/
PriorityQueue::PriorityQueue() {
    values.push_back(INT_MIN); // indices of vector start at 1 
}

/*  heapify_up
    ----------
    Function to restore the max-heap property while inserting new priorities in the priority Queue.
    Variable "position" represent the position at which the heap property is violated 
    
    Time complexity
    ---------------
    log(N), where N is the number of elements in priority queue.

    Space complexity
    ----------------
    O(N) - Where N is number of elements in priority queue
*/
void PriorityQueue::heapify_up(int position) {
    while (position > 1 and values[position / 2] < values[position]) {
        swap(values[position / 2], values[position]);
        position = position / 2;
    }
}

/*  heapify_down
    ------------

    Function to restore the max-heap property while deleting priorities from the priority queue.
    Variable position represent the position at which the heap property is violated 

    Time complexity
    ---------------
    log(N), where N is the number of elements in priority queue.

    Space complexity
    ----------------
    O(N) - Where N is number of elements in priority queue
*/

void PriorityQueue::heapify_down(int position) {
    while(2*position <= static_cast<int>(values.size())-1) {
        int child = 2*position;

        if(child < static_cast<int>(values.size())-1 and values[child] < values[child+1]) 
            child++;
        if(!(values[position] < values[child]))
            break;

        swap(values[position], values[child]);
        position = child;
    }
}

/*
    insert
    ------

    Fucntion inserting the priorities in Priority Queue with the heapify_up() function.
    Time complexity
    ---------------
    log(N), where N is the number of elements in priority queue.

    Space complexity
    ----------------
    O(N) - Where N is number of elements in priority queue

*/       
void PriorityQueue::insert(const int priority) {
    values.push_back(priority);
    heapify_up(values.size()-1);
}

/*
    max
    ---
    Function to return the maximum priority

    Time complexity
    ---------------
    log(1), constant amount of  time

    Space complexity
    ----------------
    O(1) - contstant amount of space
*/
int PriorityQueue::max() {
    if (values.size() == 1) 
        return -1; // return -1 if priority queue is empty
    return values[1];
}
/*
    remove
    ------
    Function to return the maximum priority which is recently remove from the priority queue.
    Time complexity
    ---------------
    log(N), where N is the number of elements in the priority queue.

    Space complexity
    ----------------
    O(N) - Where N is number of elements in priority queue
    */
int PriorityQueue::remove() {
    if (values.size() == 1) 
        return -1; // return -1 if priority queue is empty

    int max;
    max = values[1];
    swap(values[1], values[values.size()-1]);
    values.pop_back();
    heapify_down(1);
    
    return max; // maximum priority remove from the priority queue
}
