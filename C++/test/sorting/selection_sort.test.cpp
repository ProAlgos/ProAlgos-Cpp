#define SELECTION_SORT_TEST

#include <algorithm>
#include <functional>

#include "third_party/catch.hpp"
#include "source/sorting/selection_sort.cpp"

bool does_sort(vector<int>&& values, const int order = 1) {
    selection_sort(values, order);

    if(order >= 0) {
      return is_sorted(begin(values), end(values), less<int>());
    } else {
      return is_sorted(begin(values), end(values), greater<int>());
    }
}

TEST_CASE("Base cases", "[selection sort]") {
    REQUIRE(does_sort(vector<int>({0})));
}

TEST_CASE("Non-descending integer cases", "[selection sort]") {
    REQUIRE(does_sort(vector<int>({5, 7, 1, 3, 10})));
    REQUIRE(does_sort(vector<int>({5, -5, 0, 8, -14})));
    REQUIRE(does_sort(vector<int>({4, 8, 8, 2, 1, 2})));
}

TEST_CASE("Non-ascending integer cases", "[selection sort]") {
    REQUIRE(does_sort(vector<int>({5, 7, 1, 3, 10}), -1));
    REQUIRE(does_sort(vector<int>({5, -5, 0, 8, -14}), -1));
    REQUIRE(does_sort(vector<int>({4, 8, 8, 2, 1, 2}), -1));
}

#undef SELECTION_SORT_TEST
