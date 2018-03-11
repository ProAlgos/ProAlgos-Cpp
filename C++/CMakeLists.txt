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

# ============================================================================
# Data structures
# ============================================================================

# Disjoint set
add_executable(disjoint_set
        test/data_structure/disjoint_set.cpp)
target_link_libraries(disjoint_set test_runner)
