#include "third_party/catch.hpp"
#include "data_structure/threaded_binary_tree/threaded_binary_tree.hpp"

TEST_CASE("Create an empty threaded binary tree", "[threaded-binary-tree]") {
    Threaded_Binary_Tree tree;

    // Verify empty vectors
    REQUIRE(tree.preorder_traversal() == vector<int>({}));
    REQUIRE(tree.inorder_traversal() == vector<int>({}));
   
}

TEST_CASE("Creation of the threaded_binary_tree", "[threaded-binary-tree]") {
    Threaded_Binary_Tree tree;

   	vector<int> values{ 15 , 10, 20 , 8, 12, 25, 22, 30 }; 

   	tree.create(values);


    // The  tree creation can be verified by checking the output of their traversals
   
    REQUIRE(tree.preorder_traversal() == vector<int>({15,10,8,12,20,25,22,30}));
   
    REQUIRE(tree.inorder_traversal() == vector<int>({8,10,12,15,20,22,25,30}));
   

}

TEST_CASE("Inserting values one by one in already created threaded_binary_tree", "[threaded-binary-tree]") {
    Threaded_Binary_Tree tree;

    tree.insert(2);
    tree.insert(1);
    tree.insert(17);
    tree.insert(10);
    tree.insert(28);
    tree.insert(-1);
   

   // The  tree creation can be verified by checking the output of their traversals

    REQUIRE(tree.preorder_traversal() == vector<int>({2,1,-1,17,10,28}));

    REQUIRE(tree.inorder_traversal() == vector<int>({-1,1,2,10,17,28}));
    
}