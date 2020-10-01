# Linked Lists

Linked Lists are used as linear data structures which consist of a node. A node holds data as well as a pointer to the next node. Linked Lists easily implement stacks and queues. Linked Lists are used to create graphs and tress. Nodes are not stored at continous memory. Major advantage of linked lists over array sis that the former are dynamic in nature.

### Contents

1. [Singly Linked List](#1-singly-linked-list)
2. [Doubly Linked List](#2-doubly-linked-list)

---

## 1. Singly Linked List

A linked list is a linear data structure used to maintain a dynamic list of similar elements. The list is maintained so that each element points to the next element and stores some data. To improve performance, the head and tail elements are stored to keep a track of insertions and deletions.

### Functions
1. [is_empty()](#1-is_empty)
2. [length()](#2-length)
3. [insert_front()](#3-insert_front)
4. [insert_rear()](#4-insert_rear)
5. [delete_front()](#5-delete-front)
6. [delete_rear()](#6-delete_rear)
7. [value_at()](#7-value_at)
8. [reverse()](#8-reverse)
9. [clear()](#9-clear)

### Usage and Complexities

### 1. is_empty()
Returns true if list is empty.

#### Usage
```
bol var = L.is_empty(); //'L' is name of the linked list.
```
#### Complexity

Time               | 
-------------------|
_O(1)_ |

### 2. length()
Returns the number of elements in this list.

#### Usage
```
int size = L.length();
```
#### Complexities

Time               | 
-------------------|
_O(N)_ |

where N is the number of elements in the list.

### 3. insert_front()
Inserts an element at the head of the list.

#### Usage
```
int val = 23;
L.insert_front(val); //'L' is the linked list and 'val' is the value to be inserted.
```
#### Complexities
Time               | Space
-------------------|-------------------
_O(1)_ | _O(1)_

### 4. insert_rear()
Inserts an element at the tail of the list.

#### Usage
```
int val = 35;
L.insert_end(val); //'L' is the linked list and 'val' is the value to be inserted.
```
#### Complexities
Time               | Space
-------------------|-------------------
_O(1)_ | _O(1)_

### 5. delete_front()
Removes the element from at the head.

#### Usage
```
L.delete_front(); //'L' is the linked list.
```
#### Complexities
Time               | Space
-------------------|-------------------
_O(1)_ | _O(1)_

### 6. delete_rear()
Removes the element from at the tail. To remove an element from the tail, the list needs to be iterated through since the second-last element is needed.

#### Usage
```
L.delete_rear(); //'L' is the linked list.
```
#### Complexities
Time               | Space
-------------------|-------------------
_O(N)_ | _O(1)_

where N is the number of nodes in the list.

### 7. value_at()
This is used to find the value of the element at a particular position in the list.

#### Usage
```
int index =2;  
int value = L.value_at(index); //'L' is the linked list.
```
#### Complexities
Time               | Space
-------------------|-------------------
_O(N)_ | _O(1)_

where N is the number of nodes in the list.

### 8. reverse()
Reverse the list by changing links between nodes.

#### Usage
```  
L.reverse(); //'L' is the linked list.
```
#### Complexities
Time               | Space
-------------------|-------------------
_O(N)_ | _O(1)_

where N is the number of nodes in the list.


### 9. clear()
This is used to empty the list and remove all the elements.

#### Usage
```  
L.clear(); //'L' is the linked list.
```
#### Complexities
Time               | Space
-------------------|-------------------
_O(N)_ | _O(1)_

where N is the number of nodes in the list.


## 2. Doubly Linked List
