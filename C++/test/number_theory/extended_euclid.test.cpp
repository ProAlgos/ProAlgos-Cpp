#define EXTENDED_EUCLID_TEST

#include "third_party/catch.hpp"
#include "source/number_theory/extended_euclid.cpp"

TEST_CASE("Base Cases","[extended_euclidean]") {
	REQUIRE(extended_euclidean(0,1) == (array<int,2>{0,1}));
	REQUIRE(extended_euclidean(1,2) == (array<int,2>{1,0}));
	REQUIRE(extended_euclidean(1,99999) == (array<int,2>{1,0}));
}

TEST_CASE("Normal Cases","[extended_euclidean]") {
	REQUIRE(extended_euclidean(10,30) == (array<int,2>{1,0}));
	REQUIRE(extended_euclidean(105,15) == (array<int,2>{0,1}));
	REQUIRE(extended_euclidean(9243,45) == (array<int,2>{-2,411}));
	REQUIRE(extended_euclidean(1024,64) == (array<int,2>{0,1}));
	REQUIRE(extended_euclidean(350,64) == (array<int,2>{15,-82}));
	REQUIRE(extended_euclidean(8056,256) == (array<int,2>{15,-472}));
	REQUIRE(extended_euclidean(2468024,864226) == (array<int,2>{-161525,461277}));
}

#undef EXTENDED_EUCLID_TEST