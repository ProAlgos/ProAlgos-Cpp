#define TERNARY_SEARCH_TEST
#define CATCH_CONFIG_MAIN

#include "third_party/catch.hpp"
#include "source/searching/ternary_search.cpp"
#include <bits/stdc++.h>

unsigned int cur = 0;
unsigned int a = 13674324, b = 1233;
unsigned int nextRand24() {
    cur = cur * a + b;
    return cur >> 8;
}

vector <int> nextRandUnimodal(int sz, bool pattern) {
	vector <int> res;
	res.clear();
	int prev = nextRand24() % 1000;
	if (!pattern) prev *= -1;
	res.push_back(prev);
	int md;
	bool was = false;
	if (!pattern) md = 1; else md = -1;
	for (int i = 0; i < sz; i++) {
		int del = (nextRand24() % 15) * md;
		prev += del;
		res.push_back(prev);
		if (i > sz / 2 + nextRand24() % 15 && !was) {
			md *= -1;
			was = true;
		}
	}
	return res;
}


int solve(vector <int> &Vect, bool pattern) {
    if (!pattern) {
        int ans = -1e9;
        for (int i : Vect) ans = max(ans, i);
    } else {
        int ans = 1e9;
        for (int i : Vect) ans = min(ans, i);
    }
    return ans;
}

TEST_CASE("Base cases", "[ternary search]") {
    REQUIRE(ternary_search(vector <int> ({-5}), false) == -5);
    REQUIRE(ternary_search(vector <int> ({5}), true) == 5);
}

TEST_CASE("Integer cases", "[ternary search]") {
    for (int i = 0; i < 10; i++) {
        bool pattern = bool(nextRand24() % 2);
        vector <int> a = nextRandUnimodal(nextRand24() % 1000), pattern);
        int answer = solve(a, pattern);
        REQUIRE(ternary_search(a, pattern) == answer);
    }
}
