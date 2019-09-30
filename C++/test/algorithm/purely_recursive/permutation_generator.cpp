#include "third_party/catch.hpp"
#include "include/algorithm/purely_recursive/permutation_generator.hpp";

using std::vector;

TEST_CASE("Base cases", "[purely_recursive][permutation_generator]") {
    REQUIRE(permutation(vector<char>({'A', 'B', 'C'}), 0, 3) == 6);
    REQUIRE(permutation(vector<char>({'A', 'B', 'C', 'D'}), 0, 4) == 24);
    REQUIRE(permutation(vector<char>({'A', 'B', 'C', 'D', 'E'}), 0, 5) == 120);
    REQUIRE(permutation(vector<char>({'A', 'B', 'C', 'D', 'E', 'F'}), 0, 6) == 720);
}
