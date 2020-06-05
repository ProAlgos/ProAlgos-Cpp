#include "third_party/catch.hpp"
#include "data_structure/stack/stack.hpp"

TEST_CASE("Verify initial state", "[stack]") {
    Stack<int> temp;
    REQUIRE(temp.length() == 0);
    REQUIRE(temp.isEmpty() == true);
}

TEST_CASE("Add elements", "[stack]") {
    Stack<int> temp;
    
    temp.push(27);
    temp.push(2);
    temp.push(72);
    temp.push(681);
    temp.push(233);
    temp.push(2102);
    temp.push(955);
    temp.push(552);
    temp.push(43);
    temp.push(722);
    
    //Verify state
    REQUIRE(temp.length() == 10);
    REQUIRE(temp.isEmpty() == false);
    REQUIRE(temp.top() == 722);
}

TEST_CASE("Delete elements", "[stack]") {
    Stack<int> temp;
    
    temp.push(27);
    temp.push(2);
    temp.push(72);
    temp.push(681);
    temp.push(233);
    temp.push(2102);
    temp.push(955);
    temp.push(552);
    temp.push(43);
    temp.push(722);
    
    //Verify state
    REQUIRE(temp.length() == 10);
    REQUIRE(temp.isEmpty() == false);
    REQUIRE(temp.top() == 722);
    
    temp.pop();
    temp.pop();
    temp.pop();
    temp.pop();
    
    REQUIRE(temp.length() == 6);
    REQUIRE(temp.top() == 2102);
}

TEST_CASE("Clear list", "[stack]") {
    Stack<int> temp;
    
    temp.push(27);
    temp.push(2);
    temp.push(72);
    temp.push(681);
    temp.push(233);
    temp.push(2102);
    temp.push(955);
    temp.push(552);
    temp.push(43);
    temp.push(722);
    
    //Verify state
    REQUIRE(temp.length() == 10);
    REQUIRE(temp.isEmpty() == false);
    REQUIRE(temp.top() == 722);
    
    temp.pop();
    temp.pop();
    temp.pop();
    temp.pop();
    temp.pop();
    temp.pop();
    temp.pop();
    temp.pop();
    temp.pop();
    temp.pop();
    
    REQUIRE(temp.length() == 0);
    REQUIRE(temp.isEmpty() == true);
}

TEST_CASE("Adding and removing values", "[stack]") {
    Stack<int> temp;
    
    temp.push(2);
    REQUIRE(temp.length() == 1);
    REQUIRE(temp.top() == 2);
    temp.push(5);
    temp.push(7);
    REQUIRE(temp.length() == 3);
    temp.pop();
    REQUIRE(temp.length() == 2);
    REQUIRE(temp.top() == 5);
    temp.pop();
    REQUIRE(temp.length() == 1);
    REQUIRE(temp.top() == 2);
    temp.pop();
    REQUIRE(temp.length() == 0);
}
