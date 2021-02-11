#include "third_party/catch.hpp"
#include "algorithm/dynamic_programming/optimal_coin_game_strategy.hpp"
using std::vector;

TEST_CASE("Base Cases", "[optimal coin game strategy]") {
    OptimalCoinGameSolver solver(vector<LL>({ 1 }));
    REQUIRE(solver.solve() == 1);
}
TEST_CASE("Simple Cases", "[optimal coin game strategy]") {
    {
        OptimalCoinGameSolver solver(vector<LL>({ 5,3,7,10 }));
        REQUIRE(solver.solve() == 15);
    } 
    {
        OptimalCoinGameSolver solver(vector<LL>({ 8,15,3,7 }));
        REQUIRE(solver.solve() == 22);
    }
}
