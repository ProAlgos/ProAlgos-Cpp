#define STRING_SPLIT_TEST

#include "utility/string.hpp"
#include "third_party/catch.hpp"


TEST_CASE("Split string", "[utility][string][split_string]") {
    std::vector<std::string> strings = {
        "1,2,3,4,5,6,7,8,9,10,11,12,13",
        "This-is-a-hyphen-seperated-string",
        "Hello there! How are you"
        // add more strings to test here
    }

    std::vector<char> delimiters = {
        ',','-',' '
        // add delimiters to split the above strings here
    }

    std::vector<std::vector<std::string>> expected_lists = {
        { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13" },
        { "This", "is", "a", "hyphen", "seperated", "string" },
        { "Hello", "there!", "How", "are", "you" }
        // add expected results for the above strings here
    }

    for (size_t i = 0; i < strings.size(); i++)
        REQUIRE(split_string(strings[i], delimiters[i]) == expected_lists[i]);
}

#undef STRING_SPLIT_TEST
