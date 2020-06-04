# ProAlgos: C++

[![Travis status][travis-shield]][travis-link]

This project is focused on implementing **algorithms and data structures** in C++, while following **good software engineering practices**, such as: 

- Writing well-documented code
- Adhering to code guidelines
- Writing and passing unit tests
- Reviewing each other's code

## Goals

1. Implement algorithms and data structures
1. Learn to be better software developers
1. Guide one another on version control, unit testing, and algorithms

## How to get involved

There are a few ways to get involved.

#### Want to contribute to open-source and get involved with the project?

1. **Read** the [contribution guidelines][contrib-guide]
1. **Fork** the repo
1. **Create an issue** describing what you'd like to add, or **claim an issue** that's [up for grabs][up-for-grabs]
1. Create a **branch** and **add your code**
1. Submit a **pull request** and reference the issue it closes

You can find more details regarding the steps above in the [contribution
guidelines][contrib-guide], so be sure to check them out.

#### Just want to suggest a new algorithm or report a bug?

[Create a new issue](https://github.com/ProAlgos/ProAlgos-Cpp/issues/new) and we'll
handle it from there. :smile:

## Contents

:white_check_mark: = has unit tests

### Algorithms

* Backtracking
  * [N-Queens](../code/include/algorithm/backtracking/n_queens.hpp) :white_check_mark:

* Dynamic programming
  * [0-1 knapsack](../code/include/algorithm/dynamic_programming/0_1_knapsack.hpp) :white_check_mark:
  * [Coin change](../code/include/algorithm/dynamic_programming/coin_change.hpp) :white_check_mark:
  * [Longest decreasing subsequence](../code/include/algorithm/dynamic_programming/longest_decreasing_subsequence.hpp) :white_check_mark:
  * [Matrix chain multiplication](../code/include/algorithm/dynamic_programming/matrix_chain_multiplication.hpp) :white_check_mark:
  * Maximum sum contiguous subarray: [Kadane's algorithm](../code/include/algorithm/dynamic_programming/kadane.hpp) :white_check_mark:
  * [Rod cutting](../code/include/algorithm/dynamic_programming/rod_cutting.hpp) :white_check_mark:
  * [Weighted activity selection](../code/include/algorithm/dynamic_programming/weighted_activity_selection.hpp) :white_check_mark:

* Number theory
  * [Binomial coefficient](../code/include/algorithm/number_theory/binomial_coefficient.hpp) :white_check_mark:
  * Euclidean algorithms
    * [Greatest common divisor](../code/include/algorithm/number_theory/greatest_common_divisor.hpp) (GCD)
    * [Extended Euclidean algorithm](../code/include/algorithm/number_theory/extended_euclidean.hpp) (Bézout coefficients) :white_check_mark:
  * [Fast exponentiation](../code/include/algorithm/number_theory/fast_exponentiation.hpp) :white_check_mark:
  * Nth Fibonacci number
    * [Linear time algorithm](../code/include/algorithm/number_theory/fibonacci.hpp) :white_check_mark:
    * [Logarithmic time algorithm](../code/include/algorithm/number_theory/fibonacci_efficient.hpp) :white_check_mark:
  * [Perfect number check](../code/include/algorithm/number_theory/perfect_number_check.hpp) :white_check_mark:
  * Prime numbers
    * [Sieve of Eratosthenes (simple)](../code/include/algorithm/number_theory/sieve_of_eratosthenes.hpp) :white_check_mark:
  
* Searching
  * [Binary search](../code/include/algorithm/searching/binary_search.hpp) :white_check_mark:
  * [Linear search](../code/include/algorithm/searching/linear_search.hpp) :white_check_mark:
  * [Ternary search](../code/include/algorithm/searching/ternary_search.hpp) :white_check_mark:
  
* Sorting
  * [Bubble sort](../code/include/algorithm/sorting/bubble_sort.hpp) :white_check_mark:
  * [Bucket sort](../code/include/algorithm/sorting/bucket_sort.hpp) :white_check_mark:
  * [Comb sort](../code/include/algorithm/sorting/comb_sort.hpp) :white_check_mark:
  * [Counting sort (stable)](../code/include/algorithm/sorting/counting_sort.hpp) :white_check_mark:
  * [Heap sort](../code/include/algorithm/sorting/heap_sort.hpp) :white_check_mark:
  * [Insertion sort](../code/include/algorithm/sorting/insertion_sort.hpp) :white_check_mark:
  * [Merge sort](../code/include/algorithm/sorting/merge_sort.hpp) :white_check_mark:
  * [Quick sort](../code/include/algorithm/sorting/quick_sort.hpp) :white_check_mark:
  * [Radix sort](../code/include/algorithm/sorting/radix_sort.hpp)
  * [Selection sort](../code/include/algorithm/sorting/selection_sort.hpp) :white_check_mark:
  * [Shell sort](../code/include/algorithm/sorting/shell_sort.hpp) :white_check_mark:

* String
  * [Longest common subsequence](../code/include/algorithm/string/longest_common_subsequence.hpp) :white_check_mark:
  * Searching (pattern matching)
    * [Knuth-Morris-Pratt](../code/include/algorithm/string/knuth_morris_pratt.hpp) :white_check_mark:
  * [Edit Distance Problem](../code/include/algorithm/string/edit_distance.hpp) :white_check_mark:
  * [Shunting yard](../code/include/algorithm/string/shunting_yard.hpp) :white_check_mark:
  * Permutation
    * [Heap's Algorithm](../code/include/algorithm/string/heaps_algorithm.hpp) :white_check_mark:

### Data structures

* Linked List
  * [Singly linked list](../code/include/data_structure/linked_list/singly_linked_list.hpp) :white_check_mark:
  * [Doubly linked list](../code/include/data_structure/linked_list/doubly_linked_list.hpp) :white_check_mark:
  
* Set
  * [Disjoint-set](../code/include/data_structure/set/disjoint_set.hpp) :white_check_mark:
  
* Tree
  * [Binary search tree](../code/include/data_structure/tree/binary_search_tree.hpp) :white_check_mark:

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

To know what happens in the background when **`make`** runs, you may read the [Makefile](../code/Makefile). For more information 
on **`make`**, read the [GNU make Manual](https://www.gnu.org/software/make/manual/make.html).

## Maintainers

This project is actively maintained by [@alxmjo](https://github.com/alxmjo), and inactively by [@faheel](https://github.com/faheel).

## License

This project is licensed under the terms of the [MIT license](LICENSE.md).

[travis-shield]: https://img.shields.io/travis/ProAlgos/ProAlgos-Cpp.svg?style=for-the-badge
[travis-link]: https://travis-ci.org/ProAlgos/ProAlgos-Cpp
[contrib-guide]: CONTRIBUTING.md
[up-for-grabs]: https://github.com/ProAlgos/ProAlgos-Cpp/labels/Up%20for%20grabs
