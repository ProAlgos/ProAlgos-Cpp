# Algos: C++
[![Build Status](https://travis-ci.org/faheel/Algos.svg?branch=master)](https://travis-ci.org/faheel/Algos)

Implementation of well-known (and some rare) algorithms, in C++.

## Contents
:white_check_mark: = has unit tests

### Algorithms
* Backtracking
  * [N-Queens](source/backtracking/n_queens.cpp)
* Dynamic programming
  * [Matrix chain multiplication](source/dynamic_programming/matrix_chain_mult.cpp) :white_check_mark:
  * Maximum sum contiguous subarray: [Kadane's algorithm](source/maximum_subarray/kadane.cpp)
* Number theory
  * [Binomial coefficient](source/number_theory/binomial_coefficient.cpp) :white_check_mark:
  * Euclidean algorithms
    * [Greatest common divisor](source/number_theory/gcd.cpp) (GCD)
    * [Extended Euclidean algorithm](source/number_theory/extended_euclid.cpp) (Bézout coefficients and GCD)
  * [Fast exponentiation](source/number_theory/fast_exponentiation.cpp) :white_check_mark:
  * Nth Fibonacci number
    * [Linear time algorithm](source/number_theory/fibonacci.cpp) :white_check_mark:
    * [Logarithmic time algorithm](source/number_theory/fibonacci_efficient.cpp) :white_check_mark:
  * [Perfect number check](source/number_theory/perfect_number_check.cpp)
  * Prime numbers
    * [Sieve of Eratosthenes (simple)](source/number_theory/sieve_of_eratosthenes.cpp)
* Searching
  * [Binary search](source/searching/binary_search.cpp)
  * [Linear search](source/searching/linear_search.cpp) :white_check_mark:
  * [Ternary search](source/searching/ternary_search.cpp) :white_check_mark:
* Sorting
  * [Bubble sort](source/sorting/bubble_sort.cpp)
  * [Counting sort (stable)](source/sorting/counting_sort.cpp)
  * [Heap sort](source/sorting/heap_sort.cpp)
  * [Insertion sort](source/sorting/insertion_sort.cpp)
  * [Merge sort](source/sorting/merge_sort.cpp)
  * [Quick sort](source/sorting/quick_sort.cpp)
  * [Radix sort](source/sorting/radix_sort.cpp)
  * [Selection sort](source/sorting/selection_sort.cpp)
  * [Shell sort](source/sorting/shell_sort.cpp)
* String
  * [Longest common subsequence](source/string/lcs.cpp)
  * Searching (pattern matching)
    * [Knuth-Morris-Pratt](source/string/kmp.cpp)

### Data structures
* [Binary search tree](include/data_structures/binary_search_tree.cpp)
* [Disjoint-set](include/data_structures/disjoint_set.cpp) :white_check_mark:

## Compiling
To compile the source files, run **`make all`**. Doing so will:
* create executable binaries in sub-directories under the `bin` directory, and
* create intermediate build files in sub-directories under the `build` directory.

The sub-directories will be the same as they are under `source`.

To compile and run the tests, run **`make test`**. This will compile all the tests (in the same way as described above) and will run them, displaying the results. Note that the test binaries will have `.test` at the end of their name.

To remove all of the files created during compilation, run **`make clean`**. You need not do this every time you make some changes to a file and want to recompile it. Just run **`make all`**, and it will re-compile just those files whose contents have changed.

To know what happens in the background when **`make`** runs, you may read the [Makefile](Makefile). For more information on **`make`**, read the [GNU make Manual](https://www.gnu.org/software/make/manual/make.html).

## Unit tests
If you would like to (and you should) add unit tests for the code you are contributing, or for some of the existing code, read about [Adding unit tests for C++ code](UNIT_TESTS.md).

## C++ Coding Guidelines
If you want to contribute an algorithm or data structure in C++, make sure to read the [C++ Coding Guidelines](CODING_GUIDELINES.md) apart from the general [Contributing Guidelines](../CONTRIBUTING.md). This will help in ensuring that your code conforms to the style followed in this project.
