/*
    Fenwick Tree
    ------------
    A fenwick tree is conceptually a tree, but it is implemented as a flat array
    that allows the quick calculations prefix sums in an array. It accomplishes this by 
    storing sums according to the binary representations of the indexes. For practical
    purposes the fenwick tree is indexed starting at 1. 
    Below is a more in-depth explanation of how the tree is constructed.
    ...............................
    start of sum         end of sum
    (index - 2^r + 1) -> index 
    ...............................
    Where r is the last significant bit of the binary representation of index.
    For example:
    index = 6, 110 (in binary)
    r = 1
    (6 - 2^1 + 1) -> 6
    5 -> 6
    
    So the sum of the value stored a 5 through 6 will be stored at index 6. Now 
    remember the index is incremented by one from the original array. So at 
    index = 6, of the fenwick tree, the sum of 4 through 5, of the original array
    will be stored.
    
    This set up allows any prefix sum to be calculated in at most log(n) operations,
    where n is the number of elements in the original array. To update the tree
    it takes at most log(n) operations as well.
*/

#ifndef FENWICK_TREE_HPP
#define FENWICK_TREE_HPP

#include <vector>

using std::vector;

class FenwickTree {
private:
  vector<int> tree;
  
  int max_index;

public:
  FenwickTree(vector<int> original_array);
  
  void update_tree(int index, int value);
  
  int calculate_prefix_sum(int index);
};

/*
  Constructor
  -----------
  This creates the initial fenwick tree out of the original array. It goes 
  though each element in the array passed to the function and calls the update
  function on that value and index. 
  
  Time complexity
  ---------------
  Average case : O(nlog(n)), where n is the number of elements in the original array
  Worst case : O(nlog(n))
  
  Space complexity
  ----------------
  O(n)
*/
FenwickTree::FenwickTree(vector<int> original_array){
  max_index = original_array.size();
  if (max_index == 0) {
    return;
  }
  tree.insert(tree.begin(), max_index + 1, 0);
  
  for (int i = 0;i < max_index;i++) {
    update_tree(i, original_array[i]);
  }
}

/*
  Update tree
  -----------
  This function adds a specified int, value, to all the elements in the fenwick 
  tree such that the prefix sums will still be correct. To start with the index 
  will be incremented so that it is correct for the fenwick tree. 
  
  Next we enter the while loop where the entered value will be added to the index 
  entered. The next line updates the index to the next index by using
  two's complement and the bitwise AND operator. An example below is included for 
  a clearer explanation. In brackets is the decimal number and the binary number 
  is without brackets.
  .......................
  index = 0110 (6)
  
  Calculating the two's complement
  -index = 1001
              1
           ----
           1010
  so: (index & -index) = (0110 & 1010) = 0010 (2)
  
  therefore: index += (index & -index) -> index = 6 + 2 = 8
  .......................
  
  Time complexity
  ---------------
  Worst case : O(log n), where n is the number of elements in the fenwick tree
  
  Space complexity
  ----------------
  O(n)
*/
void FenwickTree::update_tree(int index, int value){
  if (max_index == 0){
    return;
  }
  index = index + 1;
  
  while (index <= max_index) {
    tree[index] += value;
    index += (index & -index);
  }
}

/*
  Calculate prefix sum
  --------------------
  This will calculate the prefix sum that would occur at a given index in the
  original array. The value for the sum is initialized to 0 and the value for the 
  index is incremented by one to start off with. In the while loop the value at 
  the current index is added to the sum, and the index is moved to the next index. 
  The new index is found in a similar manner to how the new index was found in 
  the update_tree function except in this function we subtract the result of 
  (index & -index) instead of adding it to the current index. 
  
  Time complexity
  ---------------
  Worst case: O(log n), where n is the number of elements in the fenwick tree
  
  Space complexity
  ----------------
  O(n)
*/
int FenwickTree::calculate_prefix_sum(int index){
  if (max_index == 0){
    return 0;
  }
  int sum = 0;
  index = index + 1;
  
  while (index > 0) {
    sum = sum + tree[index];
    
    index -= (index & -index);
  }
  
  return sum;
}

#endif
