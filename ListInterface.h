/*
<Author>: Tucker J. Polomik github.com/TheNergaL
<Name of algorithm>: Singly Linked-list
<Brief description>:
List comprised of nodes which hold a datum
and point to the next datum element in the list.
If there exists no next element, it points to null.\
If an array is populated with this style of Singly-linked-lists,
we create a HashMap with hashing function f(x) = x
Refer to LinkedList.cpp for time-space complexity.
*/

#ifndef LISTINTERFACE_H
#define LISTINTERFACE_H

template<class T>

struct Node
{
  T value;
  Node<T> *nextnode;
};

template<class T>
class LinkedList
{
      public:
        LinkedList();
        ~LinkedList();
        bool isEmpty();
        const int list_size();          //O(n) walk
        const int QUICK_list_size();    //O(1)
        void insertFront(T insertValue);
        void insertBack(T insertValue);
        T& peek();
        bool removeFront();
        bool removeBack(T removeValue);
        void clear();


      private:
        Node<T> *head;
        Node<T> *last;
        int quickSize;
};

#endif
