#ifndef SINGLY_LINKED_LIST_HPP
#define SINGLY_LINKED_LIST_HPP

#include <climits>

const int ERROR_VAL = INT_MIN;


/*
    Node class
    ----------
    Helper class for the nodes in the list
*/

template<class T>
struct Node {
    T value;
    Node<T> *next;
    Node(void);

    public:
        Node(const T&, Node<T> * const);
        Node(const Node&);
        Node<T>& operator=(const Node<T> &);
        ~Node();
        T& get_value(void);
        void set_value(const T&);
        Node<T> *get_next(void);
        void set_next(Node<T> * const);

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
    SinglyLinkedList class
    ----------------------
*/

template<class T>
class SinglyLinkedList {
    Node<T> *head;
    Node<T> *tail;
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

#endif  // SINGLY_LINKED_LIST_HPP
