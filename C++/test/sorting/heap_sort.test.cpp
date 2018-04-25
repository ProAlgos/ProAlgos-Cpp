#define HEAP_SORT_TEST

#include <algorithm>
#include <functional>

#include "third_party/catch.hpp"
#include "source/sorting/heap_sort.cpp"

bool does_sort(vector<int>&& values) {
    make_heap(values, values.size());
    heap_sort(values, values.size());

    // Heap sort interface always sorts non-descending
    return is_sorted(begin(values), end(values));
}

TEST_CASE("Base cases", "[heap sort]") {
    REQUIRE(does_sort(vector<int>({0})));
}

TEST_CASE("Non-descending integer cases", "[heap sort]") {
    REQUIRE(does_sort(vector<int>({5, 7, 1, 3, 10})));
    REQUIRE(does_sort(vector<int>({5, -5, 0, 8, -14})));
    REQUIRE(does_sort(vector<int>({4, 8, 8, 2, 1, 2})));
}

#undef HEAP_SORT_TEST
