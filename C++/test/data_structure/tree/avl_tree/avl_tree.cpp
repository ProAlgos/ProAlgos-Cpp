#include "third_party/catch.hpp"
#include "data_structure/tree/avl_tree/avl_tree.hpp"
#include <cmath>
#include <numeric>
#include <iterator>
#include <iostream>

// helper struct to parse all nodes into a vector
struct AVLNodeAccumulator {
    std::vector<AVLNode*> nodes;

    void operator()(AVLNode* node) {
        this->nodes.push_back(node);
    }

    std::vector<int> getValues() {
        std::vector<int> ret;
        std::transform(
            nodes.begin(),
            nodes.end(),
            std::back_inserter(ret),
            [] (const AVLNode* n) { return n->value; }
        );
        return ret; 
    }
};

TEST_CASE("Constructing trees", "[avl-tree]") {
    AVLTree tree;
    AVLNodeAccumulator accumulator;
    
    SECTION("Constructors") {
        REQUIRE(tree.get_root() == nullptr);
        AVLTree tree2({1, 2, 3});
        tree2.traverse(std::ref(accumulator), AVLTree::TraverseOrder::IN);
        REQUIRE(accumulator.nodes.size() == 3);
        REQUIRE(accumulator.getValues() == std::vector<int>{1, 2, 3});
    }
}

TEST_CASE("Add and remove random values", "[avl-tree]") {
    AVLTree tree;

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
    REQUIRE(tree.exists(1) == true);
    REQUIRE(tree.exists(2) == true);
    REQUIRE(tree.exists(-22) == true);
    REQUIRE(tree.exists(0) == true);
    REQUIRE(tree.exists(211) == true);
    REQUIRE(tree.exists(28) == true);
    REQUIRE(tree.exists(94) == true);
    REQUIRE(tree.exists(-55) == true);
    REQUIRE(tree.exists(39) == true);
    REQUIRE(tree.exists(92) == true);
    REQUIRE(tree.exists(-122) == true);
    REQUIRE(tree.exists(20) == true);
    REQUIRE(tree.exists(298) == true);
    REQUIRE(tree.exists(91) == true);
    REQUIRE(tree.exists(77) == true);
    REQUIRE(tree.exists(-54) == true);
    REQUIRE(tree.exists(42) == true);
    REQUIRE(tree.exists(23) == true);
    REQUIRE(tree.exists(109) == true);

    REQUIRE(tree.exists(-285) == false);
    REQUIRE(tree.exists(19) == false);
    REQUIRE(tree.exists(97) == false);
    REQUIRE(tree.exists(93) == false);
    REQUIRE(tree.exists(-381) == false);

    tree.remove(39);
    tree.remove(92);
    tree.remove(298);
    tree.remove(1);
    tree.remove(2);

    // Verify exists() and remove()
    REQUIRE(tree.exists(39) == false);
    REQUIRE(tree.exists(92) == false);
    REQUIRE(tree.exists(298) == false);
    REQUIRE(tree.exists(1) == false);
    REQUIRE(tree.exists(2) == false);

    REQUIRE(tree.exists(77) == true);
    REQUIRE(tree.exists(-54) == true);
    REQUIRE(tree.exists(42) == true);
    REQUIRE(tree.exists(23) == true);
    REQUIRE(tree.exists(109) == true);
}

TEST_CASE("Add and remove sequential values", "[avl-tree]") {
    using std::ceil;
    using std::log2;

    AVLTree tree;

    std::vector<int> testNumbers(100, 0);
    std::iota(testNumbers.begin(), testNumbers.end(), 0);
    auto shuffledTestNumbers = testNumbers;
    std::random_shuffle(shuffledTestNumbers.begin(), shuffledTestNumbers.end());

    int previousTreeSize = tree.get_size();
    // randomly add the numbers into tree
    for (int i : shuffledTestNumbers) {
        tree.insert(i);
        REQUIRE(tree.get_size() == previousTreeSize + 1);
        previousTreeSize = tree.get_size();
        AVLNodeAccumulator accumulator;
        tree.traverse(std::ref(accumulator), AVLTree::TraverseOrder::IN);
        REQUIRE(tree.get_size() == accumulator.nodes.size());
        // test that tree remains balanced after every insertion 
        for (AVLNode* node : accumulator.nodes) {
            REQUIRE(node->isBalanced() == true);
        }
         // test that height of tree stays ~log(n)
        if (tree.get_size() >= 2) {
            const int allowableAvlTreeHeight = ceil(log2(testNumbers.size()));
            REQUIRE(tree.get_root()->height <= allowableAvlTreeHeight);
        }
    }


    std::random_shuffle(shuffledTestNumbers.begin(), shuffledTestNumbers.end());
    for (int i : shuffledTestNumbers) {
        previousTreeSize = tree.get_size();
        tree.remove(i);
        REQUIRE(tree.get_size() == previousTreeSize - 1);

        AVLNodeAccumulator accumulator;
        tree.traverse(std::ref(accumulator), AVLTree::TraverseOrder::IN);
        REQUIRE(tree.get_size() == accumulator.nodes.size());
        // test that tree remains balanced after every removal
        for (AVLNode* node : accumulator.nodes) {
            REQUIRE(node->isBalanced() == true);
        }
         // test that height of tree stays ~log(n)
        if (tree.get_size() >= 2) {
            const int allowableAvlTreeHeight = ceil(log2(testNumbers.size()));
            REQUIRE(tree.get_root()->height <= allowableAvlTreeHeight);
        }
    }
}
