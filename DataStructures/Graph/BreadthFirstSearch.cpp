/* Breadth-first search/traversal
 * iterates through all vertices in an undirected graph in breadth-first order
 *
 * Time-complexity: 
 * O(V + E), where V is number of vertices and E is number of edges
 *
 * Space-complexity:
 * O(V)
 *
 */

#include <queue>
#include "Graph.h"

void breadthFirstSearch(Graph &graph, const int source_vertex) {
    bool visited[graph.numVertices()] = { false }; /* tracks which vertices have been visited */
    std::queue<int> toVisit; /* tracks which vertices to visit next */

    visited[source_vertex] = true;
    toVisit.push(source_vertex);

    int curr_vertex;
    while (!toVisit.empty()) {
        curr_vertex = toVisit.front(); /* current vertex being visited */
        std::cout << curr_vertex << " ";
        
        /* visits all the adjacent vertices and pushes them onto the queue */
        for (const auto itr : graph.adjacentVertices(curr_vertex)) {
            if (!visited[itr.first]) {
                visited[itr.first] = true;
                toVisit.push(itr.first);
            }
        }
        toVisit.pop(); /* traverse to next vertex */
    }
    std::cout << "\n";
}

int main() {
    /* declare and generate the graph */
    Graph undirected_graph;
    undirected_graph.generateGraph();

    /* prompts user for source vertex */
    int source_vertex;
    std::cout << "Enter the source vertex: ";
    std::cin >> source_vertex;
    while (!undirected_graph.isValidSource(source_vertex)) {
        std::cout << "Invalid source vertex, please enter a valid source index: ";
        std::cin >> source_vertex;
    }

    breadthFirstSearch(undirected_graph, source_vertex);

    return 0;
}
