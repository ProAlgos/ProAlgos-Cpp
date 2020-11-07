#include "third_party/catch.hpp"
#include "data_structure/tree/fenwick_tree.hpp"

TEST_CASE("Create an empty tree", "[fenwick-tree]") {
    vector<int> original_array;
    FenwickTree tree(original_array);

    REQUIRE(tree.calculate_prefix_sum(0) == 0);
}

TEST_CASE("Check tree with 5 items", "[fenwick-tree]") {
    vector<int> original_array{10, 3, 15, 12, 5};
    
    FenwickTree tree(original_array);
    
    REQUIRE(tree.calculate_prefix_sum(0) == 10);
    REQUIRE(tree.calculate_prefix_sum(1) == 13);
    REQUIRE(tree.calculate_prefix_sum(2) == 28);
    REQUIRE(tree.calculate_prefix_sum(3) == 40);
    REQUIRE(tree.calculate_prefix_sum(4) == 45);
}

TEST_CASE("Check tree that has been updated", "[fenwick-tree]") {
    vector<int> original_array{10, 3, 15, 12, 5};
    
    FenwickTree tree(original_array);
    
    // Update in the middle of the array and then check
    tree.update_tree(2, 4);
    
    REQUIRE(tree.calculate_prefix_sum(0) == 10);
    REQUIRE(tree.calculate_prefix_sum(1) == 13);
    REQUIRE(tree.calculate_prefix_sum(2) == 32);
    REQUIRE(tree.calculate_prefix_sum(3) == 44);
    REQUIRE(tree.calculate_prefix_sum(4) == 49);
    
    // Update at the end of the array and then check
    tree.update_tree(4, 4);
    
    REQUIRE(tree.calculate_prefix_sum(0) == 10);
    REQUIRE(tree.calculate_prefix_sum(1) == 13);
    REQUIRE(tree.calculate_prefix_sum(2) == 32);
    REQUIRE(tree.calculate_prefix_sum(3) == 44);
    REQUIRE(tree.calculate_prefix_sum(4) == 53);
    
    // Update at the start of the array and then check
    tree.update_tree(0, 4);
    
    REQUIRE(tree.calculate_prefix_sum(0) == 14);
    REQUIRE(tree.calculate_prefix_sum(1) == 17);
    REQUIRE(tree.calculate_prefix_sum(2) == 36);
    REQUIRE(tree.calculate_prefix_sum(3) == 48);
    REQUIRE(tree.calculate_prefix_sum(4) == 57);
}

TEST_CASE("Check tree that has been updated with a negative number", "[fenwick-tree]") {
    vector<int> original_array{10, 3, 15, 12, 5};
    
    FenwickTree tree(original_array);
    
    // original_array will now be [10, 3, 19, 12, 5]
    tree.update_tree(1, -3);
    
    REQUIRE(tree.calculate_prefix_sum(0) == 10);
    REQUIRE(tree.calculate_prefix_sum(1) == 10);
    REQUIRE(tree.calculate_prefix_sum(2) == 25);
    REQUIRE(tree.calculate_prefix_sum(3) == 37);
    REQUIRE(tree.calculate_prefix_sum(4) == 42);
    
    tree.update_tree(4, -3);
    REQUIRE(tree.calculate_prefix_sum(0) == 10);
    REQUIRE(tree.calculate_prefix_sum(1) == 10);
    REQUIRE(tree.calculate_prefix_sum(2) == 25);
    REQUIRE(tree.calculate_prefix_sum(3) == 37);
    REQUIRE(tree.calculate_prefix_sum(4) == 39);
    
    tree.update_tree(0, -3);
    REQUIRE(tree.calculate_prefix_sum(0) == 7);
    REQUIRE(tree.calculate_prefix_sum(1) == 7);
    REQUIRE(tree.calculate_prefix_sum(2) == 22);
    REQUIRE(tree.calculate_prefix_sum(3) == 34);
    REQUIRE(tree.calculate_prefix_sum(4) == 36);
}
