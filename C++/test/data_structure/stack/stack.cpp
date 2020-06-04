#include "data_structure/stack/stack.hpp"
#include "third_party/catch.hpp"

TEST_CASE("Verify initial state", "[stack]") {
    Stack<int> temp;
    REQUIRE(temp.length() == 0);
}

TEST_CASE("Adding values in front", "[stack]") {
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
