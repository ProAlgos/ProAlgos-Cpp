#ifndef GRAPH_UTILS_H
#define GRAPH_UTILS_H

/* utility Graph algorithms */

#include <cstdlib>
#include <iostream>

using namespace std;

void getNumVertices(size_t& vertex_count) {
    cout << "Enter the number of vertices: ";
    cin >> vertex_count;
    if ((int)vertex_count <= 0) {
        cout << "Please enter a positive input\n";
        getNumVertices(vertex_count);
    }
}

void getNumEdges(size_t& edge_count) {
    cout << "Enter the number of edges: ";
    cin >> edge_count;
    if ((int)edge_count <= 0) {
        cout << "Please enter a positive input\n";
        getNumEdges(edge_count);
    }
}

#endif
