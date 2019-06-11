#include "third_party/catch.hpp"
#include "data_structure/linked_list/singly_linked_list.hpp"

TEST_CASE("Create an empty linked list", "[singly-linked-list]") {
	SinglyLinkedList<int> list;
	REQUIRE(list.is_empty() == true);
}

TEST_CASE("Add elements", "[singly-linked-list]") {
	SinglyLinkedList<int> list;
	list.insert_rear(2);
	list.insert_rear(3);
	list.insert_rear(5);
	list.insert_rear(7);
	REQUIRE(list.length() == 4);
	REQUIRE(list.value_at(0) == 2);
	REQUIRE(list.value_at(1) == 3);
	REQUIRE(list.value_at(2) == 5);
	REQUIRE(list.value_at(3) == 7);
}

TEST_CASE("Delete elements", "[singly-linked-list]") {
	SinglyLinkedList<int> list;
	list.insert_rear(2);
	list.insert_rear(3);
	list.insert_rear(5);
	list.insert_rear(7);
	REQUIRE(list.length() == 4);
	list.delete_front();
	REQUIRE(list.length() == 3);
	REQUIRE(list.value_at(0) == 3);
	list.delete_rear();
	REQUIRE(list.length() == 2);
	REQUIRE(list.value_at(1) == 5);
}

TEST_CASE("Clear list", "[singly-linked-list]") {
	SinglyLinkedList<int> list;
	list.insert_rear(2);
	list.insert_rear(3);
	list.insert_rear(5);
	list.insert_rear(7);
	REQUIRE(list.length() == 4);
	list.clear();
	REQUIRE(list.length() == 0);
}
