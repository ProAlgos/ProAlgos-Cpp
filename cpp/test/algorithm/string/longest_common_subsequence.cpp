#include "third_party/catch.hpp"
#include "algorithm/string/longest_common_subsequence.hpp"

TEST_CASE("Base cases", "[string][longest_common_subsequence]"){
    REQUIRE(get_lcs("sunday", "") == "");
    REQUIRE(get_lcs("", "sunday") == "");
    REQUIRE(get_lcs("", "") == "");
}

TEST_CASE("Lower alphabetical cases", "[string][longest_common_subsequence]"){
    REQUIRE(get_lcs("cats", "dogs") == "s");
    REQUIRE(get_lcs("cats", "ctss") == "cts");
    REQUIRE(get_lcs("cats", "cross") == "cs");
}

TEST_CASE("Upper alphabetical cases", "[string][longest_common_subsequence]"){
    REQUIRE(get_lcs("CATS", "DOGS") == "S");
    REQUIRE(get_lcs("CATS", "CTSS") == "CTS");
    REQUIRE(get_lcs("CATS", "CROSS") == "CS");
}

TEST_CASE("Mixed alphabetical cases", "[string][longest_common_subsequence]"){
    REQUIRE(get_lcs("caTS", "dogs") == "");
    REQUIRE(get_lcs("cAts", "catss") == "cts");
    REQUIRE(get_lcs("cats", "CROsS") == "s");
}

TEST_CASE("Numerical cases", "[string][longest_common_subsequence]"){
    REQUIRE(get_lcs("123456", "136") == "136");
    REQUIRE(get_lcs("111", "123") == "1");
    REQUIRE(get_lcs("2849", "992719") == "29");
}

TEST_CASE("Mixed numerical and alphabetical cases", "[string][longest_common_subsequence]"){
    REQUIRE(get_lcs("c344ats", "do4gs") == "4s");
    REQUIRE(get_lcs("cats2937", "2937ctss") == "2937");
    REQUIRE(get_lcs("catsg777g", "cross77") == "cs77");
}

TEST_CASE("Random long cases", "[string][longest_common_subsequence]"){
    REQUIRE(get_lcs("189oi3n4oinoi34nuf79b39yb49b973b4f9fb9374bf993nfi293fn28", "guu37hngn83n") == "u37nn8");
    REQUIRE(get_lcs("img82n4f8u939fn93n97h7rgb9737g937rbg9739j9jed98jng82jng", "g38jendungud") == "g38jnng");
    REQUIRE(get_lcs("38jgjsg3j98j8j8hg8hs9f7dhg9d7fhg2r08jgefgnouefgne8282jf8g", "i2ijgh3unvnh") == "2jgun");
}

TEST_CASE("Special character cases", "[string][longest_common_subsequence]"){
    REQUIRE(get_lcs("@(&#(@&&@", "@($&%&@(&#") == "@(&&@");
    REQUIRE(get_lcs("@(&#(@&&@", "(%*#(@*&!)") == "(#(@&");
    REQUIRE(get_lcs("@(&#(@&&@", "@(#()*%&#&") == "@(#(&&");
}
