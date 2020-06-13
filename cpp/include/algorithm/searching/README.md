# Searching 
Searching algorithms are designed to check for an element or retrieve an element from any data structure where it is stored.

### Contents
1. [Linear search](#1-linear-search)
2. [Binary search](#2-binary-search)
3. [Ternary search](#3-ternary-search)
---
## 1. Linear search
In this algorithm the array is traversed sequentially and every element is checked until the element is found.

### Usage
``` c++
vector<int> nums{1, 29, 6, 8, 5, 2, 0};
int index_found = linear_search(2, nums);
std::cout << index_found << std::endl; // 5 
```
### Complexity

Time    | Space
:--------:|:-------------------:
_O(N)_ | _O(1)_

Where N is the number of elements in the array.

## 2. Binary search
Search a sorted array by repeatedly dividing the search interval in half. Begin with an interval covering the whole array. If the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half. Otherwise narrow it to the upper half. Repeatedly check until the value is found or the interval is empty. The array must be sorted, if it is not, binary search won't work.

### Usage
``` c++
vector<char> letters{'a', 'b', 'c', 'd', 'e'};
int index_found = binary_search('d', letters);
std::cout << index_found << std::endl; // 3
```

### Complexity
Time    | Space
:--------:|:-------------------:
_O(log(N))_ | _O(log(N))_

where N is the number of elements in the array.

## 3. Ternary search
A ternary search algorithm is a technique in computer science for finding the minimum or maximum of a unimodal function. A ternary search determines either that the minimum or maximum cannot be in the first third of the domain or that it cannot be in the last third of the domain, then repeats on the remaining two thirds. A ternary search is an example of a divide and conquer algorithm. 
Array needs to be sorted to perform ternary search on it.

### Usage
* **Search an element in a given array.**
  ``` c++
    vector<int> nums{1, 3, 4, 5, 8, 11, 20};
    size_t index_found = ternary_search(4, nums);
    std::cout << index_found << std::endl; // 2
  ```
* **Given a function f(x) and an integral interval [a, b]**
  ```c++
    int ascending_descending_func_int(int x) {
        return -(x - 2) * (x - 2);
    }
    int descending_ascending_func_int(int x) {
        return (x - 5) * (x - 5) * (x - 5) * (x - 5);
    }
    
    int main(int argc, const char *argv[]) {
        int maximum = ternary_search(&ascending_descending_func_int, 1, 7,     ASCEND_THEN_DESCEND);
        
        int minimun = ternary_search(&descending_ascending_func_int, 2, 6, DESCEND_THEN_ASCEND);
        
        std::cout << maximum << std::endl; // 2
        std::cout << maximum << std::endl; // 5
        
        return 0;
    }
  ```
* **Given a function f(x) and an floating point interval [a, b]**
  ```c++
  float ascending_descending_func_float(float x) {
    return -(x - 9.0f) * (x - 9.0f);
  }

  float descending_ascending_func_float(float x) {
    return (x - 0.5f) * (x - 0.5f) * (x - 0.5f) * (x - 0.5f);
  }
  
  int main(int argc, const char *argv[]) {
    float maximum = ternary_search(&ascending_descending_func_float, 8.0, 9.0, ASCEND_THEN_DESCEND, 10e-9);
    float minimum = ternary_search(&descending_ascending_func_float, 0.4, 0.5, DESCEND_THEN_ASCEND, 10e-9)
    
    std::cout << maximum << std::endl; // Approx(9.0);
    std::cout << minimum << std::endl; // Approx(0.5);
    
    return 0;
  }
  ```

### Complexity
Time    | Space
:--------:|:-------------------:
_O(log<sub>3</sub>(N))_ | _O(1)_

where N is the number of elements in the array.
