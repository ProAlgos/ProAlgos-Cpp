#include "third_party/catch.hpp"
#include "data_structure/stack/stack.hpp"

TEST_CASE("Verify initial state", "[stack]") {
    // Initialize stack
	Stack<int> stack;

	// Verify state
    REQUIRE(stack.length() == 0);
    REQUIRE(stack.isEmpty() == true);
}

TEST_CASE("Add elements", "[stack]") {
    // Initialize stack
	Stack<int> stack;

	// Add items
    stack.push(27);
    stack.push(2);
    stack.push(72);
    stack.push(681);
    stack.push(233);
    stack.push(2102);
    stack.push(955);
    stack.push(552);
    stack.push(43);
    stack.push(722);
    
    // Verify state
    REQUIRE(stack.length() == 10);
    REQUIRE(stack.isEmpty() == false);
    REQUIRE(stack.top() == 722);
}

TEST_CASE("Delete elements", "[stack]") {
    // Initialize stack
	Stack<int> stack;

	// Add items
    stack.push(27);
    stack.push(2);
    stack.push(72);
    stack.push(681);
    stack.push(233);
    stack.push(2102);
    stack.push(955);
    stack.push(552);
    stack.push(43);
    stack.push(722);
    
    // Verify state
    REQUIRE(stack.length() == 10);
    REQUIRE(stack.isEmpty() == false);
    REQUIRE(stack.top() == 722);

    // Remove items
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();

    // Verify state
    REQUIRE(stack.length() == 6);
    REQUIRE(stack.top() == 2102);
}

TEST_CASE("Clear list", "[stack]") {
    // Initialize stack
	Stack<int> stack;

	// Add items
    stack.push(27);
    stack.push(2);
    stack.push(72);
    stack.push(681);
    stack.push(233);
    stack.push(2102);
    stack.push(955);
    stack.push(552);
    stack.push(43);
    stack.push(722);
    
    // Verify state
    REQUIRE(stack.length() == 10);
    REQUIRE(stack.isEmpty() == false);
    REQUIRE(stack.top() == 722);

    // Remove items
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();

    // Verify state
    REQUIRE(stack.length() == 0);
    REQUIRE(stack.isEmpty() == true);
}

TEST_CASE("Adding and removing values", "[stack]") {
	// Initialize state
	Stack<int> stack;

	// Verify state after adding items
    stack.push(2);
    REQUIRE(stack.length() == 1);
    REQUIRE(stack.top() == 2);

	// Verify state after adding more items
    stack.push(5);
    stack.push(7);
    REQUIRE(stack.length() == 3);

	// Verify state after removing items
    stack.pop();
    REQUIRE(stack.length() == 2);
    REQUIRE(stack.top() == 5);

	// Verify state after removing more items
    stack.pop();
    REQUIRE(stack.length() == 1);
    REQUIRE(stack.top() == 2);

    // Verify state after removing remaining item
    stack.pop();
    REQUIRE(stack.length() == 0);
    REQUIRE(stack.isEmpty() == true);
}
