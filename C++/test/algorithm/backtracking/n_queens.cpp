#include "third_party/catch.hpp"
#include "algorithm/backtracking/n_queens.hpp"

TEST_CASE("Base cases", "[backtracking][n_queens]") {
    // N = 0 (cannot place)
    NQueensSolver b0(0);
    REQUIRE(b0.can_place_queens() == false);

    // N = 1 (can place)
    NQueensSolver b1(1);
    REQUIRE(b1.can_place_queens() == true);
    REQUIRE(b1.num_solutions() == 1);
    Board b1_sln {{true}};
    REQUIRE(b1.get_solution() == b1_sln);
    std::vector<Board> b1_slns {{{true}}};
    REQUIRE(b1.get_solutions() == b1_slns);
}

TEST_CASE("Unplaceable cases", "[backtracking][n_queens]") {
    // N = 2
    NQueensSolver b2(2);
    REQUIRE(b2.can_place_queens() == false);

    // N = 3
    NQueensSolver b3(3);
    REQUIRE(b3.can_place_queens() == false);
}

TEST_CASE("Placeable cases", "[backtracking][n_queens]") {
    // N = 4
    NQueensSolver b4(4);
    REQUIRE(b4.can_place_queens() == true);
    REQUIRE(b4.num_solutions() == 2);
    Board b4_sln1 {
        {false, true, false, false},
        {false, false, false, true},
        {true, false, false, false},
        {false, false, true, false}
    };
    Board b4_sln2 {
        {false, false, true, false},
        {true, false, false, false},
        {false, false, false, true},
        {false, true, false, false}
    };
    using Catch::Matchers::VectorContains;
    REQUIRE_THAT(b4.get_solutions(), VectorContains(b4_sln1));
    REQUIRE_THAT(b4.get_solutions(), VectorContains(b4_sln2));

    // N = 9
    NQueensSolver b9(9);
    REQUIRE(b9.can_place_queens() == true);
    REQUIRE(b9.num_solutions() == 352);

    // N = 11
    NQueensSolver b11(11);
    REQUIRE(b11.can_place_queens() == true);
    REQUIRE(b11.num_solutions() == 2680);
}
