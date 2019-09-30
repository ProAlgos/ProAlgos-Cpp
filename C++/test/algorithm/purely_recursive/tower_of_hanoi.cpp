#include "third_party/catch.hpp"
#include "include/algorithm/purely_recursive/tower_of_hanoi.hpp"

TEST_CASE("Base cases", "[purely_recursive][tower_of_hanoi]") {
    REQUIRE(tower_of_hanoi(3, 'A', 'B', 'C') == 7);
    REQUIRE(tower_of_hanoi(6, 'A', 'B', 'C') == 63);
    REQUIRE(tower_of_hanoi(10, 'A', 'B', 'C') == 1023);
    REQUIRE(tower_of_hanoi(11, 'A', 'B', 'C') == 2047);
    REQUIRE(tower_of_hanoi(3, 'A', 'B', 'C') == 1048575);
}
