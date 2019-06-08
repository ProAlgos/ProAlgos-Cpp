/*
    Singly linked list
    ------------------
    A linked list is a common data structure used to maintain a dynamic list of
    similar elements. The list is maintained so that each element points to the
    next element and stores some data. To improve performance, the head and
    tail elements are stored to keep a track of insertions and deletions.

    Author
    ------
    Sarvesh P.
*/

#include "singly_linked_list.hpp"
#include <iostream>
#include <algorithm>


/*
    ==========================================================================
    Node class
    ==========================================================================
*/


/*
    Constructor
    -----------
*/

template<class T>
Node<T>::Node(const T& value, Node<T> * const next) {
    this->value = value;
    this->next = next;
}


/*
    Copy constructor
    ----------------
*/

template<class T>
Node<T>::Node(const Node<T> &n) {
    this->value = n.value;
    this->next = n.next;
}


/*
    Assignment operator
    -------------------
    This copies the RHS (right-hand-side value) to 'this' instance
*/

template<class T>
Node<T>& Node<T>::operator=(const Node<T> &rhs) {
     this->value = rhs.value;
     return *this;
}


/*
    Destructor
    ----------
*/

template<class T>
Node<T>::~Node() {
    this->next = nullptr;
}


/*
    Getters and setters
    -------------------
*/

template<class T>
T& Node<T>::get_value(void) {
    return this->value;
}

template<class T>
void Node<T>::set_value(const T& other) {
    this->value = other;
    return;
}

template<class T>
Node<T> * Node<T>::get_next(void) {
    return this->next;
}

template<class T>
void Node<T>::set_next(Node<T> * const next) {
    this->next = next;
    return;
}


/*
    ==========================================================================
    SinglyLinkedList class
    ==========================================================================
*/


/*
    Constructor
    -----------
*/

template<class T>
SinglyLinkedList<T>::SinglyLinkedList() {
    size = 0;
    head = tail = nullptr;
}


/*
    Destructor
    ----------
*/

template<class T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    clear();
}


/*
    Copy constructor
    ----------------
*/

template<class T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T> &list) {
    size = list.size;
    head = tail = nullptr;

    Node<T> * current_pointer = list.head;
    while (current_pointer != nullptr) {
        insert_rear(current_pointer->get_value());
        current_pointer = current_pointer->get_next();
    }    
}


/*
    Move constructor
    ----------------
    Uses move semantics introduced in C++ 11 and further
*/

template<class T>
SinglyLinkedList<T>::SinglyLinkedList(SinglyLinkedList<T> &&rvalue_list) {
    size = rvalue_list.size;
    head = rvalue_list.head;
    tail = rvalue_list.tail;

    rvalue_list.head = nullptr;
    rvalue_list.tail = nullptr;
}


/*
    Assignment operator
    -------------------
    Copies the rhs value to lhs
*/

template<class T>
SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(SinglyLinkedList<T> rhs) {
    std::swap(head,rhs.head);
    std::swap(tail,rhs.tail);
    std::swap(size,rhs.size);

    return *this;
}


/*
    is_empty
    --------
    Returns true if the list is empty
*/

template<class T>
bool SinglyLinkedList<T>::is_empty(void) const {
    return (size == 0);
}


/*
    size
    ----
    Returns the number of elements in this list
*/

template<class T>
int SinglyLinkedList<T>::length(void) const {
    return size;
}


/*
    =========
    Insertion
    =========
*/


/*
    insert_front
    ------------
    Inserts an element at the head of the list.

    Time complexity
    ---------------
    O(1).

    Space complexity
    ----------------
    O(1).
*/

template<class T>
void SinglyLinkedList<T>::insert_front(const T& value) {
    Node<T> * temp = new Node<T>(value, head);
    if (head == nullptr) {
        tail = temp;
    }
    head = temp;
    size++;
    return;
}


/*
    insert_rear
    -----------
    Inserts an element at the tail of the list.

    Time complexity
    ---------------
    O(1).

    Space complexity
    ----------------
    O(1).
*/

template<class T>
void SinglyLinkedList<T>::insert_rear(const T& value) {
    Node<T> * temp = new Node<T>(value, nullptr);
    if (tail == nullptr) {
        head = temp;
    }
    else {
        tail->set_next(temp);
    }
    tail = temp;
    ++size;
    return;
}


