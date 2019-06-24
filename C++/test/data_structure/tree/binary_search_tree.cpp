#include "third_party/catch.hpp"
#include "data_structure/tree/binary_search_tree.hpp"

TEST_CASE("Create an empty search tree", "[binary-search-tree]") {
    BinarySearchTree tree;

    // Verify empty vectors
    REQUIRE(tree.traversal_inorder_recursive() == vector<int>({}));
    REQUIRE(tree.traversal_inorder_iterative() == vector<int>({}));
    REQUIRE(tree.traversal_preorder_recursive() == vector<int>({}));
    REQUIRE(tree.traversal_preorder_iterative() == vector<int>({}));
    REQUIRE(tree.traversal_postorder_recursive() == vector<int>({}));
    REQUIRE(tree.traversal_postorder_iterative() == vector<int>({}));
}

TEST_CASE("Add and remove values", "[binary-search-tree]") {
    BinarySearchTree tree;

    tree.insert(1);
    tree.insert(2);
    tree.insert(-22);
    tree.insert(0);
    tree.insert(211);
    tree.insert(28);
    tree.insert(94);
    tree.insert(-55);
    tree.insert(39);
    tree.insert(92);
    tree.insert(-122);
    tree.insert(20);
    tree.insert(298);
    tree.insert(91);
    tree.insert(77);
    tree.insert(-54);
    tree.insert(21);
    tree.insert(42);
    tree.insert(23);
    tree.insert(109);

    // Verify search() and insert()
    REQUIRE(tree.search(1) == true);
    REQUIRE(tree.search(2) == true);
    REQUIRE(tree.search(-22) == true);
    REQUIRE(tree.search(0) == true);
    REQUIRE(tree.search(211) == true);
    REQUIRE(tree.search(28) == true);
    REQUIRE(tree.search(94) == true);
    REQUIRE(tree.search(-55) == true);
    REQUIRE(tree.search(39) == true);
    REQUIRE(tree.search(92) == true);
    REQUIRE(tree.search(-122) == true);
    REQUIRE(tree.search(20) == true);
    REQUIRE(tree.search(298) == true);
    REQUIRE(tree.search(91) == true);
    REQUIRE(tree.search(77) == true);
    REQUIRE(tree.search(-54) == true);
    REQUIRE(tree.search(42) == true);
    REQUIRE(tree.search(23) == true);
    REQUIRE(tree.search(109) == true);

    REQUIRE(tree.search(-285) == false);
    REQUIRE(tree.search(19) == false);
    REQUIRE(tree.search(97) == false);
    REQUIRE(tree.search(93) == false);
    REQUIRE(tree.search(-381) == false);

    tree.remove(39);
    tree.remove(92);
    tree.remove(298);
    tree.remove(1);
    tree.remove(2);

    // Verify search() and remove()
    REQUIRE(tree.search(39) == false);
    REQUIRE(tree.search(92) == false);
    REQUIRE(tree.search(298) == false);
    REQUIRE(tree.search(1) == false);
    REQUIRE(tree.search(2) == false);

    REQUIRE(tree.search(77) == true);
    REQUIRE(tree.search(-54) == true);
    REQUIRE(tree.search(42) == true);
    REQUIRE(tree.search(23) == true);
    REQUIRE(tree.search(109) == true);
}

TEST_CASE("Traversals", "[binary-search-tree]") {
    BinarySearchTree tree;

    tree.insert(1);
    tree.insert(0);
    tree.insert(-1);
    tree.insert(5);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(6);

    // Verify traversals
    REQUIRE(tree.traversal_inorder_recursive() == vector<int>({-1,0,1,2,3,4,5,6}));
    REQUIRE(tree.traversal_inorder_iterative() == vector<int>({-1,0,1,2,3,4,5,6}));
    REQUIRE(tree.traversal_preorder_recursive() == vector<int>({1,0,-1,5,2,3,4,6}));
    REQUIRE(tree.traversal_preorder_iterative() == vector<int>({1,0,-1,5,2,3,4,6}));
    REQUIRE(tree.traversal_postorder_recursive() == vector<int>({-1,0,4,3,2,6,5,1}));
    REQUIRE(tree.traversal_postorder_iterative() == vector<int>({-1,0,4,3,2,6,5,1}));
}
