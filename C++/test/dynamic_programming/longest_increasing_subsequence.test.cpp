#define LONGEST_INCREASING_SUBSEQUENCE_TEST

#include "third_party/catch.hpp"
#include "source/dynamic_programming/longest_increasing_subsequence.cpp"

TEST_CASE( "Vector has single element" , "[longest_increasing_subsequence]" ) {
    vector<int> a = {5};
    vector<int> expected_lis = {5};
    vector<int> lis = longest_increasing_subsequence(a);
    SECTION("Size is as expected") {
        REQUIRE(lis.size() == expected_lis.size());
    }
    for(int i = 0; i < (int)lis.size(); i++) {
        SECTION("Checking value at index " + i) {
            REQUIRE(lis[i] == expected_lis[i]);
        }
    }
}

TEST_CASE( "Vector has all elements in ascending order" , "[longest_increasing_subsequence]" ) {
    vector<int> a = {5, 8, 10, 56, 135, 199, 201};
    vector<int> expected_lis = {5, 8, 10, 56, 135, 199, 201};
    vector<int> lis = longest_increasing_subsequence(a);
    SECTION("Size is as expected") {
        REQUIRE(lis.size() == expected_lis.size());
    }
    for(int i = 0; i < (int)lis.size(); i++) {
        SECTION("Checking value at index " + i) {
            REQUIRE(lis[i] == expected_lis[i]);
        }
    }
}

TEST_CASE( "Vector has all elements in descending order" , "[longest_increasing_subsequence]" ) {
    vector<int> a = {946, 865, 345, 129, 76, 34, 5, 2};
    vector<int> expected_lis = {946};
    vector<int> lis = longest_increasing_subsequence(a);
    SECTION("Size is as expected") {
        REQUIRE(lis.size() == expected_lis.size());
    }
    for(int i = 0; i < (int)lis.size(); i++) {
        SECTION("Checking value at index " + i) {
            REQUIRE(lis[i] == expected_lis[i]);
        }
    }
}

TEST_CASE( "Vector has all elements same" , "[longest_increasing_subsequence]" ) {
    vector<int> a = {5, 5, 5, 5, 5, 5, 5};
    vector<int> expected_lis = {5};
    vector<int> lis = longest_increasing_subsequence(a);
    SECTION("Size is as expected") {
        REQUIRE(lis.size() == expected_lis.size());
    }
    for(int i = 0; i < (int)lis.size(); i++) {
        SECTION("Checking value at index " + i) {
            REQUIRE(lis[i] == expected_lis[i]);
        }
    }
}

TEST_CASE( "Normal testcase" , "[longest_increasing_subsequence]" ) {
    vector<int> a = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> expected_lis = {2, 3, 7, 101};
    vector<int> lis = longest_increasing_subsequence(a);
    SECTION("Size is as expected") {
        REQUIRE(lis.size() == expected_lis.size());
    }
    for(int i = 0; i < (int)lis.size(); i++) {
        SECTION("Checking value at index " + i) {
            REQUIRE(lis[i] == expected_lis[i]);
        }
    }
}

TEST_CASE( "Vector has some negative numbers" , "[longest_increasing_subsequence]" ) {
    vector<int> a = {-11, 5, -3, 2, 8, 56, -1};
    vector<int> expected_lis = {-11, -3, 2, 8, 56};
    vector<int> lis = longest_increasing_subsequence(a);
    SECTION("Size is as expected") {
        REQUIRE(lis.size() == expected_lis.size());
    }
    for(int i = 0; i < (int)lis.size(); i++) {
        SECTION("Checking value at index " + i) {
            REQUIRE(lis[i] == expected_lis[i]);
        }
    }
}

TEST_CASE( "Vector has all negative numbers" , "[longest_increasing_subsequence]" ) {
    vector<int> a = {-10, -9, -2, -5, -3, -7, -101, -18};
    vector<int> expected_lis = {-10, -9, -5, -3};
    vector<int> lis = longest_increasing_subsequence(a);
    SECTION("Size is as expected") {
        REQUIRE(lis.size() == expected_lis.size());
    }
    for(int i = 0; i < (int)lis.size(); i++) {
        SECTION("Checking value at index " + i) {
            REQUIRE(lis[i] == expected_lis[i]);
        }
    }
}

#undef LONGEST_INCREASING_SUBSEQUENCE_TEST
