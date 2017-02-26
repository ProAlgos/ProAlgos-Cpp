#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <string>
#include <cctype>
#include <vector>

struct Edge {
    Edge(int adj_vertex, int weight) {
        adjacent_vertex = adj_vertex;
        this->weight = weight;
    }

    int adjacent_vertex;
    int weight;
};

struct Vertex {
    Vertex(int data) {
        this->data = data;
    }

    void connect_to(size_t destination_vertex, int weight) {
        edge_list.emplace_back(destination_vertex, weight);
    }

    int data;
    std::vector<Edge> edge_list;
};

class Graph {
    public:
        Graph() {
            num_vertices = 0;
        }

        void insert(int data) {
            adjacency_list.emplace_back(data);
            ++num_vertices;
        }

        bool connect(size_t source_vertex, size_t destination_vertex, int weight) {
            if (source_vertex > num_vertices - 1 || destination_vertex > num_vertices - 1 ||
                    source_vertex == destination_vertex)
                return false;

            adjacency_list[source_vertex].connect_to(destination_vertex, weight);
            adjacency_list[destination_vertex].connect_to(source_vertex, weight);

            return true;
        }

        size_t size() const {
            return num_vertices;
        }
    
    private:
        std::vector<Vertex> adjacency_list;
        size_t num_vertices;
};

bool again(const std::string& action) {
    std::cout << "Do you want to " << action << " again? (y/n): ";
    char response;
    std::cin >> response;
    std::cin.ignore(100, '\n');
    response = toupper(response);

    return 'Y' == response;
}

void read_vertices_from_user(Graph& graph) {
    do {
        std::cout << "\nEnter an integer to add to the graph: ";
        int response = 0;
        std::cin >> response;
        std::cin.ignore(100, '\n');

        graph.insert(response);
    } while (again("add a vertex to the graph"));
}

void read_edges_from_user(Graph& graph) {
    std::cout << "\nInsert an edge with by entering three numbers in this format: x y weight\n"
              << " where x and y are vertex numbers 0-" << graph.size() - 1 << " and weight is an integer.";
    do {
        std::cout << "\n\t > ";
        size_t vertex_src = 0;
        size_t vertex_dest = 0;
        int weight = 0;
        std::cin >> vertex_src >> vertex_dest >> weight;
        std::cin.ignore(100, '\n');
    } while (again("insert an edge between two vertices"));
}

size_t get_start_location(const Graph& graph) {
    std::cout << "\nWhat vertex should the algorithm start at? (0-" << graph.size() - 1 << "): ";
    size_t start_vertex = 0;
    std::cin >> start_vertex;
    std::cin.ignore(100, '\n');

    if (start_vertex > graph.size() - 1) {
        std::cerr << "You entered an invalid index. Please try again.\n";
        return get_start_location(graph);
    }

    return start_vertex;
}

#endif
