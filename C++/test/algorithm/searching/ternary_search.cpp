#include <cmath>

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
    int val;
    size_t expected_index = 0;
    if (!pattern) {
        val = std::numeric_limits<int>::min();
        for (size_t i = 0; i < values.size(); i++) {
            if (val < values[i]){
                val = values[i];
                expected_index = i;
            }
        }
    } else {
        val = std::numeric_limits<int>::max();
        for (size_t i = 0; i < values.size(); i++) {
            if (val > values[i]){
                val = values[i];
                expected_index = i;
            }
        }
    }
    return expected_index;
}


int ascending_descending_func_int(int x) {
    return -(x - 2) * (x - 2);
}

int descending_ascending_func_int(int x) {
    return (x - 5) * (x - 5) * (x - 5) * (x - 5);
}

float ascending_descending_func_float(float x) {
    return -(x - 9.0f) * (x - 9.0f);
}

float descending_ascending_func_float(float x) {
    return (x - 0.5f) * (x - 0.5f) * (x - 0.5f) * (x - 0.5f);
}

TEST_CASE("Base cases", "[searching][ternary_search]") {
    REQUIRE(ternary_search(vector<int>({5}),  ASCEND_THEN_DESCEND) == 0);
    REQUIRE(ternary_search(vector<int>({5}),  DESCEND_THEN_ASCEND) == 0);
    REQUIRE(ternary_search(vector<int>({-5}), ASCEND_THEN_DESCEND) == 0);
    REQUIRE(ternary_search(vector<int>({-5}), DESCEND_THEN_ASCEND) == 0);

    REQUIRE(ternary_search(vector<int>({4, 5}), ASCEND_THEN_DESCEND) == 1);
    REQUIRE(ternary_search(vector<int>({4, 5}), DESCEND_THEN_ASCEND) == 0);

    // Testing ternary search for integer range and ascending then descending functions
    REQUIRE(ternary_search(&ascending_descending_func_int, 2, 2, ASCEND_THEN_DESCEND) == 2);
    REQUIRE(ternary_search(&ascending_descending_func_int, 2, 3, ASCEND_THEN_DESCEND) == 2);
    REQUIRE(ternary_search([](int x){return -(x - 2) * (x - 2);}, 1, 2, ASCEND_THEN_DESCEND) == 2);
    REQUIRE(ternary_search([](int x){return -(x - 2) * (x - 2);}, -4, -3, ASCEND_THEN_DESCEND) == -3);

    // Testing ternary search for integer range and descending then ascending functions
    REQUIRE(ternary_search(&descending_ascending_func_int, 5, 5, DESCEND_THEN_ASCEND) == 5);
    REQUIRE(ternary_search(&descending_ascending_func_int, 5, 6, DESCEND_THEN_ASCEND) == 5);
    REQUIRE(ternary_search([](int x){return (x - 5) * (x - 5) * (x - 5) * (x - 5);}, 4, 5, DESCEND_THEN_ASCEND) == 5);
    REQUIRE(ternary_search([](int x){return (x - 5) * (x - 5) * (x - 5) * (x - 5);}, 12, 13, DESCEND_THEN_ASCEND) == 12);

    // Testing ternary search for float range and ascending then descending functions
    REQUIRE(ternary_search(&ascending_descending_func_float, 9.0, 9.0, ASCEND_THEN_DESCEND, 10e-9) == Approx(9.0));
    REQUIRE(ternary_search(&ascending_descending_func_float, 8.0, 9.0, ASCEND_THEN_DESCEND, 10e-9) == Approx(9.0));
    REQUIRE(ternary_search([](float x){return -(x - 9.0f) * (x - 9.0f);}, 9.0, 10.0, ASCEND_THEN_DESCEND, 10e-9) == Approx(9.0));
    REQUIRE(ternary_search([](float x){return -(x - 9.0f) * (x - 9.0f);}, -4.0, -3.0, ASCEND_THEN_DESCEND, 10e-9) == Approx(-3.0));

    // Testing ternary search for float range and descending then ascending functions
    REQUIRE(ternary_search(&descending_ascending_func_float, 0.5, 0.5, DESCEND_THEN_ASCEND, 10e-9) == Approx(0.5));
    REQUIRE(ternary_search(&descending_ascending_func_float, 0.4, 0.5, DESCEND_THEN_ASCEND, 10e-9) == Approx(0.5));
    REQUIRE(ternary_search([](float x){return (x - 0.5f) * (x - 0.5f) * (x - 0.5f) * (x - 0.5f);}, 0.5, 0.6, DESCEND_THEN_ASCEND, 10e-9) == Approx(0.5));
    REQUIRE(ternary_search([](float x){return (x - 0.5f) * (x - 0.5f) * (x - 0.5f) * (x - 0.5f);}, 2.2, 2.3, DESCEND_THEN_ASCEND, 10e-9) == Approx(2.2));
}

TEST_CASE("Normal cases", "[searching][ternary_search]") {
    vector<int> values;
    Pattern pattern;
    size_t expected_index;
    for (int test = 0; test < 20; test++) {
        if (bool(nextRand24() % 2)) {
            pattern = DESCEND_THEN_ASCEND;
        }
        else {
            pattern = ASCEND_THEN_DESCEND;
        }
        values = nextRandUnimodal(nextRand24() % 1000, pattern);
        expected_index = get_expected_index(values, pattern);
        REQUIRE(ternary_search(values, pattern) == expected_index);
    }

    REQUIRE(ternary_search([](int x){return -(x - 150) * (x - 150);}, 0, 400, ASCEND_THEN_DESCEND) == 150);
    REQUIRE(ternary_search([](float x){return (x + 351) * (x + 351);}, -1250, 5689, DESCEND_THEN_ASCEND) == -351);

    REQUIRE(ternary_search([](double d){return sin(d);}, 0.0, M_PI, ASCEND_THEN_DESCEND, 10e-9) == Approx(M_PI_2));
    REQUIRE(ternary_search([](double d){return cos(d);}, 0.0, 2.0 * M_PI, DESCEND_THEN_ASCEND, 10e-9) == Approx(M_PI));
    REQUIRE(ternary_search([](double d){return tan(d);}, -M_PI/4, M_PI/4, ASCEND_THEN_DESCEND, 10e-9) == Approx(M_PI/4));

    REQUIRE(ternary_search([](float d){return (d <= -2.1f) ? d * 5.5f :-16.2f - d * 2.5f;}, -4509.0f, 240.878f, ASCEND_THEN_DESCEND, 10e-9f) == Approx(-2.1f));
    REQUIRE(ternary_search([](float d){return (d <= 3.2f) ? - d * 3.0f :-13.44f + d * 1.2f;}, -25.2f, 240.3f, DESCEND_THEN_ASCEND, 10e-9f) == Approx(3.2f));
}
