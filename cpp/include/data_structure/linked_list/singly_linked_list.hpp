/*
    Singly linked list
    ------------------
    A linked list is a common data structure used to maintain a dynamic list of
    similar elements. The list is maintained so that each element points to the
    next element and stores some data. To improve performance, the head and
    tail elements are stored to keep a track of insertions and deletions.
*/

#ifndef SINGLY_LINKED_LIST_HPP
#define SINGLY_LINKED_LIST_HPP

#include <climits>

const int ERROR_VAL = INT_MIN;


/*
    ===========================================================================
    Node
    ===========================================================================
    Helper class for the nodes in the list.
*/

template<class T>
class Node {
    T value;
    Node<T>* next;
    Node(void);

public:
    Node(const T&, Node<T>* const);
    Node(const Node&);
    Node<T>& operator=(const Node<T>&);
    ~Node();
    T& get_value(void);
    void set_value(const T&);
    Node<T>* get_next(void);
    void set_next(Node<T>* const);

    // inline friend functions:
    friend bool operator==(const Node& lhs, const Node& rhs) {
        return lhs.value == rhs.value;
    }
    friend bool operator!=(const Node& lhs, const Node& rhs) {
        return !operator==(lhs, rhs);
    }
    friend bool operator>=(const Node& lhs, const Node& rhs) {
        return !operator<(lhs, rhs);
    }
    friend bool operator<=(const Node& lhs, const Node& rhs) {
        return !operator>(lhs, rhs);
    }
    friend bool operator>(const Node& lhs, const Node& rhs) {
        return lhs.value > rhs.value;
    }
    friend bool operator<(const Node& lhs, const Node& rhs) {
        return operator>(rhs,lhs);
    }
};


/*
    Constructor
    -----------
*/

template<class T>
Node<T>::Node(const T& value, Node<T>* const next) {
    this->value = value;
    this->next = next;
}


/*
    Copy constructor
    ----------------
*/

template<class T>
Node<T>::Node(const Node<T>& n) {
    this->value = n.value;
    this->next = n.next;
}


/*
    Assignment operator
    -------------------
    This copies the RHS (right-hand-side value) to 'this' instance
*/

template<class T>
Node<T>& Node<T>::operator=(const Node<T>& rhs) {
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
}

template<class T>
Node<T>* Node<T>::get_next(void) {
    return this->next;
}

template<class T>
void Node<T>::set_next(Node<T>* const next) {
    this->next = next;
}


/*
    ===========================================================================
    SinglyLinkedList
    ===========================================================================
*/

template<class T>
class SinglyLinkedList {
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    SinglyLinkedList();
    ~SinglyLinkedList();
    bool is_empty(void);
    int length(void) const;
    void insert_front(const T&);
    void insert_rear(const T&);
    void delete_front(void);
    void delete_rear(void);
    T value_at(int);
    T operator[](int);
    const T operator[](int) const;
    void clear(void);
};


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
    is_empty
    --------
    Returns true if the list is empty
*/

template<class T>
bool SinglyLinkedList<T>::is_empty(void) {
    return size == 0;
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
    Node<T>* temp = new Node<T>(value, head);
    if (head == nullptr)
        tail = temp;

    head = temp;
    size++;
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
    Node<T>* temp = new Node<T>(value, nullptr);
    if (tail == nullptr)
        head = temp;
    else
        tail->set_next(temp);

    tail = temp;
    ++size;
}

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
    Node<T>* temp = head;
    if (temp == nullptr)
        return;

    head = head->get_next();
    delete temp;
    --size;
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
    Node<T>* temp = head;
    if (temp == nullptr)
        return;
    if (temp == tail) {
        delete temp;
        head = tail = nullptr;
        --size;
        return;
    }

    while (temp->get_next() != tail)
        temp = temp->get_next();
    tail = temp;
    temp = temp->get_next();
    delete temp;
    tail->set_next(nullptr);
    --size;
}

/*
    value_at
    --------
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
    if (size == 0 or index > size)
        return ERROR_VAL;

    Node<T>* temp = head;
    int i = 0;
    while (i++ != index)
        temp = temp->get_next();

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


/*
    clear
    -----
    This is used to empty the list and remove all the elements.
*/

template<class T>
void SinglyLinkedList<T>::clear(void) {
    Node<T>* temp = head;
    while (temp != nullptr) {
        temp = temp->get_next();
        delete head;
        head = temp;
    }
    head = tail = nullptr;
    size = 0;
}

#endif  // SINGLY_LINKED_LIST_HPP
