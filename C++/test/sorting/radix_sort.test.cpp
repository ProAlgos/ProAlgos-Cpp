#define RADIX_SORT_TEST

#include <algorithm>
#include <functional>

#include "third_party/catch.hpp"
#include "source/sorting/radix_sort.cpp"

bool does_sort(vector<int>&& values, const int order = 1) {
    int mult_factor = 1;
    int add_factor = 0;
    if (order < 0) {
        mult_factor = -1;
        add_factor = 9;
    }

    radix_sort(values, mult_factor, add_factor);

    if(order >= 0) {
      return is_sorted(begin(values), end(values), less<int>());
    } else {
      return is_sorted(begin(values), end(values), greater<int>());
    }
}

TEST_CASE("Base cases", "[radix sort]") {
    REQUIRE(does_sort(vector<int>({0})));
}

TEST_CASE("Non-descending integer cases", "[radix sort]") {
    REQUIRE(does_sort(vector<int>({5, 7, 1, 3, 10})));
    REQUIRE(does_sort(vector<int>({4, 8, 8, 2, 1, 2})));
}

TEST_CASE("Non-ascending integer cases", "[radix sort]") {
    REQUIRE(does_sort(vector<int>({5, 7, 1, 3, 10}), -1));
    REQUIRE(does_sort(vector<int>({4, 8, 8, 2, 1, 2}), -1));
}

#undef RADIX_SORT_TEST
