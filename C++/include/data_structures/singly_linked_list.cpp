#include "include/data_structures/singly_linked_list.hpp"

template <class T>
Node<T>::Node(const T& value, const Node<T> *next) {
    this->value = value;
    this->next = next;
}

template <class T>    
Node<T>::Node(const Node<T> &n) {
    this->value = n.value;
    this->next = n.next;
}

template <class T>
Node<T>& Node<T>::operator=(const Node<T> &rhs) {
     this->value = rhs.value;
     return *this;
}

template<class T>
Node<T>::~Node() {
    this->next = nullptr;
}

template <class T>    
T& Node<T>::get_value(void) {
    return this->value;
}

template <class T>    
void Node<T>::set_value(const T& other) {
    this->value = other;
}
    
template <class T>
Node<T> *Node<T>::get_next(void) {
    return this->next;
}

template <class T>    
void set_next(const Node<T> *next) {
    this->next = next;
}

template <class T>
SinglyLinkedList<T>::SinglyLinkedList() {
    size = 0;
    head = tail = nullptr;
}

template<class T>    
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList& list) {
    //Copy
}
    
template<class T>
SinglyLinkedList& SinglyLinkedList<T>:operator=(const SinglyLinkedList& rhs) {
    //Copy
}

template<class T>    
SinglyLinkedList<T>::~SinglyLinkedList() {
    //Iterate over the list and delete nodes
}

template<class T>    
bool SinglyLinkedList<T>::is_empty(void) {
    return size == 0;
}

template<class T>    
int SinglyLinkedList<T>::length(void) const {
    return size;
}
    
template<class T>
void SinglyLinkedList<T>::insert_front(const T& value) {
    //Assign value to temp
    //temp points to head
    //update head
}

template<class T>
void SinglyLinkedList<T>::insert_back(const T& value) {
}
    
template<class T>
void SinglyLinkedList<T>::delete_front(void) {

}
    
template<class T>
void SinglyLinkedList<T>::delete_back(void) {

}
    
template<class T>
T& SinglyLinkedList<T>::value_at(int index) {

}
    
template<class T>
T& SinglyLinkedList<T>::operator[](int index) {

}
    
template<class T>
const T& SinglyLinkedList<T>::operator[](int index) const {

}
    
template<class T>
void SinglyLinkedList<T>::erase(int pos) {

}
    
template<class T>
void SinglyLinkedList<T>::erase(int from, int to) {

}
    
template<class T>
void SinglyLinkedList<T>::clear(void) {
    //Iterate over list and delete elements
}
