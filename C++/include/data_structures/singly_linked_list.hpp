#include <climits>
#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

#define ERROR_VAL INT_MIN

template <class T>
struct Node {
private:
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

    //Inline friend functions
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

template <class T>
class SinglyLinkedList{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    SinglyLinkedList();
    ~SinglyLinkedList();
    bool is_empty(void);
    int length(void) const;
    void insert_front(const T&);
    void insert_back(const T&);
    void delete_front(void);
    void delete_back(void);
    T value_at(int);
    T operator[](int);
    const T operator[](int) const;
    void clear(void);
};

#endif
