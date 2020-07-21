# Sorting
Sorting algorithms are designed to arrange data in a particular order. Sorting algoritms have a few properties:

#### Stable and unstable sorting
**Stable:** Identical elements remain in the same order as before sorting.  
**Unstable:** Identical elements may be sorted in any order.

#### In-place and Not In-place Sorting:
**In-place**: where the elements are sorted by modifying their order directly.
**Not In-place**: where an auxiliary data structure is used for sorting.


### Contents
1. [Bubble Sort](#1-bubble-sort)
2. [Selection Sort](#2-selection-sort)
3. [Insertion Sort](#3-insertion-sort)
4. [Quick Sort](#4-quick-sort)
5. [Merge Sort](#5-merge-sort)
6. [Counting Sort](#6-counting-sort)
7. [Bucket Sort](#7-bucket-sort)
8. [Radix Sort](#8-radix-sort)
9. [Heap Sort](#9-heap-sort)
10. [Shell Sort](#10-shell-sort)
11. [Comb Sort](#11-comb-sort)
---

## 1. Bubble Sort
It is the simplest sorting algorithm which repeatedly compares pairs of adjacent elements and swaps their positions if they are in the wrong order.
Also known as sinking sort.

### Usage
``` c++
vector<int> Arr{1, 8, 5, 12, 3};
bubble_sort(Arr, -1, true)
```
### Complexity

Time    | Space
:--------:|:-------------------:
_O(N^2)_ | _O(1)_

Where N is the number of elements in the array.

## 2. Selection Sort
A simple in-place comparision-based sorting algorithm. It sorts a list by finding the smallest / largest element (depending on the
sorting order) from the unsorted sublist and swapping it with the leftmost unsorted element, moving the sublist boundary one element to the right.

### Usage
``` c++
vector<int> Arr{1, 8, 5, 12, 3};
selection_sort(Arr, -1, true)
```
### Complexity

Time    | Space
:--------:|:-------------------:
_O(N^2)_ | _O(1)_

Where N is the number of elements in the array.

## 3. Insertion Sort
It is an in-place, comparision based sorting algorithm that builds the final sorted list of value one item at a time. It is more efficient for small data sets than most other quadratic-time algorithms.

### Usage
``` c++
vector<int> Arr{1, 8, 5, 12, 3};
insertion_sort(Arr, -1, true)
```
### Complexity

Time    | Space
:--------:|:-------------------:
_O(N^2)_ | _O(1)_

Where N is the number of elements in the array.

## 4. Quick Sort
It is an efficient sorting algorithm that uses the concept of 'divide and conquer'. It is a recursive algorithm. 

### Usage
``` c++
vector<int> Arr{1, 8, 5, 12, 3};
quick_sort(Arr, -1, true)
```
### Complexity

Time    | Space
:--------:|:-------------------:
Absolute case:_O(N^2)_ | _O(1)_
Expected case:_O(N * log(N)_ | _O(1)_

Where N is the number of elements.

## 5. Merge Sort
It is also a sorting algorithm that uses the concept of 'divide and conquer'. It is a recursive, not in-place sorting algorithm and is efficient.

### Usage
``` c++
vector<int> Arr{1, 8, 5, 12, 3};
merge_sort(Arr, -1, true)
```
### Complexity

Time    | Space
:--------:|:-------------------:
_O(N * log(N)_ | _O(1)_

Where N is the number of elements.

## 6. Counting Sort
An integer sorting algorithm that operates by counting the number of objects that have each distinct key value, and using arithmetic on those counts to determine the positions of each key value in the output sequence. It is a stable and comparision based algorithm. 

### Usage
``` c++
vector<int> Arr{1, 8, 5, 12, 3};
couting_sort(Arr, -1, true)
```
### Complexity

Time    | Space
:--------:|:-------------------:
_O(N + R)_ | _O(N + K)_

Where N is the number of elements, R is the range of input and K the size of the frequency array.


<!-- WIP BELOW -->
## 7. Bucket Sort
A sorting algorithm that works 
### Usage
``` c++
vector<int> Arr{1, 8, 5, 12, 3};
couting_sort(Arr, -1, true)
```
### Complexity

Time    | Space
:--------:|:-------------------:
_O(N + R)_ | _O(N + K)_

Where N is the number of elements, R is the range of input and K the size of the frequency array.

## 7. Bucket Sort
A sorting algorithm that works 
### Usage
``` c++
vector<int> Arr{1, 8, 5, 12, 3};
couting_sort(Arr, -1, true)
```
### Complexity

Time    | Space
:--------:|:-------------------:
_O(N + R)_ | _O(N + K)_

Where N is the number of elements, R is the range of input and K the size of the frequency array.

## 8. Radix Sort
A sorting algorithm that works 
### Usage
``` c++
vector<int> Arr{1, 8, 5, 12, 3};
couting_sort(Arr, -1, true)
```
### Complexity

Time    | Space
:--------:|:-------------------:
_O(N + R)_ | _O(N + K)_

Where N is the number of elements, R is the range of input and K the size of the frequency array.

## 9. Heap Sort
A sorting algorithm that works 
### Usage
``` c++
vector<int> Arr{1, 8, 5, 12, 3};
couting_sort(Arr, -1, true)
```
### Complexity

Time    | Space
:--------:|:-------------------:
_O(N + R)_ | _O(N + K)_

Where N is the number of elements, R is the range of input and K the size of the frequency array.

## 10. Shell Sort
A sorting algorithm that works 
### Usage
``` c++
vector<int> Arr{1, 8, 5, 12, 3};
couting_sort(Arr, -1, true)
```
### Complexity

Time    | Space
:--------:|:-------------------:
_O(N + R)_ | _O(N + K)_

Where N is the number of elements, R is the range of input and K the size of the frequency array.

## 11. Comb Sort
A sorting algorithm that works 
### Usage
``` c++
vector<int> Arr{1, 8, 5, 12, 3};
couting_sort(Arr, -1, true)
```
### Complexity

Time    | Space
:--------:|:-------------------:
_O(N + R)_ | _O(N + K)_

Where N is the number of elements, R is the range of input and K the size of the frequency array.

