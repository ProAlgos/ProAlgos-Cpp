#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include <climits>

const int ERROR_VAL = INT_MIN;

/*
    Node class
*/

template<class T>
struct Node {
    private:
        T value;
        Node<T> *prev, *next;
        Node(void);

    public:
        Node(const T value, Node<T> *const prev, Node<T> *const next) {
            this->value = value;
            this->prev = prev;
            this->next = next;
        }

        Node(const Node<T> &n) {
            this->value = n.value;
            this->prev = n.prev;
            this->next = n.next;
        }

        Node<T> operator=(const Node<T> &rhs) {
            this->value = rhs.value;
            this->prev = rhs.prev;
            this->next = rhs.next;
            return *this;
        }

        ~Node() {
            this->prev = nullptr;
            this->next = nullptr;
        }

        T get_value(void) {
            return this->value;
        }

        Node<T> *get_prev(void) {
            return this->prev;
        }

        void set_prev(Node<T> * const prev) {
            this->prev = prev;
        }

        Node<T> *get_next(void) {
            return this->next;
        }

        void set_next(Node<T> * const next) {
            this->next = next;
        }

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
    DoublyLinkedList class
    ----------------------
*/

template<class T>
class DoublyLinkedList {
    private:
        Node<T> *head;
        Node<T> *tail;
        int size;

    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
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

template<class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    size = 0;
    head = tail = nullptr;
}


template<class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}


/*
    is_empty
    --------
    Returns true if the list is empty
*/
template<class T>
bool DoublyLinkedList<T>::is_empty(void) {
    return size == 0;
}


/*
    size
    ----
    Returns the number of elements in this list
*/
template<class T>
int DoublyLinkedList<T>::length(void) const {
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
void DoublyLinkedList<T>::insert_front(const T& value) {
    Node<T> *temp = new Node<T>(value, nullptr, head);

    if (head == nullptr) {
        tail = temp;
    } else {
        head->set_prev(temp);
    }

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
void DoublyLinkedList<T>::insert_rear(const T& value) {
    Node<T> *temp = new Node<T>(value, tail, nullptr);
    if (tail == nullptr) {
        head = temp;
    } else {
        tail->set_next(temp);
    }

    tail = temp;
    ++size;
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
void DoublyLinkedList<T>::delete_front(void) {
    Node<T> *temp = head;
    if (temp == nullptr) {
        return;
    } else if (temp == tail) {
        head = tail = nullptr;
    } else {
        head = head->get_next();
        head->set_prev(nullptr);
    }

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
    O(1)

    Space complexity
    ----------------
    O(1).
*/
template<class T>
void DoublyLinkedList<T>::delete_rear(void) {
    Node<T> *temp = tail;
    if (temp == nullptr) {
        return;
    } else if (temp == head) {
        head = tail = nullptr;
    } else {
        tail = tail->get_prev();
        tail->set_next(nullptr);
    }

    delete temp;
    --size;
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
T DoublyLinkedList<T>::value_at(int index) {
    if (size == 0 or index > size)
        return ERROR_VAL;

    Node<T> *temp = head;
    int i = 0;
    while (i++ != index)
        temp = temp->get_next();

    return temp->get_value();
}

template<class T>
T DoublyLinkedList<T>::operator[](int index) {
    return value_at(index);
}

template<class T>
const T DoublyLinkedList<T>::operator[](int index) const {
    return value_at(index);
}


/*
    clear
    -----
    This is used to empty the list and remove all the elements.
*/

template<class T>
void DoublyLinkedList<T>::clear(void) {
    Node<T> *temp = head;
    
    while (temp != nullptr) {
        temp = temp->get_next();
        delete head;
        head = temp;
    }

    head = tail = nullptr;
    size = 0;
}

#endif  // DOUBLY_LINKED_LIST_HPP
