#include "ListInterface.hpp"

/*
<Author>: Tucker J. Polomik github.com/TheNergaL
<Name of algorithm>: Singly Linked-list
<Brief description>:
List comprised of nodes which hold a value
and point to the next value element in the list.
If there exists no next element, it points to null.

Time complexity:
Element search/access: O(N)
Data insertion: O(1)
Data deletion: O(1)
where N is the number of nodes (elements) in the list.

Space complexity:
O(n), where n is the number of nodes (elements) in a list
*/

template <class T>
LinkedList<T>::LinkedList() {    //constructor
    head = nullptr;
    last = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList() {    //destructor
    Node<T>* temp_node = head;
    while(temp_node != nullptr) {
        temp_node = temp_node->nextnode;
        delete(head);
        head = temp_node;
    }
}

template <class T>
bool LinkedList<T>::isEmpty() {
    return (head == nullptr);
}

template <class T>
int LinkedList<T>::size() const {
    if (head == nullptr) { return 0; }
        Node<T>* temp_node = head;
        int nodeWalk = 0;
    while (temp_node != nullptr) {
        nodeWalk += 1;
        temp_node = temp_node->nextnode;
  }
    return nodeWalk;
}

template <class T>
int LinkedList<T>::size_quick() const {
    return size;
}

template <class T>
void LinkedList<T>::insertFront(T insertValue) {
    quickSize += 1;
    Node<T>* new_node;

    new_node->value = insertValue;

    if (head == nullptr) {
        head = new_node;
      }
    else {
        new_node->nextnode = head;
        head = new_node;
    }
}

template <class T>
void LinkedList<T>::insertBack(T insertValue) {
    quickSize += 1;
    Node<T>* new_node;
    new_node->value = insertValue;
    new_node->nextnode = nullptr;

    Node<T>* temp_node = head;

    if(temp_node != nullptr) {
        while (temp_node->nextnode != nullptr) {
            temp_node = temp_node->nextnode;
          }
        temp_node->nextnode = new_node;
      }
    else {
        head = new_node;
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
        Node<T>* temp_node = head;
        int count = 0;
        while (temp_node != nullptr) {
            count += 1;
            temp_node = temp_node->nextnode;
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
    if (head == nullptr and last == nullptr) {
        return false;
    }
    else {
        Node<T>* temp_node;
        temp_node = head;
        head = head->nextnode;
        delete(temp_node);
        quickSize -= 1;
        return true;
    }
}

template <class T>
void LinkedList<T>::clear() {
    Node<T>* temp_node = head;
    while (temp_node != nullptr) {
        temp_node = temp_node->nextnode;
        head = temp_node;
        delete(temp_node);
    }
}

template <class T>
T& LinkedList<T>::peek() {
    return head->value;
}
