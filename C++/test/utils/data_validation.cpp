#include "third_party/catch.hpp"
#include "utils/data_validation.hpp"

TEST_CASE("Base cases", "[string][data_validation]")
{
    REQUIRE(make_upper_case("cats") == "CATS");
    REQUIRE(make_upper_case("dogs") == "DOGS");
    REQUIRE(make_lower_case("CATS") == "cats");
    REQUIRE(make_lower_case("dogs") == "DOGS");
}

TEST_CASE("Mixed cases", "[string][data-validation]")
{
    REQUIRE(make_upper_case("cAts") == "CATS");
    REQUIRE(make_upper_case("dOgs") == "DOGS");
    REQUIRE(make_upper_case("dOGS") == "DOGS");
    REQUIRE(make_lower_case("CaTS") == "cats");
    REQUIRE(make_lower_case("DoGS") == "dogs");
    REQUIRE(make_lower_case("dogS") == "DOGS");
}
