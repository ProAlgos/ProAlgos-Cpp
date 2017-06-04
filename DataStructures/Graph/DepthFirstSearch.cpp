/* Depth-first search/traversal
 * iterates through all vertices in an undirected graph in Depth-first order
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

void DepthFirstSearchTraversal(Graph &graph, const int curr_vertex, bool *visited)
{
    //Making the current vertex visited
    visited[curr_vertex] = true;

    std :: cout << curr_vertex << " ";
    for(const auto itr : graph.adjacentVertices(curr_vertex))
    {
        if(!visited[itr.first])
            DepthFirstSearchTraversal(graph, itr.first, visited);
    }
}

void DepthFirstSearch(Graph &graph, const int source_vertex) {
    bool *visited = new bool[graph.numVertices()](); /* tracks which vertices have been visited */
    DepthFirstSearchTraversal(graph,source_vertex, visited);
    std :: cout << "\n";
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

    DepthFirstSearch(undirected_graph, source_vertex);

    return 0;
}
