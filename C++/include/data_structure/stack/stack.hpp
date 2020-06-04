/*
    Stack
    ------------------
    A data structure which has the Last In First Out (LIFO) property. Elements are added
    and removed from the top(head). Only the top element can be accessed at any given time.
    Hence, there is no random access. All member functions have O(1) time complexity.
*/
#ifndef stack_h
#define stack_h

#include "data_structure/linked_list/singly_linked_list.hpp"
#include <iostream>

template<class T>
class Stack {
private:
    int size;
    Node<T> * head;
    
public:
    Stack();
    void push(const T &item);
    void pop();
    T top();
    int length();
};

/*
    Constructor
    -----------
*/
template<class T>
Stack<T>::Stack() : size {0}, head {nullptr} {}

/*
    Adds item to the top of the stack
 */
template<class T>
void Stack<T>::push(const T &item) {
    Node<T> temp  = new Node<T>(item, head);
    head = temp;
    ++size;
}

/*
    Removes an item from the top of the stack
 */
template<class T>
void Stack<T>::pop() {
    if (!head) {
        std::cout << "Stack is empty\n";
        return;
    }
    Node<T> * temp = head;
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
    if (!head) {
        std::cout << "Stack is empty\n";
//        exit(1);
    }
    return head->get_value();
}

/*
   Returns the size of the stack
*/
template<class T>
int Stack<T>::length() {
    return size;
}

#endif /* stack_h */
