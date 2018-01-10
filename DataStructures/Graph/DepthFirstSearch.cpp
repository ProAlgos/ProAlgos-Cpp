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

#include "Graph.h"

#define WHITE 0
#define GRAY 1
#define BLACK 2

class DepthFirstSearch
{
private:
    int *colour;
    int *parent;
    int *discovery_time;
    int *finishing_time;
    int time;
public:
    DepthFirstSearch(int n)
    {
        time = 0; // this is the timestamp which is used by the vertices to know when it was discovered and when it was finished
        colour = new int[n](); // initially all the vertex are coloured WHITE
        parent = new int[n](); // parent of all the vertex are initialized to zero
        discovery_time = new int[n](); // initializing discovery_time of each vertex as zero
        finishing_time = new int[n](); // initializing finishing_time of each vertex as zero
    };
    ~DepthFirstSearch()
    {
        delete colour;
        delete parent;
        delete discovery_time;
        delete finishing_time;
    };
    void DepthFirstSearchTraversal(Graph &graph, const int curr_vertex);
};

void DepthFirstSearch :: DepthFirstSearchTraversal(Graph &graph, const int curr_vertex)
{
    //Displaying the current vertex
    std :: cout << curr_vertex << " ";

    //Colour the current vertex with GRAY to mark visited 
    colour[curr_vertex] = GRAY;

    discovery_time[curr_vertex] = time = time +1;

    for(const auto itr : graph.adjacentVertices(curr_vertex))
    {
        if(colour[itr.first] == WHITE)
        {
            parent[itr.first] = curr_vertex;
            DepthFirstSearchTraversal(graph, itr.first);
        }
    }

    //Colour the current vertex with BLACK to mark finish
    colour[curr_vertex] = BLACK;
    finishing_time[curr_vertex] = time = time +1; 
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

    DepthFirstSearch(undirected_graph.numVertices()).DepthFirstSearchTraversal(undirected_graph, source_vertex);
    std :: cout << "\n";
    return 0;
}
