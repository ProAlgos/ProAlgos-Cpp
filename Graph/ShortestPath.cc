#include <iostream>
#include <limits>
#include <tuple>
#include <vector>

#include "UndirectedGraph.h"

// Implements an algorithm to find the shortest distance between two nodes in a weighted undirected graph.
//
// Space complexity:
// O(N + E) where N is the number of nodes and E is the number of edges
//
// Time complexity:
// O(N^2) where N is the number of nodes

int ShortestPath(const UndirectedGraph& graph, const int current_node, const int end_node)
{
    // For each node, we hold a pair to represent its current best shortest path value.
    // Each is initialised to inf.
    std::vector<int> node_shortest_path_values(graph.NumNodes(), std::numeric_limits<int>::max());

    // Set path length for the start node to 0.
    node_shortest_path_values[current_node-1] = 0;

    std::vector<int> nodes_changed_last_iteration{current_node};

    while (!nodes_changed_last_iteration.empty())
    {
        for (int index = nodes_changed_last_iteration.size() - 1; index >= 0; --index)
        {
            int node = nodes_changed_last_iteration[index];
            nodes_changed_last_iteration.pop_back();

            for (const auto& pair : graph.GetNodes()[node-1].GetAdjacentNodes())
            {
                int& shortest_path{node_shortest_path_values[pair.first-1]};
                int path_length = node_shortest_path_values[node-1] + pair.second;

                if (path_length < shortest_path)
                {
                    shortest_path = path_length;
                    nodes_changed_last_iteration.push_back(pair.first);
                }
            }
        }
    }

    return node_shortest_path_values[end_node-1];
}

int main()
{
    UndirectedGraph graph{GetUndirectedGraphFromInput()};

    int start_node{EnterNumber("Start node: ", [&graph](int node){ return node > 0 && node <= graph.NumNodes(); })};
    int end_node{EnterNumber("End node: ", [&graph](int node){ return node > 0 && node <= graph.NumNodes(); })};

    int shortest_path{ShortestPath(graph, start_node, end_node)};

    if (shortest_path == std::numeric_limits<int>::max())
        std::cout << "There is not path from " << start_node << " to " << end_node << "\n";
    else
        std::cout << "Shortest path from node " << start_node << " to node " << end_node << " is " << ShortestPath(graph, start_node, end_node) << "\n";

    return 0;
}
