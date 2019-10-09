#include "third_party/catch.hpp"
#include "algorithm/number_theory/primorial_of_prime.hpp"

TEST_CASE("Normal cases","[primorial_of_prime]") {
    REQUIRE(primorial_of_prime(2) == 2);
    REQUIRE(primorial_of_prime(5) == 30);
    REQUIRE(primorial_of_prime(11) == 2310);
    REQUIRE(primorial_of_prime(13) == 30030);
    REQUIRE(primorial_of_prime(23) == 223092870);
    REQUIRE(primorial_of_prime(29) == 6469693230);
    REQUIRE(primorial_of_prime(37) == 7420738134810);
    REQUIRE(primorial_of_prime(43) == 13082761331670030);
    REQUIRE(primorial_of_prime(47) == 614889782588491410);
}

TEST_CASE("Overflow cases","[primorial_of_prime]") {
    REQUIRE(primorial_of_prime(53) == -1);
    REQUIRE(primorial_of_prime(88) == -1);
}