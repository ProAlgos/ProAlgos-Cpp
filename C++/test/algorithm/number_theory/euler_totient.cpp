#include "third_party/catch.hpp"
#include "algorithm/number_theory/EulerTotient.hpp"

TEST_CASE( "Easy Test Cases", "[eulertot]" ) {
    REQUIRE( eulertot(1) == 1 );
    REQUIRE( eulertot(9) == 6 );
    REQUIRE( eulertot(100) == 40 );
    REQUIRE( eulertot(500) == 200 );
    REQUIRE( eulertot(6561) == 4374 );
}
TEST_CASE("Hard Test Cases","[eulertot]")
{
	REQUIRE( eulertot(15345) == 7200 );
	REQUIRE( eulertot(45699) == 30464 );
	REQUIRE( eulertot(815623) == 815622);
	REQUIRE( eulertot(1099123) == 1073520 );
	REQUIRE( eulertot(9999999) == 6637344 );
	REQUIRE( eulertot(23918763) == 13831200 );	
	REQUIRE( eulertot(31543908) == 8995840);
	REQUIRE( eulertot(40961024) == 17694720);
}
