#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include <vector>

class PriorityQueue{
private:
	
	std::vector<int> v;
	void heapify_up(int);
	void heapify_down(int);

public:

	PriorityQueue();
	void insert(int);
	int max();
	int remove();

};

#endif