#define CATCH_CONFIG_MAIN
#include "third_party/catch.hpp"
#include "algorithm/dynamic_programming/Paintingfence.hpp"

using namespace std;

TEST_CASE("Base Cases", "[Paintingfence]") {
    REQUIRE(Paintingfence(1,0) == 0);
    REQUIRE(Paintingfence(0,1) == 0);
    REQUIRE(Paintingfence(1,1) == 1);
    REQUIRE(Paintingfence(1,2) == 2);
    REQUIRE(Paintingfence(3,2) == 6);
}

TEST_CASE("Simple Cases", "[Paintingfence]") {
    REQUIRE(Paintingfence(3,2) == 6);
}
