# Algos: C++

[![Travis status][travis-shield]][travis-link]

Implementing well-known (and some rare) **algorithms and data structures in C++**, while following **good software engineering practices** such as writing well-documented code, adhering to code guidelines, writing unit tests, reviewing each other's code, and ultimately learning to be better software developers.

## Contents

:white_check_mark: = has unit tests

### Algorithms

* Backtracking
  * [N-Queens](include/algorithm/backtracking/n_queens.hpp)
  
* Dynamic programming
  * [0-1 knapsack](include/algorithm/dynamic_programming/0_1_knapsack.hpp) :white_check_mark:
  * [Coin change](include/algorithm/dynamic_programming/coin_change.hpp) :white_check_mark:
  * [Longest decreasing subsequence](include/algorithm/dynamic_programming/longest_decreasing_subsequence.hpp) :white_check_mark:
  * [Matrix chain multiplication](include/algorithm/dynamic_programming/matrix_chain_multiplication.hpp) :white_check_mark:
  * Maximum sum contiguous subarray: [Kadane's algorithm](include/algorithm/dynamic_programming/kadane.hpp) :white_check_mark:
  * [Rod cutting](include/algorithm/dynamic_programming/rod_cutting.hpp) :white_check_mark:
  * [Weighted activity selection](include/algorithm/dynamic_programming/weighted_activity_selection.hpp) :white_check_mark:

* Number theory
  * [Binomial coefficient](include/algorithm/number_theory/binomial_coefficient.hpp) :white_check_mark:
  * Euclidean algorithms
    * [Greatest common divisor](include/algorithm/number_theory/greatest_common_divisor.hpp) (GCD)
    * [Extended Euclidean algorithm](include/algorithm/number_theory/extended_euclidean.hpp) (Bézout coefficients) :white_check_mark:
  * [Fast exponentiation](include/algorithm/number_theory/fast_exponentiation.hpp) :white_check_mark:
  * Nth Fibonacci number
    * [Linear time algorithm](include/algorithm/number_theory/fibonacci.hpp) :white_check_mark:
    * [Logarithmic time algorithm](include/algorithm/number_theory/fibonacci_efficient.hpp) :white_check_mark:
  * [Perfect number check](include/algorithm/number_theory/perfect_number_check.hpp) :white_check_mark:
  * Prime numbers
    * [Sieve of Eratosthenes (simple)](include/algorithm/number_theory/sieve_of_eratosthenes.hpp) :white_check_mark:
  
* Searching
  * [Binary search](include/algorithm/searching/binary_search.hpp) :white_check_mark:
  * [Linear search](include/algorithm/searching/linear_search.hpp) :white_check_mark:
  * [Ternary search](include/algorithm/searching/ternary_search.hpp) :white_check_mark:
  
* Sorting
  * [Bubble sort](include/algorithm/sorting/bubble_sort.hpp) :white_check_mark:
  * [Comb sort](include/algorithm/sorting/comb_sort.hpp) :white_check_mark:
  * [Counting sort (stable)](include/algorithm/sorting/counting_sort.hpp) :white_check_mark:
  * [Heap sort](include/algorithm/sorting/heap_sort.hpp) :white_check_mark:
  * [Insertion sort](include/algorithm/sorting/insertion_sort.hpp) :white_check_mark:
  * [Merge sort](include/algorithm/sorting/merge_sort.hpp) :white_check_mark:
  * [Quick sort](include/algorithm/sorting/quick_sort.hpp) :white_check_mark:
  * [Radix sort](include/algorithm/sorting/radix_sort.hpp)
  * [Selection sort](include/algorithm/sorting/selection_sort.hpp) :white_check_mark:
  * [Shell sort](include/algorithm/sorting/shell_sort.hpp) :white_check_mark:

* String
  * [Longest common subsequence](include/algorithm/string/longest_common_subsequence.hpp) :white_check_mark:
  * Searching (pattern matching)
    * [Knuth-Morris-Pratt](include/algorithm/string/knuth_morris_pratt.hpp) :white_check_mark:
  * [Edit Distance Problem](include/algorithm/string/edit_distance.hpp) :white_check_mark:
  * [Shunting yard](include/algorithm/string/shunting_yard.hpp) :white_check_mark:

### Data structures

* Linked List
  * [Singly linked list](include/data_structure/linked_list/singly_linked_list.hpp) :white_check_mark:
  * [Doubly linked list](include/data_structure/linked_list/doubly_linked_list.hpp) :white_check_mark:
  
* Set
  * [Disjoint-set](include/data_structure/set/disjoint_set.hpp) :white_check_mark:
  
* Tree
  * [Binary search tree](include/data_structure/tree/binary_search_tree.hpp) :white_check_mark:

## Compiling

To compile the source files, run **`make all`**. Doing so will:

* create executable binaries in sub-directories under the `bin` directory, and
* create intermediate build files in sub-directories under the `build` directory.

The sub-directories will be the same as they are under `source`.

To compile and run the tests, run **`make test`**. This will compile all the tests (in the same way as described above) 
and will run them, displaying the results. Note that the test binaries will have `.test` at the end of their name.

To remove all of the files created during compilation, run **`make clean`**. You need not do this every time you make 
some changes to a file and want to recompile it. Just run **`make all`**, and it will re-compile just those files whose 
contents have changed.

To know what happens in the background when **`make`** runs, you may read the [Makefile](Makefile). For more information 
on **`make`**, read the [GNU make Manual](https://www.gnu.org/software/make/manual/make.html).

## Contributing

If you want to contribute an algorithm or data structure in C++, please have a look at the following guidelines: 
* [General Contribution Guidelines](../.github/CONTRIBUTING.md)
* [C++ Contribution Guidelines](CONTRIBUTING.md) 
* [C++ Coding Guidelines](CODING_GUIDELINES.md)

Following the guidelines laid out in these documents will ensure that your code conforms to the standards and style 
of the project.

[travis-shield]: https://img.shields.io/travis/faheel/Algos.svg?style=for-the-badge
[travis-link]: https://travis-ci.org/faheel/Algos
