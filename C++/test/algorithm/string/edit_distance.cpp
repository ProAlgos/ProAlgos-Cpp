#include "third_party/catch.hpp"
#include "algorithm/string/edit_distance.hpp"

TEST_CASE("Base cases", "[string][edit_distance]"){
    REQUIRE(get_edit_distance("sunday", "") == 6);
    REQUIRE(get_edit_distance("", "sunday") == 6);
    REQUIRE(get_edit_distance("", "") == 0);
}

TEST_CASE("Normal cases", "[string][edit_distance]"){
    REQUIRE(get_edit_distance("sunday", "saturday") == 3);
    REQUIRE(get_edit_distance("food", "money") == 4);
    REQUIRE(get_edit_distance("code", "code") == 0);
    REQUIRE(get_edit_distance("plot", "plotting") == 4);
}

TEST_CASE("Large cases", "[string][edit_distance]"){
    REQUIRE(get_edit_distance("aaaaaaaaaaaaaaaaaaaaaaaXaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaXaaaaaaaaaaaaaaaaXaaaaaaaaaaaaaaaaaaaaXaaaaaaX") == 3);
    REQUIRE(get_edit_distance("abc*efghijklm---nopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLM+++NOPQRSTU*WXYZ") == 8);
}
