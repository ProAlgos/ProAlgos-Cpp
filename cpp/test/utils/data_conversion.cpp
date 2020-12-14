#include "third_party/catch.hpp"
#include "utils/data_conversion.hpp"

#define NAME_SPACE "[utils][data-conversion][make_upper_case]"

TEST_CASE("Base cases",  NAME_SPACE) {
    REQUIRE(make_upper_case(" ") == " ");
    REQUIRE(make_upper_case("1234567890") == "1234567890");
    REQUIRE(make_upper_case("!@#$%^&*()_+±~<>.,|':;") == "!@#$%^&*()_+±~<>.,|':;");
    REQUIRE(make_lower_case(" ") == " ");
    REQUIRE(make_lower_case("1234567890") == "1234567890");
    REQUIRE(make_lower_case("!@#$%^&*()_+±~<>.,|':;") == "!@#$%^&*()_+±~<>.,|':;");
}

TEST_CASE("Convert to upper case", NAME_SPACE) {
    REQUIRE(make_upper_case("hello") == "HELLO");
    REQUIRE(make_upper_case("world") == "WORLD");
    REQUIRE(make_upper_case("GITHUB") == "GITHUB");
    REQUIRE(make_upper_case("Cpp") == "CPP");
    REQUIRE(make_upper_case("Hello World!") == "HELLO WORLD!");
    REQUIRE(make_upper_case("Hello\nWorld!") == "HELLO\nWORLD!");
}

TEST_CASE("Convert to lower case", NAME_SPACE) {
    REQUIRE(make_lower_case("HELLO") == "hello");
    REQUIRE(make_lower_case("WORLD") == "world");
    REQUIRE(make_lower_case("github") == "github");
    REQUIRE(make_lower_case("Cpp") == "cpp");
    REQUIRE(make_lower_case("Hello World!") == "hello world!");
    REQUIRE(make_lower_case("Hello\nWorld!") == "hello\nworld!");
}
