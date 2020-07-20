# Sorting Algorithms

Sorting Algorithms are used to rearange a given array or list elements according to a comparison operator on the elements. The comparison operator is used to decide the new order of element in the respective data structure. 

## Contents


1.[Bubble Sort](https://github.com/ProAlgos/ProAlgos-Cpp/blob/master/cpp/include/algorithm/sorting/bubble_sort.hpp)  
2.[Bucket Sort](https://github.com/ProAlgos/ProAlgos-Cpp/blob/master/cpp/include/algorithm/sorting/bucket_sort.hpp)  
3.[Comb Sort](https://github.com/ProAlgos/ProAlgos-Cpp/blob/master/cpp/include/algorithm/sorting/comb_sort.hpp)  
4.[Counting Sort](https://github.com/ProAlgos/ProAlgos-Cpp/blob/master/cpp/include/algorithm/sorting/counting_sort.hpp)  
5.[Heap Sort](https://github.com/ProAlgos/ProAlgos-Cpp/blob/master/cpp/include/algorithm/sorting/heap_sort.hpp)  
6.[Insertion Sort](https://github.com/ProAlgos/ProAlgos-Cpp/blob/master/cpp/include/algorithm/sorting/insertion_sort.hpp)  
7.[Merge Sort](https://github.com/ProAlgos/ProAlgos-Cpp/blob/master/cpp/include/algorithm/sorting/merge_sort.hpp)  
8.[Quick Sort](https://github.com/ProAlgos/ProAlgos-Cpp/blob/master/cpp/include/algorithm/sorting/quick_sort.hpp)  
9.[Radix Sort](https://github.com/ProAlgos/ProAlgos-Cpp/blob/master/cpp/include/algorithm/sorting/radix_sort.hpp)  
10.[Selection Sort](https://github.com/ProAlgos/ProAlgos-Cpp/blob/master/cpp/include/algorithm/sorting/selection_sort.hpp)  
11.[Shell Sort](https://github.com/ProAlgos/ProAlgos-Cpp/blob/master/cpp/include/algorithm/sorting/shell_sort.hpp)  
12.[Utils Sort](https://github.com/ProAlgos/ProAlgos-Cpp/blob/master/cpp/include/algorithm/sorting/utils.hpp)  



### Bubble Sort

Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.  

Example:

First Pass:  
( 5 1 4 2 8 ) –> ( 1 5 4 2 8 ), Here, algorithm compares the first two elements, and swaps since 5 > 1.  
( 1 5 4 2 8 ) –>  ( 1 4 5 2 8 ), Swap since 5 > 4  
( 1 4 5 2 8 ) –>  ( 1 4 2 5 8 ), Swap since 5 > 2  
( 1 4 2 5 8 ) –> ( 1 4 2 5 8 ), Now, since these elements are already in order (8 > 5), algorithm does not swap them.  
  
Second Pass:  
( 1 4 2 5 8 ) –> ( 1 4 2 5 8 )  
( 1 4 2 5 8 ) –> ( 1 2 4 5 8 ), Swap since 4 > 2  
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )  
( 1 2 4 5 8 ) –>  ( 1 2 4 5 8 )  
Now, the array is already sorted, but our algorithm does not know if it is completed. The algorithm needs one whole pass without any swap to know it is sorted.  

Third Pass:  
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )  
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )  
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )  
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )  

    Worst and Average Case Time Complexity: O(n*n). Worst case occurs when array is reverse sorted.

    Best Case Time Complexity: O(n). Best case occurs when array is already sorted.

    Auxiliary Space: O(1)

### Bucket Sort

In the Bucket Sorting technique, the data items are distributed in a set of buckets. Each bucket can hold a similar type of data. After distributing, each bucket is sorted using another sorting algorithm. After that, all elements are gathered on the main list to get the sorted form.
The complexity of the Bucket Sort Technique.

    Time Complexity: O(n + k) for best case and average case and O(n^2) for the worst case.

    Space Complexity: O(nk) for worst case
### Comb Sort
Comb Sort is mainly an improvement over Bubble Sort. Bubble sort always compares adjacent values. So all inversions are removed one by one. Comb Sort improves on Bubble Sort by using gap of size more than 1. The gap starts with a large value and shrinks by a factor of 1.3 in every iteration until it reaches the value 1. Thus Comb Sort removes more than one inversion counts with one swap and performs better than Bubble Sort.  

    Time Complexity: Worst case complexity is O(n2), the Best Case complexity is O(n).  
    Auxiliary Space: O(1).

### Counting Sort
Counting sort is a sorting technique based on keys between a specific range. It works by counting the number of objects having distinct key values (kind of hashing). Then doing some arithmetic to calculate the position of each object in the output sequence.

Let us understand it with the help of an example.

    For simplicity, consider the data in the range 0 to 9. 
    Input data: 1, 4, 1, 2, 7, 5, 2
     1) Take a count array to store the count of each unique object.
    Index:     0  1  2  3  4  5  6  7  8  9
    Count:     0  2  2  0   1  1  0  1  0  0

    2) Modify the count array such that each element at each index 
    stores the sum of previous counts. 
    Index:     0  1  2  3  4  5  6  7  8  9
    Count:     0  2  4  4  5  6  6  7  7  7

    The modified count array indicates the position of each object in 
    the output sequence.
 
    3) Output each object from the input sequence followed by 
    decreasing its count by 1.
    Process the input data: 1, 4, 1, 2, 7, 5, 2. Position of 1 is 2.
    Put data 1 at index 2 in output. Decrease count by 1 to place 
    next data 1 at an index 1 smaller than this index.
``
Time Complexity: O(n+k) where n is the number of elements in input array and k is the range of input.  
Auxiliary Space: O(n+k)
``

### Heap Sort

Heap sort is a comparison based sorting technique based on Binary Heap data structure. It is similar to selection sort where we first find the maximum element and place the maximum element at the end. We repeat the same process for remaining element.
```
Input data: 4, 10, 3, 5, 1
         4(0)
        /   \
     10(1)   3(2)
    /   \
 5(3)    1(4)

The numbers in bracket represent the indices in the array 
representation of data.

Applying heapify procedure to index 1:
         4(0)
        /   \
    10(1)    3(2)
    /   \
5(3)    1(4)

Applying heapify procedure to index 0:
        10(0)
        /  \
     5(1)  3(2)
    /   \
 4(3)    1(4)
The heapify procedure calls itself recursively to build heap
 in top down manner.
```
    Time Complexity: Time complexity  of Heap Sort is O(nLogn).

### Insertion sort
Insertion sort is a simple sorting algorithm that builds the final sorted array one item at a time. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort.
  
    Worst complexity: n^2  
    Average complexity: n^2  
    Best complexity: n  
    Space complexity: 1  
### Merge Sort
Like QuickSort, Merge Sort is a Divide and Conquer algorithm. It divides input array in two halves, calls itself for the two halves and then merges the two sorted halves. The merge() function is used for merging two halves. The merge(arr, l, m, r) is key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one. See following C implementation for details.  

    Worst complexity: n*log(n)
    Average complexity: n*log(n)
    Best complexity: n*log(n)
    Space complexity: n

### Quick Sort
Like Merge Sort, QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot. There are many different versions of quickSort that pick pivot in different ways.

Always pick first element as pivot.  
Always pick last element as pivot.  
Pick a random element as pivot.  
Pick median as pivot.  

    Worst complexity: n^2  
    Average complexity: n*log(n)  
    Best complexity: n*log(n)  

### Radix Sort
In computer science, radix sort is a non-comparative sorting algorithm. It avoids comparison by creating and distributing elements into buckets according to their radix.  

    Worst complexity: n*k/d
    Average complexity: n*k/d
    Space complexity: n+2^d

### Selection Sort
In computer science, selection sort is an in-place comparison sorting algorithm. It has an O(n²) time complexity, which makes it inefficient on large lists, and generally performs worse than the similar insertion sort.   

    Worst complexity: n^2
    Average complexity: n^2
    Best complexity: n^2
    Space complexity: 1

### Shell Sort
Shell sort, also known as Shell sort or Shell's method, is an in-place comparison sort. It can be seen as either a generalization of sorting by exchange or sorting by insertion. The method starts by sorting pairs of elements far apart from each other, then progressively reducing the gap between elements to be compared.  

    Worst complexity: Depends on gap sequence
    Average complexity: n*log(n)^2 or n^(3/2)
    Best complexity: n

### Utlis Sort

Returns a copy of the list, sorted according to the comparator function, which should accept two values at a time and return a negative number if the first value is smaller, a positive number if it’s larger, and zero if they are equal. Please note that this is a copy of the list. It does not modify the original.  
