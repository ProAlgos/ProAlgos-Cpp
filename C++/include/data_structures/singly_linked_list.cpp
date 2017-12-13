#include "include/data_structures/singly_linked_list.hpp"

template <class T>
Node<T>::Node(const T& value, const Node<T> *next) {
    this->value = value;
    this->next = next;
}

template <class T>    
Node<T>::Node(const Node& n) {
    this->value = n.value;
    this->next = n.next;
}

template <class T>
Node<T>& Node<T>::operator=(const Node<T> &rhs) {
     this->value = rhs.value;
     return *this;
}

template<class T>
~Node() {
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
Node *Node<T>::get_next(void) {
    return this->next;
}

template <class T>    
void set_next(const Node *next) {
    this->next = next;
}


template <class T>
class SinglyLinkedList{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;
template <class T>
SinglyLinkedList<T>::SinglyLinkedList() {
    size = 0;
    head = tail = nullptr;
}
    SinglyLinkedList(const SinglyLinkedList&);
    SinglyLinkedList& operator=(const SinglyLinkedList&);
    ~SinglyLinkedList();
    bool is_empty(void);
    int length(void) const;
    void insert_front(const T&);
    void insert_back(const T&);
    void delete_front(void);
    void delete_back(void);
    T& value_at(int);
    T& operator[](int);
    const T& operator[](int) const;
    void erase(int);
    void erase(int, int);
    void clear(void);
};

#endif
