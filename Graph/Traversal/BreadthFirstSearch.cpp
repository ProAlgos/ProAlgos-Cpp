/* Breadth-first search/traversal
 * iterates through all vertices in an undirected graph in breadth-first order
 *
 * Time-complexity: 
 * O(V + E), where V is number of vertices and E is number of edges
 * Space-complexity:
 * O(V)
 *
 */

#include <queue>
#include "BreadthFirstSearch.h"

void Graph::breadthFirstSearch(int source_vertex) {
    bool visited[num_vertices] = { false }; /* tracks which vertices have been visited */
    std::queue<int> toVisit; /* tracks which vertices to visit next */

    visited[source_vertex] = true;
    toVisit.push(source_vertex);

    int curr_vertex;
    while (!toVisit.empty()) {
        curr_vertex = toVisit.front(); /* next vertex to visit */
        std::cout << curr_vertex << " ";
        
        /* visits all the adjacent vertices and pushes them onto the queue */
        for (auto itr = adj_list[curr_vertex].begin(); itr != adj_list[curr_vertex].end(); itr++) {
            if (!visited[*itr]) {
                visited[*itr] = true;
                toVisit.push(*itr);
            }
        }
        toVisit.pop(); /* traverse to next vertex */
    }
    std::cout << "\n";
}

int main(int argc, char **argv) {
    Graph *undirected_graph;
    undirected_graph = generateGraph();

    int source_vertex;
    std::cout << "Enter the source vertex: ";
    std::cin >> source_vertex;
    while (!undirected_graph->isValidSource(source_vertex)) {
        std::cout << "Invalid source vertex, please enter a valid source index: ";
        std::cin >> source_vertex;
    }
    undirected_graph->breadthFirstSearch(source_vertex);

    return 0;
}
