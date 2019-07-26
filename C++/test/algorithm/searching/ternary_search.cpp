#include <algorithm>

#include "third_party/catch.hpp"
#include "algorithm/searching/ternary_search.hpp"

using std::vector;

/*
    TODO: refactor
*/

unsigned int cur = 0;
unsigned int a = 13674324, b = 1233;

unsigned int nextRand24() {
    cur = cur * a + b;
    return cur >> 8;
}

vector<int> nextRandUnimodal(int size, const bool pattern) {
    vector<int> res;
    res.clear();
    int prev = nextRand24() % 1000;
    if (!pattern) prev *= -1;
    res.push_back(prev);
    int md;
    bool was = false;
    if (!pattern) md = 1; else md = -1;
    for (int i = 0; i < size; i++) {
        int del = (nextRand24() % 15) * md;
        prev += del;
        res.push_back(prev);
        if (i > size / 2 + (int)nextRand24() % 15 && !was) {
            md *= -1;
            was = true;
        }
    }
    return res;
}

size_t get_expected_index(const vector<int>& values, const bool pattern) {
    int val, expected_index;
    if (!pattern) {
        val = -1e9;
        for (size_t i = 0; i < values.size(); i++) {
            if (val < values[i]){
                val = values[i];
                expected_index = i;
            }
        }
    } else {
        val = 1e9;
        for (size_t i = 0; i < values.size(); i++) {
            if (val > values[i]){
                val = values[i];
                expected_index = i;
            }
        }
    }
    return expected_index;
}

TEST_CASE("Base cases", "[searching][ternary_search]") {
    REQUIRE(ternary_search(vector<int>({5}),  ASCEND_THEN_DESCEND) == 0);
    REQUIRE(ternary_search(vector<int>({5}),  DESCEND_THEN_ASCEND) == 0);
    REQUIRE(ternary_search(vector<int>({-5}), ASCEND_THEN_DESCEND) == 0);
    REQUIRE(ternary_search(vector<int>({-5}), DESCEND_THEN_ASCEND) == 0);

    REQUIRE(ternary_search(vector<int>({4, 5}), ASCEND_THEN_DESCEND) == 1);
    REQUIRE(ternary_search(vector<int>({4, 5}), DESCEND_THEN_ASCEND) == 0);
}

TEST_CASE("Normal cases", "[searching][ternary_search]") {
    vector<int> values;
    Pattern pattern;
    size_t expected_index;
    for (int test = 0; test < 20; test++) {
        if (bool(nextRand24() % 2))
            pattern = DESCEND_THEN_ASCEND;
        else
            pattern = ASCEND_THEN_DESCEND;
        values = nextRandUnimodal(nextRand24() % 1000, pattern);
        expected_index = get_expected_index(values, pattern);
        REQUIRE(ternary_search(values, pattern) == expected_index);
    }
}
