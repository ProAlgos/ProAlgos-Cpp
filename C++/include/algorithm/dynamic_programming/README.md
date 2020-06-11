# Dynamic programming

Dynamic programming (also known as dynamic optimization) is a method for solving a complex problem by breaking it down into a collection of simpler subproblems, solving each of those subproblems just once, and storing their solutions. The next time the same subproblem occurs, instead of recomputing its solution, one simply looks up the previously computed solution, thereby saving computation time at the expense of a (hopefully) modest expenditure in storage space. (Each of the subproblem solutions is indexed in some way, typically based on the values of its input parameters, so as to facilitate its lookup.) The technique of storing solutions to subproblems instead of recomputing them is called "memoization".

Dynamic programming algorithms are often used for optimization. A dynamic programming algorithm will examine the previously solved subproblems and will combine their solutions to give the best solution for the given problem.

### Contents

1. [Matrix chain multiplication](#1-matrix-chain-multiplication)
2. [Coin Change](#2-coin-change)
3. [0_1 Knapsack](#3-0_1-knapsack)
4. [Kadane](#4-Kadane)
5. [Longest Decreasing Subsequence](#5-Longest-Decreasing-Subsequence)
6. [Rod Cutting](#6-Rod-Cutting)
7. [Weighted Activity Selection](#7-Weighted-Activity-Selection)

---

## 1. Matrix chain multiplication

Given a sequence of matrices, the goal is to find the most efficient way to multiply these matrices. The problem is not actually to perform the multiplications, but merely to decide the sequence of the matrix multiplications involved.

There are many options available because matrix multiplication is associative. In other words, no matter how the product is parenthesized, the result obtained will remain the same. For example, for four matrices A, B, C, and D, we would have:

_((AB)C)D = (A(BC))D = (AB)(CD) = A((BC)D) = A(B(CD))_

However, the order in which the product is parenthesized affects the number of simple arithmetic operations needed to compute the product, that is the computational complexity. For example, if A is a 10 × 30 matrix, B is a 30 × 5 matrix, and C is a 5 × 60 matrix, then

* computing _(AB)C_ needs (10×30×5) + (10×5×60) = 1500 + 3000 = 4500 operations, while
* computing _A(BC)_ needs (30×5×60) + (10×30×60) = 9000 + 18000 = 27000 operations.

Clearly the first method is more efficient. With this information, the problem statement can be refined as "how to determine the optimal parenthesization of a product of n matrices?"

### Usage

```c++
MatrixChainMultiplier chain_multiplier = MatrixChainMultiplier({40, 30, 20, 10, 30});

// ull is a type alias for `unsigned long long`
ull optimal_cost = chain_multiplier.optimal_cost();     // 30000

std::string optimal_parenthesization = chain_multiplier.optimal_parenthesization();
// ((A(BC))D)
```

### Complexity

Time               | Space
-------------------|-------------------
_O(N<sup>3</sup>)_ | _O(N<sup>2</sup>)_

where N is the number of matrices.

## 2. Coin Change

Given an unlimited amount of coins with different values, find the number of ways of making change for an given
value using the coins.

## Input
- #### `coin`
  Type: `vector<int> &`

  It contains coins of different denomination.

- #### `number_of_coins`
  Type: `int`

  It is the size of vector coin (coin.size()), or the total number of coins given.

- #### `amount`
  Type: `int`

  It is the amount for which we have to find the number of ways to make change.

### Output
- #### `table[amount][number_of_coins - 1]`
  Type: `int (bottom rightmost cell of 2D Matrix of type vector<vector<int>>)`

  After filling the matrix the bottom rightmost cell of the of the matrix will contain the total number of ways.  

### Complexity

Time               | Space
-------------------|-------------------
_O(M*N)_ | _O(M*N)_

where M is the number of coins with different values and 
N is the amount that we desired to change.

## 3. 0_1 Knapsack

Given weights and values of n items, put these items in a knapsack of a fixed capacity to get the maximum total value in the knapsack.

## Input
- #### `capacity`
  Type: `long long`

  It is the maximum capacity of the knapsack, in which we have to put weights.

- #### `numberOfItems`
  Type: `long long`

  It is the total number of items given.

- #### `weights`
  Type: `vector<long long>`

  vector array of the weights for the items given.

- #### `values`
  Type: `vector<long long>`

  vector array of the values for the items given.

### Output
- #### `maxItems[numberOfItems][capacity]`
  Type: `int (bottom rightmost cell of 2D Matrix of type vector<vector<long long>>)`

  After filling the matrix the bottom rightmost cell of the of the matrix will contain maximum total value in the knapsack.  

### Complexity

Time               | Space
-------------------|-------------------
_O(N*C)_ | _O(N*C)_

where N is the number of items and C is the capacity of the knapsack.

## 4. Kadane

This algorithm is used for finding the contiguous subarray within a one-dimensional array of integers which has the largest sum.

## Input
- #### `values`
  Type: `vector<int> &`

  Array of integers for which we have to find the contiguous subarray having the largest sum.

### Output
- #### `maxSum, start, end`
  Type: `tuple<int, size_t, size_t>`

  Output is a tuple of maximum sum, start index of the contiguous array and the last index of the contiguous array. Note: size_t is an unsigned integral data type.  

### Complexity

Time               | Space
-------------------|-------------------
_O(N)_ | _O(1)_

where N is the number of elements in the original array.

## 5. Longest Decreasing Subsequence

This algorithm finds the longest decreasing subsequence in a sequence of numbers.

## Input
- #### `input`
  Type: `vector<int> &`

  Vector array of inputs for which we have to find longest decreasing subsequence.

- #### `to_show_state`
  Type: `const bool`

  Initially it is set to false, if no second argument is provided in the function. if this is true subsequence is printed out by the function.

### Output
- #### `max`
  Type: `int`

  It is the largest length of the longest decreasing subsequence.  

### Complexity

Time               | Space
-------------------|-------------------
_O(n log(n))_ | _O(n)_

where n is the number of elements in the initial list.

## 6. Rod Cutting

Given a rod of length N units and an array of prices that contains prices of all pieces of size smaller than N. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

## Input
- #### `costs`
  Type: `vector<std::size_t>`

  Vector array of costs of all pieces of size smaller than N.

### Output
- #### `cost`
  Type: `size_t (size_t is an unsigned integral data type)`

  It is the maximum value obtainable by cutting up the rod and selling the pieces. 

### Complexity

Time               | Space
-------------------|-------------------
_O(N<sup>2</sup>)_ | _O(N)_

where N is the length of the rod.

## 7. Weighted Activity Selection

Given N activities where every activity is represented by following three elements of it.
Markup : 1. Start Time
         2. Finish Time
         3. Weight or Value Associated
Find the maximum weight subset of activities such that no two of them in the subset overlap.

## Input
- #### `start`
  Type: `const vector<std::time_t> &`

  Vector array representing start time of N activities.
  Note: time_t is a arithmetic type capable of representing times.

- #### `end`
  Type: `const vector<std::time_t> &`

  Vector array representing end time of N activities.
  Note: time_t is a arithmetic type capable of representing times.

- #### `weight`
  Type: `const vector<std::size_t> &`

  Vector array representing the Weight or priority of the given N activities.
  Note: size_t is an unsigned integral data type.

### Output
- #### `sol.back() `
  Type: `int (sol is a vector of type size_t)`

  The last index of the vector sol contains maximum weight subset of activities.

### Complexity

Time               | Space
-------------------|-------------------
_O(N*log(N))_ | _O(N)_

where N is the Number of activities given.
