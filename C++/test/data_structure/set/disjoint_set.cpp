#include "third_party/catch.hpp"
#include "data_structure/set/disjoint_set.hpp"

TEST_CASE("Create a large set containing 10^8 elements", "[disjoint-set]") {
    /*
        Note: This test requires around 800MB of memory.
    */
    DisjointSet ds(1e8);
    REQUIRE(ds.size() == 1e8);
}

TEST_CASE("Check initial state", "[disjoint-set]") {
    DisjointSet ds(20);

    for (size_t element = 0; element < ds.size(); element++) {
        REQUIRE(ds.find(element) == element);
    }
}

TEST_CASE("Connect elements and verify their representatives", "[disjoint-set]") {
    DisjointSet ds(16);     // create a disjoint-set with elements from 0 to 15

    ds.join(0, 8);
    REQUIRE(ds.find(0) == 0);
    REQUIRE(ds.find(8) == 0);

    ds.join(3, 15);
    REQUIRE(ds.find(3) == 3);
    REQUIRE(ds.find(15) == 3);

    ds.join(10, 5);
    REQUIRE(ds.find(10) == 10);
    REQUIRE(ds.find(5) == 10);

    SECTION("Connecting the elements the other way shouldn't change things") {
        ds.join(8, 0);
        REQUIRE(ds.find(0) == 0);
        REQUIRE(ds.find(8) == 0);

        ds.join(15, 3);
        REQUIRE(ds.find(3) == 3);
        REQUIRE(ds.find(15) == 3);

        ds.join(5, 10);
        REQUIRE(ds.find(10) == 10);
        REQUIRE(ds.find(5) == 10);
    }

    // Connect elements directly to representatives
    ds.join(0, 9);
    REQUIRE(ds.find(9) == 0);

    ds.join(3, 4);
    REQUIRE(ds.find(4) == 3);

    ds.join(10, 2);
    REQUIRE(ds.find(2) == 10);

    // Connect elements to the ones already connected to some other element
    ds.join(1, 9);
    REQUIRE(ds.find(1) == 0);

    ds.join(6, 4);
    REQUIRE(ds.find(6) == 3);

    ds.join(7, 2);
    REQUIRE(ds.find(7) == 10);

    // Connect some more elements
    ds.join(11, 12);
    ds.join(12, 13);
    ds.join(13, 14);
    REQUIRE(ds.find(11) == 11);
    REQUIRE(ds.find(12) == 11);
    REQUIRE(ds.find(13) == 11);
    REQUIRE(ds.find(14) == 11);

    // Connect elements belonging to different subsets
    ds.join(9, 4);
    REQUIRE(ds.find(9) == 0);
    REQUIRE(ds.find(4) == 0);
    REQUIRE(ds.find(3) == 0);

    ds.join(12, 7);
    REQUIRE(ds.find(12) == 11);
    REQUIRE(ds.find(7) == 11);
    REQUIRE(ds.find(10) == 11);

    ds.join(13, 6);
    for (size_t element = 0; element < ds.size(); element++) {
        REQUIRE(ds.find(element) == 11);
    }
}
