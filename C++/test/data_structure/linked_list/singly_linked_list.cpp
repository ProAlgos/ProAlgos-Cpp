#include "third_party/catch.hpp"
#include "data_structure/linked_list/singly_linked_list.hpp"

TEST_CASE("Create an empty linked list", "[singly-linked-list]") {
    SinglyLinkedList<int> list;

    // Verify is_empty()
    REQUIRE(list.is_empty() == true);
}

TEST_CASE("Add elements", "[singly-linked-list]") {
    SinglyLinkedList<int> list;

    list.insert_rear(27);
    list.insert_rear(2);
    list.insert_rear(72);
    list.insert_rear(681);
    list.insert_rear(233);
    list.insert_rear(2102);
    list.insert_rear(955);
    list.insert_rear(552);
    list.insert_rear(43);
    list.insert_rear(27);

    list.insert_front(29);
    list.insert_front(511);
    list.insert_front(23);
    list.insert_front(281);
    list.insert_front(-112);
    list.insert_front(251);
    list.insert_front(233);
    list.insert_front(551);
    list.insert_front(6732);
    list.insert_front(-722);

    // Verify length()
    REQUIRE(list.length() == 20);

    // Verify value_at()
    REQUIRE(list.value_at(0) == -722);
    REQUIRE(list.value_at(1) == 6732);
    REQUIRE(list.value_at(2) == 551);
    REQUIRE(list.value_at(3) == 233);
    REQUIRE(list.value_at(4) == 251);
    REQUIRE(list.value_at(5) == -112);
    // ...
    REQUIRE(list.value_at(17) == 552);
    REQUIRE(list.value_at(18) == 43);
    REQUIRE(list.value_at(19) == 27);

    // Verify [] operator
    REQUIRE(list[0] == -722);
    REQUIRE(list[1] == 6732);
    REQUIRE(list[2] == 551);
    // ...
    REQUIRE(list[14] == 233);
    REQUIRE(list[15] == 2102);
    REQUIRE(list[16] == 955);
    REQUIRE(list[17] == 552);
    REQUIRE(list[18] == 43);
    REQUIRE(list[19] == 27);
}

TEST_CASE("Delete elements", "[singly-linked-list]") {
    SinglyLinkedList<int> list;

    list.insert_rear(27);
    list.insert_rear(2);
    list.insert_rear(72);
    list.insert_rear(681);
    list.insert_rear(233);
    list.insert_rear(2102);
    list.insert_rear(955);
    list.insert_rear(552);
    list.insert_rear(43);
    list.insert_rear(27);

    list.insert_front(29);
    list.insert_front(511);
    list.insert_front(23);
    list.insert_front(281);
    list.insert_front(-112);
    list.insert_front(251);
    list.insert_front(233);
    list.insert_front(551);
    list.insert_front(6732);
    list.insert_front(-722);

    // Verify length()
    REQUIRE(list.length() == 20);

    list.delete_front();
    list.delete_front();
    list.delete_front();
    list.delete_front();

    // Verify length()
    REQUIRE(list.length() == 16);

    // Verify element locations
    REQUIRE(list[0] == 251);
    REQUIRE(list[1] == -112);
    REQUIRE(list[2] == 281);
    REQUIRE(list[3] == 23);
    // ...
    REQUIRE(list[14] == 43);
    REQUIRE(list[15] == 27);

    list.delete_rear();
    list.delete_rear();
    list.delete_rear();
    list.delete_rear();

    // Verify length()
    REQUIRE(list.length() == 12);

    // Verify element locations
    REQUIRE(list[0] == 251);
    REQUIRE(list[1] == -112);
    // ...
    REQUIRE(list[8] == 72);
    REQUIRE(list[9] == 681);
    REQUIRE(list[10] == 233);
    REQUIRE(list[11] == 2102);
}

TEST_CASE("Clear list", "[singly-linked-list]") {
    SinglyLinkedList<int> list;

    list.insert_rear(27);
    list.insert_rear(2);
    list.insert_rear(72);
    list.insert_rear(681);
    list.insert_rear(233);
    list.insert_rear(2102);
    list.insert_rear(955);
    list.insert_rear(552);
    list.insert_rear(43);
    list.insert_rear(27);

    list.insert_front(29);
    list.insert_front(511);
    list.insert_front(23);
    list.insert_front(281);
    list.insert_front(-112);
    list.insert_front(251);
    list.insert_front(233);
    list.insert_front(551);
    list.insert_front(6732);
    list.insert_front(-722);

    // Verify length()
    REQUIRE(list.length() == 20);

    list.clear();

    // Verify length()
    REQUIRE(list.length() == 0);

    // Verify is_empty()
    REQUIRE(list.is_empty() == true);
}
