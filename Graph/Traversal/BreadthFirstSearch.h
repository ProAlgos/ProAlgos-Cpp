#ifndef BREATHFIRSTSEARCH_H
#define BREATHFIRSTSEARCH_H

#include <cstdlib>
#include <vector>
#include <list>
#include <iostream>

class Graph {
        int num_vertices;
        std::vector< std::list<int> > adj_list; /* adjacency list representing graph */
    public:
        Graph(int num_vertices) {
            this->num_vertices = num_vertices;
            adj_list.resize(num_vertices);
        }
        void addEdge(int source_vertex, int dest_vertex) { adj_list[source_vertex].push_back(dest_vertex); }
        bool isValidSource(int source_vertex) { return !(source_vertex < 0 || source_vertex >= num_vertices); }
        /* prints BFS-traversal from a source vertex */
        void breadthFirstSearch(int source_vertex);
};

Graph *generateGraph() { /* calls BFS-traversal */
    int num_vertices;
    int num_edges;

    std::cout << "Enter the number of vertices (# > 0): ";
    std::cin >> num_vertices;
    while ((int) num_vertices <= 0) {
        std::cout << "Invalid # of vertices\n";
        std::cout << "Enter the number of vertices (# > 0): ";
        std::cin >> num_vertices;
    }
    Graph *graph = new Graph(num_vertices);

    std::cout << "Enter the number of edges (# >= 0): ";
    std::cin >> num_edges;
    while ((int) num_edges < 0) {
        std::cout << "Invalid # of edges\n";
        std::cout << "Enter the number of edges (# >= 0): ";
        std::cin >> num_edges;
    }

    int first_vertex;
    int second_vertex;
    for (int i = 0; i < num_edges; i++) {
        std::cout << "Enter the edge pair as two separate numbers (counting from 0): ";
        std::cin >> first_vertex;
        std::cin >> second_vertex;
        while (first_vertex < 0 || first_vertex >= num_vertices ||
            second_vertex < 0 || second_vertex >= num_vertices) {
            std::cout << "Invalid input\n";
            std::cout << "Enter the edge pair as two separate numbers (counting from 0): ";
            std::cin >> first_vertex;
            std::cin >> second_vertex;
        }
        graph->addEdge(first_vertex, second_vertex);
    }

    return graph;
}

#endif
