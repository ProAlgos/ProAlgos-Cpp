# Tree
Trees are a group of data structures that are named this way because of how they look when conceptually drawn or because of how the different elements connect to each other. Trees are used to solve a variety of different problems, such as storing data so that it quickly searched for later, allowing prefix sums to be calculated quickly, or to store data in a hierarchical structure. 

### Contents

1. [Fenwick Tree](#1-fenwick-tree)

---

## 1. Fenwick Tree
A fenwick tree offers a more equitable tradeoff between updating an array of prefix sums and calculating prefix sums. Both the update operation and the calculate operation are implemented with the time complexity of O(log n). That can be compared to the naive implementation where the caclulate operation is O(1), and the update operation is O(n).

### Usage 

```c++
vector<int> original_array{10, 3, 15, 12, 5};

FenwickTree tree(original_array);

\\ calculate the sum from index 0 -> 2
tree.calculate_prefix_sum(2)

\\ add 3 to the value located at index = 2
tree.update_tree(3, 2)

\\ add -3 to the value located at index = 2
tree.update_tree(-3, 2)

```

### Complexity
Operation   | Time         | Space
----------- | ------------ |-------------------
_Update_    | _O(log N)_   | _O(N)_
_Calculate_ | _O(log N)_   | _O(N)_

Where N is the number of elements in the original array.
