#include "data_structure/heap/min_heap.hpp"
#include "third_party/catch.hpp"

TEST_CASE("Verify initial state", "[min-heap]") {
  MinHeap<int> temp;

  REQUIRE(temp.size() == 0);
}

TEST_CASE("Building a heap from inserts", "[min-heap]") {
  MinHeap<int> heap;
  heap.insert_value(1);
  heap.insert_value(8);
  heap.insert_value(6);
  heap.insert_value(5);
  heap.insert_value(13);
  heap.insert_value(9);
  heap.insert_value(4);
  heap.insert_value(517);
  heap.insert_value(-23);
  heap.insert_value(0);
  vector<int> expected = {-23, 0, 4, 5, 1, 9, 6, 517, 8, 13};

  REQUIRE(heap.return_elements() == expected);
}

TEST_CASE("Building a heap from vector", "[min-heap]") {
  MinHeap<int> heap({1, 8, 6, 5, 13, 9, 4, 517, -23, 0});

  vector<int> expected = {-23, 0, 4, 5, 1, 9, 6, 517, 8, 13};
  REQUIRE(heap.return_elements() == expected);
}

TEST_CASE("Removing from a heap", "[min-heap]") {
  MinHeap<int> heap({1, 8, 6, 5, 13, 9, 4, 517, -23, 0});
  heap.remove_value(8);

  vector<int> expected = {-23, 0, 4, 5, 1, 9, 6, 517, 13};
  REQUIRE(heap.return_elements() == expected);

  heap.remove_value(-23);

  vector<int> expected2 = {0, 1, 4, 5, 13, 9, 6, 517};
  REQUIRE(heap.return_elements() == expected2);

  heap.remove_value(8);

  vector<int> expected3 = {0, 1, 4, 5, 13, 9, 6, 517};
  REQUIRE(heap.return_elements() == expected3);
}

TEST_CASE("Complex removals and insertions", "[min-heap]") {
  MinHeap<int> heap({5, 2, 89, 901, 563, 120, 12, 13, -46, 53, -89});
  
  vector<int> expected = {-89, -46, 12, 5, 2, 120, 89, 13, 901, 53, 563};
  REQUIRE(heap.return_elements() == expected);

  heap.insert_value(10);

  vector<int> expected2 = {-89, -46, 10, 5, 2, 12, 89, 13, 901, 53, 563, 120};
  REQUIRE(heap.return_elements() == expected2);

  heap.insert_value(-100);

  vector<int> expected3 = {-100, -46, -89, 5, 2, 10, 89, 13, 901, 53, 563, 120, 12};
  REQUIRE(heap.return_elements() == expected3);

  heap.remove_value(-46);

  vector<int> expected4 = {-100, 2, -89, 5, 12, 10, 89, 13, 901, 53, 563, 120};
  REQUIRE(heap.return_elements() == expected4);

  heap.insert_value(11);

  vector<int> expected5 = {-100, 2, -89, 5, 12, 10, 89, 13, 901, 53, 563, 120, 11};
  REQUIRE(heap.return_elements() == expected5);

  heap.remove_value(563);

  vector<int> expected6 = {-100, 2, -89, 5, 11, 10, 89, 13, 901, 53, 12, 120};
  REQUIRE(heap.return_elements() == expected6);

  heap.remove_value(-100);

  vector<int> expected7 = {-89, 2, 10, 5, 11, 120, 89, 13, 901, 53, 12};
  REQUIRE(heap.return_elements() == expected7);

  REQUIRE(heap.return_min() == -89);
}
