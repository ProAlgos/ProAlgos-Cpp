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
    Node *start, *temp;
    start = list.head;
    while(start != nullptr) {
        if(this->head == nullptr) {
            this->head = new Node(start);
        } else {
        
        }
    }
}
    
template<class T>
SinglyLinkedList& SinglyLinkedList<T>:operator=(const SinglyLinkedList& rhs) {
    //Copy-and-swap
}

template<class T>    
SinglyLinkedList<T>::~SinglyLinkedList() {
    clear();
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
    Node<T> *temp = new Node<T>(value, head);
    if(head == nullptr) {
        tail = temp;
    } 
    head = temp;
    size++;
}

template<class T>
void SinglyLinkedList<T>::insert_back(const T& value) {
    Node<T> *temp = new Node<T>(value, nullptr);
    if(tail == nullptr) {
        head = temp;
    } else {
        tail->set_next(temp);
    }
    tail = temp;
    ++size;
}
    
template<class T>
void SinglyLinkedList<T>::delete_front(void) {
    Node<T> *temp = head;
    if(temp == nullptr) return;
    head = head->get_next(); 
    delete temp;
    temp = nullptr;
    --size;    
}
    
template<class T>
void SinglyLinkedList<T>::delete_back(void) {
    Node<T> *temp = head;
    if(temp == nullptr) 
        return;
    if(temp == tail) {
        delete temp;
        head = tail = nullptr;
        --size;
    }
    while(temp->get_next() != tail) {
        temp = temp->get_next();
    }
    tail = temp;
    temp = temp->get_next();
    delete temp;
    temp = nullptr;
    tail->set_next(nullptr);
    --size;
}
    
template<class T>
T SinglyLinkedList<T>::value_at(int index) {
    int i;
    Node *temp = head;
    if((size == 0)||(index > size)) 
        return ERROR_VAL;
    for(i = 0; i != index; temp = temp->get_next(), ++i);
    return temp->get_value(); 
}
    
template<class T>
T SinglyLinkedList<T>::operator[](int index) {
    return value_at(index);
}
    
template<class T>
const T SinglyLinkedList<T>::operator[](int index) const {
    return value_at(index);
}
    
template<class T>
void SinglyLinkedList<T>::erase(int pos) {

}
    
template<class T>
void SinglyLinkedList<T>::erase(int from, int to) {

}
    
template<class T>
void SinglyLinkedList<T>::clear(void) {
    Node<T> *temp = head;
    while(temp != nullptr) {
        temp = temp->get_next();
        delete head;
        head = temp;
    }
    head = tail = nullptr;
}
