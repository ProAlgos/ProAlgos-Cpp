#include "third_party/catch.hpp"
#include "data_structure/tree/binary_search_tree.hpp"

TEST_CASE("Create an empty search tree", "[binary-search-tree]") {
	BinarySearchTree tree;
	REQUIRE(tree.traversal_inorder_recursive() == vector<int>({})); 	// empty vector
	REQUIRE(tree.traversal_inorder_iterative() == vector<int>({})); 	// empty vector
	REQUIRE(tree.traversal_preorder_recursive() == vector<int>({})); 	// empty vector
	REQUIRE(tree.traversal_preorder_iterative() == vector<int>({})); 	// empty vector
	REQUIRE(tree.traversal_postorder_recursive() == vector<int>({})); 	// empty vector
	REQUIRE(tree.traversal_postorder_iterative() == vector<int>({})); 	// empty vector
}

TEST_CASE("Add and remove values", "[binary-search-tree]") {
	BinarySearchTree tree;
	tree.insert(1);
	tree.insert(2);
	REQUIRE(tree.search(1) == true);
	tree.remove(1);
	REQUIRE(tree.search(1) == false);
	REQUIRE(tree.search(2) == true);
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
	REQUIRE(tree.traversal_inorder_recursive() == vector<int>({-1,0,1,2,3,4,5,6}));
	REQUIRE(tree.traversal_inorder_iterative() == vector<int>({-1,0,1,2,3,4,5,6}));
	REQUIRE(tree.traversal_preorder_recursive() == vector<int>({1,0,-1,5,2,3,4,6}));
	REQUIRE(tree.traversal_preorder_iterative() == vector<int>({1,0,-1,5,2,3,4,6}));
	REQUIRE(tree.traversal_postorder_recursive() == vector<int>({-1,0,4,3,2,6,5,1}));
	REQUIRE(tree.traversal_postorder_iterative() == vector<int>({-1,0,4,3,2,6,5,1}));
}
