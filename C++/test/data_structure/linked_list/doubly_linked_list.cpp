#include "data_structure/linked_list/doubly_linked_list.hpp"
#include "third_party/catch.hpp"

TEST_CASE("Verify initial state", "[doubly-linked-list]") {
    DoublyLinkedList<int> temp;

    REQUIRE(temp.length() == 0);
}

TEST_CASE("Adding values in front", "[doubly-linked-list]") {
    DoublyLinkedList<int> temp;

    REQUIRE(temp.is_empty());
    REQUIRE(temp.length() == 0);
    temp.insert_front(1);
    REQUIRE(!temp.is_empty());
    REQUIRE(temp.length() == 1);
    temp.insert_front(2);
    REQUIRE(temp.length() == 2);
    temp.insert_front(3);
    REQUIRE(temp.length() == 3);
    temp.insert_front(4);
    REQUIRE(temp.length() == 4);
    temp.insert_front(5);
    REQUIRE(!temp.is_empty());
    REQUIRE(temp.length() == 5);

    for (int i = 0; i < temp.length(); i++) {
        REQUIRE(temp[i] == 5 - i);
    }
}

TEST_CASE("Removing values from front", "[doubly-linked-list]") {
    DoublyLinkedList<int> temp;

    REQUIRE(temp.is_empty());
    REQUIRE(temp.length() == 0);
    temp.insert_front(1);
    REQUIRE(!temp.is_empty());
    REQUIRE(temp.length() == 1);
    temp.insert_front(2);
    REQUIRE(temp.length() == 2);
    temp.insert_front(3);
    REQUIRE(temp.length() == 3);
    temp.insert_front(4);
    REQUIRE(temp.length() == 4);
    temp.insert_front(5);
    REQUIRE(!temp.is_empty());
    REQUIRE(temp.length() == 5);

    temp.delete_front();
    REQUIRE(temp.length() == 4);
    temp.delete_front();
    REQUIRE(temp.length() == 3);
    temp.delete_front();
    REQUIRE(temp.length() == 2);
    temp.delete_front();
    REQUIRE(temp.length() == 1);
    temp.delete_front();
    REQUIRE(temp.length() == 0);
    temp.delete_front();
    REQUIRE(temp.is_empty());
    REQUIRE(temp.length() == 0);
}

TEST_CASE("Adding values in rear", "[doubly-linked-list]") {
    DoublyLinkedList<int> temp;

    REQUIRE(temp.is_empty());
    REQUIRE(temp.length() == 0);
    temp.insert_rear(1);
    REQUIRE(!temp.is_empty());
    REQUIRE(temp.length() == 1);
    temp.insert_rear(2);
    REQUIRE(temp.length() == 2);
    temp.insert_rear(3);
    REQUIRE(temp.length() == 3);
    temp.insert_rear(4);
    REQUIRE(temp.length() == 4);
    temp.insert_rear(5);
    REQUIRE(!temp.is_empty());
    REQUIRE(temp.length() == 5);

    for (int i = 0; i < temp.length(); i++) {
        REQUIRE(temp[i] == i + 1);
    }
}

TEST_CASE("Removing values from rear", "[doubly-linked-list]") {
    DoublyLinkedList<int> temp;

    REQUIRE(temp.is_empty());
    REQUIRE(temp.length() == 0);
    temp.insert_rear(1);
    REQUIRE(temp.length() == 1);
    temp.insert_rear(2);
    REQUIRE(temp.length() == 2);
    temp.insert_rear(3);
    REQUIRE(temp.length() == 3);
    temp.insert_rear(4);
    REQUIRE(temp.length() == 4);
    temp.insert_rear(5);
    REQUIRE(!temp.is_empty());
    REQUIRE(temp.length() == 5);

    temp.delete_rear();
    REQUIRE(temp.length() == 4);
    temp.delete_rear();
    REQUIRE(temp.length() == 3);
    temp.delete_rear();
    REQUIRE(temp.length() == 2);
    temp.delete_rear();
    REQUIRE(temp.length() == 1);
    temp.delete_rear();
    REQUIRE(temp.length() == 0);
    temp.delete_rear();
    REQUIRE(temp.is_empty());
    REQUIRE(temp.length() == 0);
}

TEST_CASE("Inserting arbitrary values", "[doubly-linked-list]") {
    DoublyLinkedList<int> list;

    REQUIRE(list.is_empty());
    list.insert_rear(-13);
    list.insert_rear(157);
    list.insert_front(-166);
    list.insert_front(43);

    REQUIRE(list.length() == 4);
    REQUIRE(list[0] == 43);
    REQUIRE(list[1] == -166);
    REQUIRE(list[2] == -13);
    REQUIRE(list[3] == 157);
}
