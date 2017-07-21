#define FIBONACCI_TEST
#define CATCH_CONFIG_MAIN

#include "third_party/catch.hpp"
#include "source/number_theory/fibonacci.cpp"

TEST_CASE("Base cases", "[fibonacci]") {
    REQUIRE(fibonacci(0) == 0);
    REQUIRE(fibonacci(1) == 1);
}

TEST_CASE("Normal cases", "[fibonacci]") {
    REQUIRE(fibonacci(2) == 1);
    REQUIRE(fibonacci(7) == 13);
    REQUIRE(fibonacci(15) == 610);
    REQUIRE(fibonacci(18) == 2584);
    REQUIRE(fibonacci(23) == 28657);
    REQUIRE(fibonacci(50) == 12586269025);
    REQUIRE(fibonacci(93) == 12200160415121876738U);
}

TEST_CASE("Overflow cases", "[fibonacci]") {
    REQUIRE(fibonacci(94) == 1293530146158671551U);
    REQUIRE(fibonacci(1500) == 13173307912845686352U);
}

#undef FIBONACCI_TEST
