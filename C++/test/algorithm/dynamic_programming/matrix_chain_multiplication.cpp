#include "third_party/catch.hpp"
#include "algorithm/dynamic_programming/matrix_chain_multiplication.hpp"


TEST_CASE("Base cases", "[matrix_chain_multiplication]") {
    MatrixChainMultiplier chain_multiplier;
    
    try {
        chain_multiplier = MatrixChainMultiplier({1});
    }
    catch (const std::invalid_argument& e) {
        CHECK(e.what() == std::string("You need to provide at least 4 dimension"
            "values, as there need to be atleast 3 matrices."));
    }
    
    try {
        chain_multiplier = MatrixChainMultiplier({20, 30});
    }
    catch (const std::invalid_argument& e) {
        CHECK(e.what() == std::string("You need to provide at least 4 dimension"
            "values, as there need to be atleast 3 matrices."));
    }
    
    try {
        chain_multiplier = MatrixChainMultiplier({10, 20, 30});
    }
    catch (const std::invalid_argument& e) {
        CHECK(e.what() == std::string("You need to provide at least 4 dimension"
            "values, as there need to be atleast 3 matrices."));
    }

    chain_multiplier = MatrixChainMultiplier({1, 2, 3, 4});
    REQUIRE(chain_multiplier.optimal_cost() == 18);
    REQUIRE(chain_multiplier.optimal_parenthesization() == "((AB)C)");
}

TEST_CASE("Normal cases", "[matrix_chain_multiplication]") {
    MatrixChainMultiplier chain_multiplier;

    chain_multiplier = MatrixChainMultiplier({100, 20, 50, 90});
    REQUIRE(chain_multiplier.optimal_cost() == 270000);
    REQUIRE(chain_multiplier.optimal_parenthesization() == "(A(BC))");

    chain_multiplier = MatrixChainMultiplier({40, 30, 20, 10, 30});
    REQUIRE(chain_multiplier.optimal_cost() == 30000);
    REQUIRE(chain_multiplier.optimal_parenthesization() == "((A(BC))D)");

    chain_multiplier = MatrixChainMultiplier({20, 30, 50, 70, 40, 30, 100, 30, 55, 20});
    REQUIRE(chain_multiplier.optimal_cost() == 333000);
    REQUIRE(chain_multiplier.optimal_parenthesization() == "(A(B(C(D(E((FG)(HI)))))))");

    chain_multiplier = MatrixChainMultiplier({30, 35, 15, 5, 10, 20, 25});
    REQUIRE(chain_multiplier.optimal_cost() == 15125);
    REQUIRE(chain_multiplier.optimal_parenthesization() == "((A(BC))((DE)F))");
}
