# Sorting
Sorting algorithms are designed to arrange data in a particular order. Sorting algoritms have a few properties:

#### Stable and unstable sorting
**Stable:** Identical elements remain in the same order as before sorting.  
**Unstable:** Identical elements may be sorted in any order.  

#### In-place and Not In-place Sorting
**In-place**: Elements are sorted by modifying their order directly.  
**Not in-place**: An auxiliary data structure is used for sorting.  

### Contents
1. [Bubble sort](#1-bubble-sort)
2. [Bucket sort](#2-bucket-sort)
3. [Comb sort](#3-comb-sort)
4. [Counting sort](#4-counting-sort)
5. [Heap sort](#5-heap-sort)
6. [Insertion sort](#6-insertion-sort)
7. [Merge sort](#7-merge-sort)
8. [Quick sort](#8-quick-sort)
9. [Radix sort](#9-radix-sort)
10. [Selection sort](#10-selection-sort)
11. [Shell sort](#11-shell-sort)

---

## 1. Bubble sort
A simple algorithm which repeatedly compares pairs of adjacent elements and swaps their positions if they are in the wrong order. Also known as sinking sort.

### Usage
``` c++
vector<int> arr{1, 8, 5, 12, 3};
bubble_sort(arr, -1, true);
```
### Complexity

Time    | Space
:--------:|:-------------------:
_O(N^2)_ | _O(1)_

Where N is the number of elements in the array.

## 2. Bucket sort
A sorting algorithm that works by dividing elements into different buckets, and then sorting the buckets individually. Each bucket is then sorted individually by using a different sorting algorithm. Insertion sort is used in this implementation, but other algorithms can be used.

### Usage
``` c++
vector<int> arr{1, 8, 5, 12, 3};
bucket_sort(arr, -1, true);
```
### Complexity

Time    | Space
:--------:|:-------------------:
_O(N + N^2 / K+K)_ | _O(N)_

Where N is the number of elements, and K is the number of buckets

## 3. Comb sort
A sorting algorithm designed to improve upon bubble sort by eliminating small values that start near the end of the list.
	
### Usage
``` c++
vector<int> arr{1, 8, 5, 12, 3};
comb_sort(arr, -1, true);
```
### Complexity

Time    | Space
:--------:|:-------------------:
_O(N^2 / 2^p)_ | _O(1)_

Where N is the number of elements, and p is the number of increments

## 4. Counting sort
An integer sorting algorithm that operates by counting the number of objects that have each distinct key value, and using arithmetic on those counts to determine the positions of each key value in the output sequence. This is a stable and comparision based algorithm. 

### Usage
``` c++
vector<int> arr{1, 8, 5, 12, 3};
couting_sort(arr, -1, true);
```
### Complexity

Time    | Space
:--------:|:-------------------:
_O(N + R)_ | _O(N + K)_

Where N is the number of elements, R is the range of input and K the size of the frequency array.

## 5. Heap sort
A comparison-based sorting algorithm that uses an array-implemented heap to sort a list of integers.

### Usage
``` c++
vector<int> arr{1, 8, 5, 12, 3};
heap_sort(arr, -1, true);
```
### Complexity

Time    | Space
:--------:|:-------------------:
_O(N * log(N))_ | _O(1)_

Where N is the number of elements

## 6. Insertion sort
An in-place, comparison based sorting algorithm that builds the final sorted list one item at a time. This is a recursive algorithm more efficient for small data sets than most other quadratic-time algorithms.

### Usage
``` c++
vector<int> arr{1, 8, 5, 12, 3};
insertion_sort(arr, -1, true);
```
### Complexity

Time    | Space
:--------:|:-------------------:
_O(N^2)_ | _O(1)_

Where N is the number of elements in the array.

## 7. Merge sort
An algorithm that uses the concept 'divide and conquer'. This is a not in-place sorting algorithm and is efficient.

### Usage
``` c++
vector<int> arr{1, 8, 5, 12, 3};
merge_sort(arr, -1, true);
```
### Complexity

Time    | Space
:--------:|:-------------------:
_O(N * log(N)_ | _O(1)_

Where N is the number of elements.

## 8. Quick sort
An efficient sorting algorithm that uses the concept of 'divide and conquer'. This is a recursive algorithm. 

### Usage
``` c++
vector<int> arr{1, 8, 5, 12, 3};
quick_sort(arr, -1, true);
```
### Complexity

Time    | Space
:--------:|:-------------------:
Absolute case:_O(N^2)_ | _O(1)_
Expected case:_O(N * log(N)_ | _O(1)_

Where N is the number of elements.

## 8. Radix sort
Least significant digit radix sort is an efficient, non-comparative, integer sorting algorithm that sorts data with integer keys by grouping keys by the individual digits which share the same significant position and value. Note that this implementation of radix sort can be used to sort positive integers only.

### Usage
``` c++
vector<int> arr{1, 8, 5, 12, 3};
radix_sort(arr, -1, true);
```
### Complexity

Time    | Space
:--------:|:-------------------:
_O(N)_ | _O(N)_

Where N is the number of keys

## 10. Selection sort
A simple in-place comparison-based sorting algorithm. This sorts a list by finding the smallest or largest element (depending on the sorting order) from the unsorted sublist and swapping it with the leftmost unsorted element, then moving the sublist boundary one element to the right.

### Usage
``` c++
vector<int> arr{1, 8, 5, 12, 3};
selection_sort(arr, -1, true);
```
### Complexity

Time    | Space
:--------:|:-------------------:
_O(N^2)_ | _O(1)_

Where N is the number of elements in the array.

## 11. Shell sort
An in-place comparison sort which starts by sorting pairs of elements far apart from each other, then progressively reducing the gap between elements to be compared. The time complexity depends on the gap sequence, which is _floor(N / 2^K)_ in this implementation.

### Usage
``` c++
vector<int> arr{1, 8, 5, 12, 3};
shell_sort(arr, -1, true);
```
### Complexity

Time    | Space
:--------:|:-------------------:
_O(N^2)_ | _O(1)_

Where N is the number of elements

