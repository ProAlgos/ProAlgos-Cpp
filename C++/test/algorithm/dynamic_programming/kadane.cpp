#include "third_party/catch.hpp"
#include "algorithm/dynamic_programming/kadane.hpp"

#include <tuple>
#include <vector>

using std::tuple;
using std::vector;

TEST_CASE("Base case", "[dynamic_programming][maximum_subarray][kadane]") {
    vector<int> a_vector = { 0 };
    tuple<int, size_t, size_t> a_tuple = make_tuple(0, 0, 0);
    REQUIRE(maximumSubarray(a_vector) == a_tuple);
}

TEST_CASE("Normal cases", "[dynamic_programming][maximum_subarray][kadane]") {
    vector<int> a_vector = { 1, 2, 3 };
    tuple<int, size_t, size_t> a_tuple = make_tuple(6, 0, 2);
    REQUIRE(maximumSubarray(a_vector) == a_tuple);

    vector<int> b_vector = { 1, -2, 3 };
    tuple<int, size_t, size_t> b_tuple = make_tuple(3, 2, 2);
    REQUIRE(maximumSubarray(b_vector) == b_tuple);

    vector<int> c_vector = { 0, -1, 12, 14, -32, 11, 17 };
    tuple<int, size_t, size_t> c_tuple = make_tuple(28, 5, 6);
    REQUIRE(maximumSubarray(c_vector) == c_tuple);

    vector<int> d_vector = { 19, 2, 13, -99, -1, 14, 33, 211, -33, 17 };
    tuple<int, size_t, size_t> d_tuple = make_tuple(258, 5, 7);
    REQUIRE(maximumSubarray(d_vector) == d_tuple);
}
