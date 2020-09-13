#include "third_party/catch.hpp"
#include "data_structure/queue/queue.hpp"

TEST_CASE("Verify initial state", "[queue]") {
    // Initialize queue
    Queue<int> queue;

    // Verify state
    REQUIRE(queue.length() == 0);
    REQUIRE(queue.isEmpty() == true);
}

TEST_CASE("Add elements", "[queue]") {
    // Initialize queue
    Queue<int> queue;

    // Add items
    queue.push(27);
    queue.push(2);
    queue.push(72);
    queue.push(681);
    queue.push(233);
    queue.push(2102);
    queue.push(955);
    queue.push(552);
    queue.push(43);
    queue.push(722);

    // Verify state
    REQUIRE(queue.length() == 10);
    REQUIRE(queue.isEmpty() == false);
    REQUIRE(queue.top() == 27);
}

TEST_CASE("Delete elements", "[queue]") {
    // Initialize queue
    Queue<int> queue;

    // Add items
    queue.push(27);
    queue.push(2);
    queue.push(72);
    queue.push(681);
    queue.push(233);
    queue.push(2102);
    queue.push(955);
    queue.push(552);
    queue.push(43);
    queue.push(722);

    // Verify state
    REQUIRE(queue.length() == 10);
    REQUIRE(queue.isEmpty() == false);
    REQUIRE(queue.top() == 27);

    // Remove items
    queue.pop();
    queue.pop();
    queue.pop();
    queue.pop();

    // Verify state
    REQUIRE(queue.length() == 6);
    REQUIRE(queue.top() == 233);
}

TEST_CASE("Clear list", "[queue]") {
    // Initialize queue
    Queue<int> queue;

    // Add items
    queue.push(27);
    queue.push(2);
    queue.push(72);
    queue.push(681);
    queue.push(233);
    queue.push(2102);
    queue.push(955);
    queue.push(552);
    queue.push(43);
    queue.push(722);

    // Verify state
    REQUIRE(queue.length() == 10);
    REQUIRE(queue.isEmpty() == false);
    REQUIRE(queue.top() == 27);

    // Remove items
    queue.pop();
    queue.pop();
    queue.pop();
    queue.pop();
    queue.pop();
    queue.pop();
    queue.pop();
    queue.pop();
    queue.pop();
    queue.pop();

    // Verify state
    REQUIRE(queue.length() == 0);
    REQUIRE(queue.isEmpty() == true);
}

TEST_CASE("Adding and removing values", "[queue]") {
    // Initialize state
    Queue<int> queue;

    // Verify state after adding items
    queue.push(2);
    REQUIRE(queue.length() == 1);
    REQUIRE(queue.top() == 2);

    // Verify state after adding more items
    queue.push(5);
    queue.push(7);
    REQUIRE(queue.length() == 3);
    REQUIRE(queue.top() == 2);

    // Verify state after removing items
    queue.pop();
    REQUIRE(queue.length() == 2);
    REQUIRE(queue.top() == 5);

    // Verify state after removing more items
    queue.pop();
    REQUIRE(queue.length() == 1);
    REQUIRE(queue.top() == 7);

    // Verify state after removing remaining item
    queue.pop();
    REQUIRE(queue.length() == 0);
    REQUIRE(queue.isEmpty() == true);
}
