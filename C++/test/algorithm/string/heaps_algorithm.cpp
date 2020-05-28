#define CATCH_CONFIG_MAIN
#include "third_party/catch.hpp"
#include "algorithm/string/heaps_algorithm.hpp"


TEST_CASE("Base cases", "[string][heaps_algorithm]") {
    vector<string> output_1;
    string s = ""; // empty string
    vector<string> permutations = {""};
    REQUIRE(heaps_algorithm(s.length(), s, output_1) == permutations);
    
    vector<string> output_2;
    s = "a";
    permutations = {"a"};
    REQUIRE(heaps_algorithm(s.length(), s, output_2) == permutations);
    
    vector<string> output_3;
    s = " ";
    permutations = {" "};
    REQUIRE(heaps_algorithm(s.length(), s, output_3) == permutations);
}


TEST_CASE("short cases", "[string][heaps_algorithm]") {
    vector<string> output_4;
    string s = "abc";
    vector<string> permutations = {"abc", "bac", "cab", "acb", "bca", "cba"};
    REQUIRE(heaps_algorithm(s.length(), s, output_4) == permutations);

    vector<string> output_5;
    s = "a$1";
    permutations = {"a$1", "$a1", "1a$", "a1$", "$1a", "1$a"};
    REQUIRE(heaps_algorithm(s.length(), s, output_5) == permutations);
}

TEST_CASE("long cases", "[string][heaps_algorithm]") {
    vector<string> output_6;
    string s = "1_#c";
    vector<string> permutations = {"1_#c", "_1#c", "#1_c", "1#_c", "_#1c", "#_1c", "c_1#", "_c1#", "1c_#", "c1_#", "_1c#", "1_c#", "1#c_", "#1c_", "c1#_", "1c#_", "#c1_", "c#1_", "c#_1", "#c_1", "_c#1", "c_#1", "#_c1", "_#c1"};
    REQUIRE(heaps_algorithm(s.length(), s, output_6) == permutations);
}
