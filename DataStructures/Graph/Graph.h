#ifndef GRAPH_H
#define GRAPH_H

#include <cstdlib>
#include <vector>
#include <list>
#include <iostream>

class Graph {
    /* Graph class representing an undirected weighted graph */
    public:
        Graph() {}
        void generateGraph() {
            getNumVerticesFromUser();
            getNumEdgesFromUser();
            getEdgeFromUser();
        }
        int numVertices() { return num_vertices; }
        std::list< std::pair<int, int> > adjacentVertices(const int curr_vertex) { return adj_list[curr_vertex]; }
        bool isValidSource(const int source_vertex) { return !(source_vertex < 0 || source_vertex >= num_vertices); }
    private:
        int num_vertices;
        int num_edges;
        std::vector< std::list< std::pair<int,int> > > adj_list;
        /* adjacency list representing graph
         * first int represents destination node
         * second int represents weight of the edge
         */
       void addUndirectedEdge(const int source_vertex, const int dest_vertex, const int weight) {
            std::pair<int, int> vertexPair = std::make_pair(dest_vertex, weight);
            adj_list[source_vertex].push_back(vertexPair);
            /* undirected graph so we add the edge both ways */
            vertexPair = std::make_pair(source_vertex, weight);
            adj_list[dest_vertex].push_back(vertexPair);
        }
        void getNumVerticesFromUser() {
            std::cout << "Enter the number of vertices (# > 0): ";
            std::cin >> num_vertices;
            while ((int) num_vertices <= 0) {
                std::cout << "Invalid # of vertices\n";
                std::cout << "Enter the number of vertices (# > 0): ";
                std::cin >> num_vertices;
            }
            this->num_vertices = num_vertices;
            adj_list.resize(num_vertices);
        }
        void getNumEdgesFromUser() {
            std::cout << "Enter the number of edges (# >= 0): ";
            std::cin >> num_edges;
            while ((int) num_edges < 0) {
                std::cout << "Invalid # of edges\n";
                std::cout << "Enter the number of edges (# >= 0): ";
                std::cin >> num_edges;
            }
        }
        void getEdgeFromUser() {
            int first_vertex;
            int second_vertex;
            int weight;
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
                std::cout << "Enter the weight of the edge: ";
                std::cin >> weight;
                addUndirectedEdge(first_vertex, second_vertex, weight);
            }
        }
};

#endif
