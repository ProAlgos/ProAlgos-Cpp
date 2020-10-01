#include "third_party/catch.hpp"
#include "algorithm/backtracking/all_permutations.hpp"

TEST_CASE("Base cases","[backtracking][all_permutations]"){
 string s =""; // empty string
 vector<string> permutations = {""};
 REQUIRE(all_permutations(s,0,s.length()-1) == permutations);

 s = "a";
 permutations = {"a"};
 REQUIRE(all_permutations(s,0,s.length()-1) == permutations); 
 
 s = " ";
 permutations = {" "};
 REQUIRE(all_permutations(s,0,s.length()-1) == permutations); 
}

 TEST_CASE("Normal cases",[backtracking][all_permutations]"){
 string s = "abc";
 vector<string> permutations = {"abc","acb","bac","bca","cab","cba"};
 REQUIRE(all_permutations(s,0,s.length()-1) == permutations);

 s = "abcd";
 permutations ={"abcd","abdc","acbd","acdb","adcb","adbc",
                "bacd","badc","bcad","bcda","bdca","bdac",
                "cbad","cbda","cabd","cadb","cdab","cdba",
                "dbca","dbac","dcba","dcab","dacb","dabc" };
 REQUIRE(all_permutations(s,0,s.length()-1) == permutations);
}