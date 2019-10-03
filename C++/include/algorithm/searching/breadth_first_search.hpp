/*
    Breadth First Search
    -------------
    A graph searching algorithm that finds the shortest distance between two nodes.

    Time complexity
    ---------------
    O(V+E), where V is the number of vertices and E is the number of edges of the graph.

    Space complexity
    ----------------
    O(V), where V is the number of vertices.
*/

#ifndef BREADTH_FIRST_SEARCH_HPP
#define BREADTH_FIRST_SEARCH_HPP

#include <list>
#include <algorithm>
#include <vector>

using std::list;
using std::vector;

class Graph{
    int numVertices;
    list<int> *adjacencyList;

public:
    Graph(int numberVertices);
    void addEdge(int firstVertex, int secondVertex);
    vector<int> breadth_first_search(int startNode);
};

Graph::Graph(int numberVertices) {
    numVertices = numberVertices;
    adjacencyList = new list<int>[numberVertices];
}

void Graph::addEdge(int firstVertex, int secondVertex) {
    adjacencyList[firstVertex].push_back(secondVertex);
    adjacencyList[secondVertex].push_back(firstVertex);
}

vector<int> Graph::breadth_first_search(int startNode){
    list<int> queue;
    vector<int> resultingQueue;
    list<int> visited;
    int currentVertex;
    bool foundInVisitedList;

    queue.push_back(startNode);
    resultingQueue.push_back(startNode);
    visited.push_back(startNode);

    while (!queue.empty()){
        currentVertex = queue.front();
        queue.pop_front();
        for(auto it = adjacencyList[currentVertex].begin(); it!= adjacencyList[currentVertex].end(); it++){
            foundInVisitedList = (std::find(visited.begin(), visited.end(), *it) != visited.end());
            if(!foundInVisitedList){
                queue.push_back(*it);
                resultingQueue.push_back(*it);
                visited.push_back(*it);
            }
        }
    }

    return resultingQueue;
}

#endif //ALGOS_BREADTH_FIRST_SEARCH_HPP
