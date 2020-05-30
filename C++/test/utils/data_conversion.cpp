#include "third_party/catch.hpp"
#include "utils/data_conversion.hpp"

TEST_CASE("Make upper case", "[string][data_conversion][make-upper-case]")
{
    REQUIRE(make_upper_case("cats") == "CATS");
    REQUIRE(make_upper_case("dogs") == "DOGS");
    REQUIRE(make_upper_case("s3Cret") == "S3CRET");
    REQUIRE(make_upper_case(" ") == " ");
    REQUIRE(make_upper_case("c") == "C");
    REQUIRE(make_upper_case("#er$T") == ("#ER$T"));
}

TEST_CASE("Make lower case", "[string][data_conversion][make-lower-case]")
{
    REQUIRE(make_lower_case("CaTS") == "cats");
    REQUIRE(make_lower_case("DoGS") == "dogs");
    REQUIRE(make_lower_case("dogS") == "DOGS");
    REQUIRE(make_lower_case("A@#B$%C") == "a@#b$%c");
    REQUIRE(make_lower_case(" ") == " ");
    REQUIRE(make_lower_case("F") == "f");
}
