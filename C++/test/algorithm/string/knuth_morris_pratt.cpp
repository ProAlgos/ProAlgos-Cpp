#include "third_party/catch.hpp"
#include "algorithm/string/knuth_morris_pratt.hpp"

TEST_CASE("Base cases", "[string][knuth_morris_pratt]") {
    vector<int> a = { };
    REQUIRE(search("", "") == a);
    vector<int> b = { 0 };
    REQUIRE(search("a", "a") == b);
    vector<int> c = { 0 };
    REQUIRE(search("1", "1") == c);
}

TEST_CASE("Single cases", "[string][knuth_morris_pratt]") {
    vector<int> a = { 0 };
    REQUIRE(search("Sun", "Sunday") == a);
    vector<int> b = { 4 };
    REQUIRE(search("horse", "Wildhorse") == b);
    vector<int> c = { 6 };
    REQUIRE(search("you", "Won't you be my neighbor?") == c);
    vector<int> d = { 7 };
    REQUIRE(search("g", "Lady Gaga") == d);
}

TEST_CASE("Multiple cases", "[string][knuth_morris_pratt]") {
    vector<int> a = {4, 9};
    REQUIRE(search("a", "Michael Jackson") == a);
    vector<int> b = {1, 5};
    REQUIRE(search("u", "autobus") == b);
    vector<int> c = {0, 7};
    REQUIRE(search("sn", "snickersnee") == c);
}
