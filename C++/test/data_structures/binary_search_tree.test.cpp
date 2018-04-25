#define BINARY_SEARCH_TREE_TEST

#include "third_party/catch.hpp"
#include "data_structures/binary_search_tree.cpp"

TEST_CASE("Lowest common ancestor", "[binary-search-tree]") {
    BinarySearchTree tree;

    SECTION("empty tree") {
        REQUIRE(tree.lowest_common_ancestor(0, 0) == nullptr);
    }

    SECTION("value not in tree") {
        tree.insert(10);
        tree.insert(14);
        tree.insert(12);

        REQUIRE(tree.lowest_common_ancestor(2, 10) == nullptr);
        REQUIRE(tree.lowest_common_ancestor(14, 5) == nullptr);
    }

    SECTION("self ancestry") {
        tree.insert(10);
        auto ancestor = tree.lowest_common_ancestor(10, 10);
        REQUIRE(ancestor != nullptr);
        REQUIRE(ancestor->value == 10);
    }

    SECTION("general") {
        tree.insert(10);
        tree.insert(14);
        tree.insert(12);
        tree.insert(5);
        tree.insert(7);
        tree.insert(4);

        auto ancestor = tree.lowest_common_ancestor(5, 12);
        REQUIRE(ancestor != nullptr);
        REQUIRE(ancestor->value == 10);

        ancestor = tree.lowest_common_ancestor(7, 4);
        REQUIRE(ancestor != nullptr);
        REQUIRE(ancestor->value == 5);
    }
}

#undef BINARY_SEARCH_TREE_TEST
