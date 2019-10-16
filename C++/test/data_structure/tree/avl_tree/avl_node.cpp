#include "third_party/catch.hpp"
#include "data_structure/tree/avl_tree/avl_node.hpp"

TEST_CASE("Linking nodes together", "[avl-node]") {
    AVLNode a(1), b(2), c(3);
    a.attach_left_child(&b);
    b.attach_left_child(&c);

    SECTION("Nodes are correctly attached") {
        REQUIRE(a.left_child == &b);
        REQUIRE(b.left_child == &c);

        REQUIRE(c.parent == &b);
        REQUIRE(b.parent == &a);
    }
    SECTION("Heights are correctly calculated after attach") {
        REQUIRE(a.height == 2);
        REQUIRE(b.height == 1);
        REQUIRE(c.height == 0);
    }

    SECTION("Balances are correctly calculated") {
        REQUIRE(a.is_balanced() == false);
        REQUIRE(b.is_balanced() == true);
        REQUIRE(c.is_balanced() == true);
    }

    b.detach_parent();
    b.detach_left_child();

    SECTION("Nodes are correctly detached") {
        REQUIRE(a.left_child == nullptr);
        REQUIRE(b.left_child == nullptr);

        REQUIRE(c.parent == nullptr);
        REQUIRE(b.parent == nullptr);
    }
    SECTION("Heights are correctly calculated after detach") {
        REQUIRE(a.height == 0);
        REQUIRE(b.height == 0);
        REQUIRE(c.height == 0);
    }

    SECTION("Child nodes are correctly replaced") {
        a.attach_right_child(&b);
        AVLNode* oldChild = a.replace_child(&b, &c);
        
        REQUIRE(a.right_child == &c);
        REQUIRE(c.parent == &a);

        REQUIRE(oldChild == &b);
        REQUIRE(oldChild->parent == nullptr);

        a.attach_left_child(&b);
        oldChild = a.replace_child(&b, &c);
        
        REQUIRE(a.left_child == &c);
        REQUIRE(c.parent == &a);

        REQUIRE(oldChild == &b);
        REQUIRE(oldChild->parent == nullptr);
    }
}