#define GCD_TEST

#include "third_party/catch.hpp"
#include "source/number_theory/gcd.cpp"

TEST_CASE("Base cases", "[gcd]") {
	//gcd(0,0) is undefined
    REQUIRE(gcd(0,1) == 1);
    REQUIRE(gcd(1,0) == 1);
}

TEST_CASE("Normal cases", "[gcd]") {
	REQUIRE(gcd(48,92) == 4);
	REQUIRE(gcd(101,39) == 1);
	REQUIRE(gcd(1000,400) == 200);
	REQUIRE(gcd(10005,2505) == 15);
	REQUIRE(gcd(999999999,333333) == 333);
	//999999999 (9.99*10^9) is the limit
}

#undef GCD_TEST