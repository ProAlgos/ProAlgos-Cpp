#pragma once

#include <functional>
#include <iostream>
#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>

struct Node
{
    void AddAdjacentNode(int node, int weight) { adjacent_nodes_with_weights_.emplace_back(node, weight); }

    const auto& GetAdjacentNodes() const { return adjacent_nodes_with_weights_; }

private:
    std::vector<std::pair<int /* node */, int /* weight */>> adjacent_nodes_with_weights_;
};

class UndirectedGraph
{
public:
    UndirectedGraph(int num_nodes) { nodes_.resize(num_nodes); }

    void SetNode(int first, int second, int weight)
    {
        nodes_[first-1].AddAdjacentNode(second, weight);
        nodes_[second-1].AddAdjacentNode(first, weight);
    }

    int NumNodes() const { return nodes_.size(); }

    const auto& GetNodes() const { return nodes_; }

private:
    std::vector<Node> nodes_;
};

int EnterNumber(const std::string& node_text, std::function<bool (int)> is_valid)
{
    static bool valid{false};

    static int node;

    while (!valid)
    {
        std::cout << node_text;
        std::cin >> node;

        if (is_valid(node))
            valid = true;
        else
            std::cout << "Invalid node number.\n";
    }

    valid = false;

    return node;
}

UndirectedGraph GetUndirectedGraphFromInput()
{
    std::cout << "Please input graph details.\n\n";

    int num_nodes;
    std::cout << "Number of nodes: ";
    std::cin >> num_nodes;

    UndirectedGraph graph(num_nodes);

    std::cout << "\nPlease enter edge details.\n";

    while (1)
    {
        int first{EnterNumber("First node (0 to finish edge input): ", [num_nodes](int node){ return node >= 0 && node <= num_nodes; })};

        if (first == 0)
            break;

        int second{EnterNumber("Second node: ", [num_nodes](int node){ return node > 0 && node <= num_nodes; })};

        int weight{EnterNumber("Weight: ", [](int weight){ return weight > 0; })};

        graph.SetNode(first, second, weight);

        std::cout << "\n";
    }

    std::cout << "\n";

    return graph;
}
