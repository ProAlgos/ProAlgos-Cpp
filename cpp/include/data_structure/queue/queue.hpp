/*
    Queue
    -----
    A data structure which has the First In First Out (FIFO) property i.e. the
    first element to be added to the queue is also the first element to be
    removed. Elements are added at the back (tail) and removed from the
    front (head). Only the top element can be accessed at any given time. Hence,
    there is no random access. All member functions have O(1) time complexity.
*/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "data_structure/linked_list/singly_linked_list.hpp"

template<class T>
class Queue {
private:
    size_t size;
    Node<T>* head;
    Node<T>* tail;

public:
    Queue();
    void push(const T &item);
    void pop();
    T top();
    size_t length();
    bool isEmpty();
};

/*
    Constructor
    -----------
*/
template<class T>
Queue<T>::Queue() : size {0}, head {nullptr} {}

/*
 Adds an item to the end of the queue
*/
template<class T>
void Queue<T>::push(const T &item) {
    Node<T>* temp  = new Node<T>(item, head);
    if (tail)
      tail->set_next(temp);
    tail = temp;
    if (!head)
      head = tail;
    ++size;
}

/*
 Removes an item from the top of the queue
*/
template<class T>
void Queue<T>::pop() {
    Node<T>* temp = head;
    head = temp->get_next();
    temp->set_next(nullptr);
    if (!head)
      tail = nullptr;
    delete temp;
    --size;
}

/*
 Returns the top element of the queue
*/
template<class T>
T Queue<T>::top() {
    return head->get_value();
}

/*
 Returns the size of the queue
*/
template<class T>
size_t Queue<T>::length() {
    return size;
}

/*
 Returns true if queue is empty
*/
template<class T>
bool Queue<T>::isEmpty() {
    return size == 0;
}

#endif /* QUEUE_HPP */
