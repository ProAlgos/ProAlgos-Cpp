# Linked List

The linked list is a dynamic data structure that contains elements not stored in contiguous memory. This means that the elements of the list must contain pointers to other elements in the list in order to form a chain of associations.
As a result of it being dynamic, the linked list can easily grow and shrink.
Common implementations of the linked list include stacks and queues, which often only need to access or remove elements from the front or end of a list.

### Contents

1. [doubly linked list](#1-doubly-linked-list)
2. [singly linked list](#2-singly-linked-list)

---

## 1. Doubly Linked List

The Doubly Linked List stores a list of elements that contain pointers to both the previous and next element in the list. 
This implementation of the linked list allows for both forward and backward traversion, but it does require more memory than the Singly Linked List.


### Complexity

Time    | Space
--------|-------------------
_O(N)_ | _O(1)_

where N is the number of elements.

## 2. Singly Linked List

The Singly Linked List stores a list of elements that contain a pointer to the next element in the list.
This implementation of the linked list allows for only forward traversion, but requires less memory than the Doubly Linked List. 


### Complexity

Time    | Space
--------|-------------------
_O(N)_ | _O(N)_

where N is the number of elements.
