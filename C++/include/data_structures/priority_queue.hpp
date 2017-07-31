#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include <vector>

class PriorityQueue {
private:
    std::vector<int> values;
    void heapify_up(int);
    void heapify_down(int);

public:
    PriorityQueue();
    void insert(const int);
    int max();
    int remove();
};

#endif