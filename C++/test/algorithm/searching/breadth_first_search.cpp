#include "third_party/catch.hpp"
#include "algorithm/searching/breadth_first_search.hpp"


TEST_CASE("Base cases", "[searching][breadth_first_search]") {
    Graph testGraph = Graph(5);
    testGraph.addEdge(0,1);
    testGraph.addEdge(1,2);
    testGraph.addEdge(2,4);
    testGraph.addEdge(0,3);
    std::vector<int> expectedResult{0,1,3,2,4};
    std::vector<int> resultingQueue;
    resultingQueue = testGraph.breadth_first_search(0);
    REQUIRE(resultingQueue == expectedResult);
}

TEST_CASE("Corner cases", "[searching][breadth_first_search]") {
    Graph testGraph = Graph(6);
    testGraph.addEdge(0,1);
    testGraph.addEdge(1,2);
    testGraph.addEdge(0,2);
    testGraph.addEdge(1,3);
    testGraph.addEdge(3,5);
    testGraph.addEdge(2,4);
    std::vector<int> expectedResult{0,1,2,3,4,5};
    std::vector<int> resultingQueue;
    resultingQueue = testGraph.breadth_first_search(0);
    REQUIRE(resultingQueue == expectedResult);
    std::vector<int> expectedResult2{1,0,2,3,4,5};
    resultingQueue = testGraph.breadth_first_search(1);
    REQUIRE(resultingQueue == expectedResult2);
}
