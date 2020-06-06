/*
    Stack
    -----
    A data structure which has the Last In First Out (LIFO) property. Elements are added
    and removed from the top (head). Only the top element can be accessed at any given time.
    Hence, there is no random access. All member functions have O(1) time complexity.
*/

#ifndef STACK_HPP
#define STACK_HPP

#include "data_structure/linked_list/singly_linked_list.hpp"

template<class T>
class Stack {
private:
    size_t size;
    Node<T>* head;
    
public:
    Stack();
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
Stack<T>::Stack() : size {0}, head {nullptr} {}

/*
 Adds an item to the top of the stack
*/
template<class T>
void Stack<T>::push(const T &item) {
    Node<T>* temp  = new Node<T>(item, head);
    head = temp;
    ++size;
}

/*
 Removes an item from the top of the stack
*/
template<class T>
void Stack<T>::pop() {
    Node<T>* temp = head;
    head = temp->get_next();
    temp->set_next(nullptr);
    delete temp;
    --size;
}

/*
 Returns the top element of the stack
*/
template<class T>
T Stack<T>::top() {
    return head->get_value();
}

/*
 Returns the size of the stack
*/
template<class T>
size_t Stack<T>::length() {
    return size;
}

/*
 Returns true if stack is empty
*/
template<class T>
bool Stack<T>::isEmpty() {
    return size == 0;
}

#endif /* STACK_HPP */
