#include "../../DataStructures/Graph/Graph.h"

#include <queue>

void breadth_first_search(const Graph& graph, const size_t start_location) {
    // rather than exposing the graph's data, get a copy of the adjacency list
    std::vector<Vertex> adj_list = graph.get_adjacency_list();
    std::queue<Vertex> to_visit;

    // visit start location
    to_visit.push(adj_list[start_location]);
    adj_list[start_location].visited = true;

    while (!to_visit.empty()) {
        Vertex front = to_visit.front();
        to_visit.pop();

        std::cout << front.data << " ";

        for (Edge& edge : front.edge_list) {
            if (!adj_list[edge.adjacent_vertex].visited) {
                to_visit.push(adj_list[edge.adjacent_vertex]);
                adj_list[edge.adjacent_vertex].visited = true;
            }
        }
    }

    std::cout << "\n";
}

int main() {
    Graph graph;

    read_vertices_from_user(graph);
    read_edges_from_user(graph);
    size_t start_location = get_start_location(graph);

    std::cout << "The algorithm should start at vertex " << start_location << ".\n";

    breadth_first_search(graph, start_location);

    return EXIT_SUCCESS;
}
