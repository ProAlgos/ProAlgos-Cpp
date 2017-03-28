/*
    Author:
    Tucker J. Polomik (https://github.com/TheNergaL)
    Name of algorithm:
    Singly Linked-list
    Brief description:
    List comprised of nodes which hold a value
    and point to the next value element in the list.
    If there exists no next element, it points to null.
*/

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

template<class T>
struct Node
{
  T value;
  Node<T> *nextnode;
};

template<class T>
class LinkedList
{
        Node<T>* head;
        Node<T>* last;
        int size;

      public:
        LinkedList();
        ~LinkedList();
        bool isEmpty();
        int size() const;          //O(n) walk
        int size_quick() const;    //O(1)
        void insertFront(T insertValue);
        void insertBack(T insertValue);
        T& peek();
        bool removeFront();
        bool removeBack(T removeValue);
        void clear();
};

#endif