/*
    ========
    Deletion
    ========
*/


/*
    delete_front
    ------------
    Removes the element from at the head.

    Time complexity
    ---------------
    O(1).

    Space complexity
    ----------------
    O(1).
*/

template<class T>
void SinglyLinkedList<T>::delete_front(void) {
    Node<T> * temp = head;
    if (temp == nullptr) {
        return;
    }
    else {
        head = head->get_next();
        delete temp;
        --size;
        return;
    }
}


/*
    delete_rear
    ------------
    Removes the element from at the tail. To remove an element from the tail,
    the list needs to be iterated through since the second-last element is needed.

    Time complexity
    ---------------
    O(N), where N is the number of nodes in the list.

    Space complexity
    ----------------
    O(1).
*/

template<class T>
void SinglyLinkedList<T>::delete_rear(void) {
    Node<T> * temp = head;
    if (temp == nullptr) {
        return;
    }
    else if (temp == tail) {
        delete temp;
        head = tail = nullptr;
        --size;
        return;
    }
    else {
        while (temp->get_next() != tail)
            temp = temp->get_next();
        tail = temp;
        temp = temp->get_next();
        delete temp;
        tail->set_next(nullptr);
        --size;
        return;
    }
}

/*
    ========
    Indexing
    ========
    This is used to find the value of the element at a particular position in
    the list.

    Time complexity
    ---------------
    O(N), where N is the number of nodes in the list

    Space complexity
    ----------------
    O(1)
*/

template<class T>
T SinglyLinkedList<T>::value_at(int index) {
    if (size == 0 or index > size) {
        return ERROR_VAL;
    }
    else {
        Node<T> * temp = head;
        int i = 0;
        while (i++ != index) {
            temp = temp->get_next();
        }
        return temp->get_value();
    }
}

template<class T>
T SinglyLinkedList<T>::operator[](int index) {
    return value_at(index);
}

template<class T>
const T SinglyLinkedList<T>::operator[](int index) const {
    return value_at(index);
}


/*
    clear
    -----
    This is used to empty the list and remove all the elements.
*/

template<class T>
void SinglyLinkedList<T>::clear(void) {
    Node<T> * temp = head;
    while (temp != nullptr) {
        temp = temp->get_next();
        delete head;
        head = temp;
    }
    head = tail = nullptr;
    size = 0;
    return;
}

/*
    print
    -----
    Auxiliary function to print the linked list.
*/

template<class T>
void SinglyLinkedList<T>::print(void) {
    if (size <= 0) {
        std::cout << "Empty List";
    }
    else {
        Node<T> * current = head;
        while (current != nullptr) {
            std::cout << current->get_value() << " ";
            current = current->get_next();
        }
    }
    std::cout << '\n';
    return;
}

template<class T>
void SinglyLinkedList<T>::print(void) const {
    if (size <= 0) {
        std::cout << "Empty List";
    }
    else {
        Node<T> * current = head;
        while (current != nullptr) {
            std::cout << current->get_value() << " ";
            current = current->get_next();
        }
    }
    std::cout << '\n';
    return;
}

/*
    ==========
    Algorithms
    ==========
*/


/*
    reverse_list
    ------------
    Reverses a linked list in place, by changing pointers
    (iterative implementation)

    Time complexity
    ---------------
    O(N), where N is the number of nodes in the list

    Space complexity
    ----------------
    O(1)
*/

template<class T>
void SinglyLinkedList<T>::reverse_list(void) {
    if (head == tail) {
        //if linked list is null or has single element, nothing is to be done
        return;
    }
    else {
        Node<T> * new_tail = head;
        Node<T> * prev_pointer = nullptr;

        while (head != tail) {
            Node<T> * temp = head->get_next();

            head->set_next(prev_pointer);
            prev_pointer = head;
            head = temp;
        }
        head->set_next(prev_pointer);
        tail = new_tail;
        return;
    }
}

int main() {
    SinglyLinkedList<int> list;
    list.insert_front(4);
    list.insert_rear(7);
    list.insert_front(list.length());

    const SinglyLinkedList<int> list2 = list;
    SinglyLinkedList<int>list3 = list;

    list2.print();
    list.insert_rear(11);
    list3.reverse_list();
    list3.print();
    list.print();    

    return 0;
}