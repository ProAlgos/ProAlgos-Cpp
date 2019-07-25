cmake_minimum_required(VERSION 3.0)

project(Algos)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include_directories(include)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-g -O0 -Wall -Wextra -pedantic-errors")

# Test runner
add_library(test_runner STATIC
        test/test_runner.cpp)

# ============================================================================
# Algorithms
# ============================================================================

# -------------------
# Dynamic programming
# -------------------

# Matrix chain multiplication
add_executable(matrix_chain_multiplication
        test/algorithm/dynamic_programming/matrix_chain_multiplication.cpp)
target_link_libraries(matrix_chain_multiplication test_runner)

# 0-1 knapsack
add_executable(0_1_knapsack
        test/algorithm/dynamic_programming/0_1_knapsack.cpp)
target_link_libraries(0_1_knapsack test_runner)

# Kadane's
add_executable(kadane
        test/algorithm/dynamic_programming/kadane.cpp)
target_link_libraries(kadane test_runner)

# -------------
# Number theory
# -------------

# Binomial coefficient
add_executable(binomial_coefficient
        test/algorithm/number_theory/binomial_coefficient.cpp)
target_link_libraries(binomial_coefficient test_runner)

# Extended Euclidean
add_executable(extended_euclidean
        test/algorithm/number_theory/extended_euclidean.cpp)
target_link_libraries(extended_euclidean test_runner)

# Fast exponentiation
add_executable(fast_exponentiation
        test/algorithm/number_theory/fast_exponentiation.cpp)
target_link_libraries(fast_exponentiation test_runner)

# Fibonacci
add_executable(fibonacci
        test/algorithm/number_theory/fibonacci.cpp)
target_link_libraries(fibonacci test_runner)

# Fibonacci efficient
add_executable(fibonacci_efficient
        test/algorithm/number_theory/fibonacci_efficient.cpp)
target_link_libraries(fibonacci_efficient test_runner)

# Greatest common divisor
add_executable(greatest_common_divisor
        test/algorithm/number_theory/greatest_common_divisor.cpp)
target_link_libraries(greatest_common_divisor test_runner)

# Perfect number check
add_executable(perfect_number_check
        test/algorithm/number_theory/perfect_number_check.cpp)
target_link_libraries(perfect_number_check test_runner)

# Sieve of Eratosthenes
add_executable(sieve_of_eratosthenes
        test/algorithm/number_theory/sieve_of_eratosthenes.cpp)
target_link_libraries(sieve_of_eratosthenes test_runner)

# ---------
# Searching
# ---------

# Binary search
add_executable(binary_search
        test/algorithm/searching/binary_search.cpp)
target_link_libraries(binary_search test_runner)

# Linear search
add_executable(linear_search
        test/algorithm/searching/linear_search.cpp)
target_link_libraries(linear_search test_runner)

# Ternary search
add_executable(ternary_search
        test/algorithm/searching/ternary_search.cpp)
target_link_libraries(ternary_search test_runner)

# -------
# Sorting
# -------

add_executable(sorting
        test/algorithm/sorting/sorting.cpp)
target_link_libraries(sorting test_runner)

# ------
# String
# ------

# Edit distance Problem
add_executable(edit_distance
        test/algorithm/string/edit_distance.cpp)
target_link_libraries(edit_distance test_runner)

# Longest common subsequence
add_executable(longest_common_subsequence
        test/algorithm/string/longest_common_subsequence.cpp)
target_link_libraries(longest_common_subsequence test_runner)

# Knuth-Morris-Pratt
add_executable(knuth_morris_pratt
        test/algorithm/string/knuth_morris_pratt.cpp)
target_link_libraries(knuth_morris_pratt test_runner)

# ============================================================================
# Data structures
# ============================================================================

# -----------
# Linked list
# -----------

# Singly-linked list
add_executable(singly_linked_list
        test/data_structure/linked_list/singly_linked_list.cpp)
target_link_libraries(singly_linked_list test_runner)

# Doubly-linked list
add_executable(doubly_linked_list
        test/data_structure/linked_list/doubly_linked_list.cpp)
target_link_libraries(doubly_linked_list test_runner)

# ---
# Set
# ---

# Disjoint set
add_executable(disjoint_set
        test/data_structure/set/disjoint_set.cpp)
target_link_libraries(disjoint_set test_runner)

# ----
# Tree
# ----

# Binary search tree
add_executable(binary_search_tree
        test/data_structure/tree/binary_search_tree.cpp)
target_link_libraries(binary_search_tree test_runner)
