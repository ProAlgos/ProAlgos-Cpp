#include "ListInterface.h"

/*
<Author>: Tucker J. Polomik github.com/TheNergaL
<Name of algorithm>: Singly Linked-list
<Brief description>:
List comprised of nodes which hold a datum
and point to the next datum element in the list.
If there exists no next element, it points to null.\
If an array is populated with this style of Singly-linked-lists,
we create a HashMap with hashing function f(x) = x
Refer to interface file for function prototypes.

Time complexity:
Element search/access is O(n), element insertion/deletion O(1)

Space complexity:
O(n), where n is the number of nodes (read: elements) in a list*/

template <class T>
LinkedList<T>::LinkedList() {    //constructor
  head = nullptr;
  last = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList() {    //destructor
  Node<T>* tempnode = head;
  while(tempnode != nullptr) {
    tempnode = tempnode->nextnode;
    delete(head);
    head = tempnode;
  }
}

template <class T>
bool LinkedList<T>::isEmpty() {
  if (head == nullptr) { return true; }
  else { return false; }
}

template <class T>
int LinkedList<T>::list_size() const {
    if (head == nullptr) { return 0; }
  Node<T>* tempnode = head;
  int nodeWalk = 0;
    while (tempnode != nullptr) {
      nodeWalk += 1;
      tempnode = tempnode->nextnode;
  }
    return nodeWalk;
}

template <class T>
int LinkedList<T>::QUICK_list_size() const {
    return quickSize;
}

template <class T>
void LinkedList<T>::insertFront(T insertValue) {
    quickSize += 1;
    Node<T>* NODE;

    NODE->value = insertValue;

  if (head == nullptr) {
    head = NODE;
  }
  else {
    NODE->nextnode = head;
    head = NODE;
  }
}

template <class T>
void LinkedList<T>::insertBack(T insertValue) {
    quickSize += 1;
    Node<T>* NODE;
    NODE->value = insertValue;
    NODE->nextnode = nullptr;

    Node<T>* tempnode = head;

    if(tempnode != nullptr) {
        while (tempnode->nextnode != nullptr) {
            tempnode = tempnode->nextnode;
          }
          tempnode->nextnode = NODE;
        }
  else {
    head = NODE;
  }
}

template <class T>
bool LinkedList<T>::removeBack() {
    if (head == nullptr && last == nullptr) {
      return false;
}

    if (head == last) {
      delete(head);
      head = last = nullptr;
      return true;
  }

    else {
      Node<T>* tempnode = head;
      int count = 0;

    while (tempnode != nullptr) {
      count += 1;
      tempnode = tempnode->nextnode;
    }

    Node<T>* tempnode2 = head;

    for(int i = 0; i < count; ++i) {
      tempnode2 = tempnode2->nextnode;
    }
    delete(tempnode2->nextnode);
    last = tempnode2;
    last->nextnode = nullptr;

    quickSize -= 1;
    return true;
  }
}

template <class T>
bool LinkedList<T>::removeFront() {
  if (head == nullptr && last == nullptr) {
    return false;
  }
  else {
    Node<T>* tempnode;
    tempnode = head;
    head = head->nextnode;
    delete(tempnode);
    quickSize -= 1;
    return true;
  }
}

template <class T>
void LinkedList<T>::clear() {
  Node<T>* tempnode = head;
  while (tempnode != nullptr) {
    tempnode = tempnode->nextnode;
    head = tempnode;
    delete(tempnode);
  }
}

template <class T>
T& LinkedList<T>::peek() {
  return head->value;
}
