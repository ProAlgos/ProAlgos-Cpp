/*
 *  Adjacency Matrix of a Graph
 *  
 *  A graph is a collection of vertices and edges.
 *  An adjacency matrix is a possible implementation of a graph,
 *  represented by a 2D array of size VxV where V is the number
 *  of vertices. Let adj[][] be the 2D array, a slot adj[i][j] = w
 *  means that there is an edge from vertex i to vertex j with
 *  weight w. If w = 0, then there is no edge.
 *
 *  Time Complexity
 *
 * */


#ifndef ADJACENCY_MATRIX_HPP
#define ADJACENCY_MATRIX_HPP

#include <iostream>
#include <vector>
#include <map>

using std::vector;
using std::map;

template<typename Vertex>
class Graph {
    
    public:
        
        Graph(bool is_directed);
        virtual ~Graph()       ;
        
        /* set methods */        
        int add_vertex(const Vertex& v);
        int add_edge   (int weight, const Vertex& vertex_1, const Vertex& vertex_2);
        int remove_edge(const Vertex& vertex_1, const Vertex& vertex_2)            ;
   


        /* get methods */  
        int get_index               (const Vertex& v)                   ;
        int get_weight              (const Vertex& vertex_1, const Vertex& vertex_2);
        int get_num_vertices        ()                                  ;
        vector<Vertex>& get_vertices()                                  ; 
        Vertex& get_vertex          (int index)                         ;
    
    private:

        // this integer identifies each vertex in our map. We increase it every time we add a vertex. It never decreases
        int                  index   ;

        vector<vector<int> > matrix  ;
        map<int, Vertex>     indices ;
        bool                 directed;
};

template<typename Vertex>
Graph<Vertex>::Graph(bool is_directed) {
    index = -1;
    directed = is_directed;
}

template<typename Vertex>
Graph<Vertex>::~Graph() {
    indices.clear();
    matrix.clear();
    index = -1;
}

// TODO how to deal with non-existent indices?
template<typename Vertex>
Vertex& Graph<Vertex>::get_vertex(int index) {
    auto it = indices.find(index);
    if (it != indices.end()) {
        return it->second;
    }
}

template<typename Vertex>
vector<Vertex>& Graph<Vertex>::get_vertices() {
    vector<Vertex> vertices;
    for (auto it : indices) {
        vertices.push_back(it.second);
    }
    return *vertices;
}

template<typename Vertex>
int Graph<Vertex>::get_index(const Vertex& v) {
    for (auto it : indices) {
        if (it.second == v) {
            return it.first;
        }
    }
    return -1;
}

// returns the index of the added vertex
// or -1 if it already exists        
template<typename Vertex>
int Graph<Vertex>::add_vertex(const Vertex& v) { 
    
    int index = get_index(v);
    
    if (index != -1) {
        return -1;
    } else {
        index++;
        indices.insert({index, v});
        vector<int> new_vertex(matrix.size(), 0);
        matrix.push_back(new_vertex);
        
        for (int i = 0; i < matrix.size(); i++) {
            matrix[i].push_back(0);
        }
    }
     
    return index;
}


// returns 0 if OK
// or -1 if it already exists        
// will silently fail if either vertex_1 or vertex_2 does not exist
template<typename Vertex>
int Graph<Vertex>::add_edge(int weight, const Vertex& vertex_1, const Vertex& vertex_2) {
    
    int index_vertex_1, index_vertex_2;
    if (vertex_1 != vertex_2) {
        index_vertex_1 = get_index(vertex_1);
        index_vertex_2 = get_index(vertex_2);
    } else {
        index_vertex_1 = get_index(vertex_1);
        index_vertex_2 = index_vertex_1;
    }
    
    if (matrix[index_vertex_1][index_vertex_2] != 0) {
        return -1;
    } else {
        if (!directed) {
            matrix[index_vertex_1][index_vertex_2] = weight;
            matrix[index_vertex_2][index_vertex_1] = weight;
        } else {
            matrix[index_vertex_1][index_vertex_2] = weight;
        }
    }
    return 0; 
}

template<typename Vertex>
int Graph<Vertex>::remove_edge(const Vertex& vertex_1, const Vertex& vertex_2) {
    int index_vertex_1, index_vertex_2; 
    if (vertex_1 != vertex_2) {
        index_vertex_1 = get_index(vertex_1);
        index_vertex_2 = get_index(vertex_2);
    } else {
        index_vertex_1 = get_index(vertex_1);
        index_vertex_2 = index_vertex_1;
    }
    
    if (matrix[index_vertex_1][index_vertex_2] == 0) {
        return -1;
    } else {
        if (!directed) {
            matrix[index_vertex_1][index_vertex_2] = 0;
            matrix[index_vertex_2][index_vertex_1] = 0;
        } else {
            matrix[index_vertex_1][index_vertex_2] = 0;
        }
    }
    return 0;
}

template<typename Vertex>
int Graph<Vertex>::get_weight(const Vertex& vertex_1, const Vertex& vertex_2) {
    int index_vertex_1, index_vertex_2; 
    if (vertex_1 != vertex_2) {
        index_vertex_1 = get_index(vertex_1);
        index_vertex_2 = get_index(vertex_2);
    } else {
        index_vertex_1 = get_index(vertex_1);
        index_vertex_2 = index_vertex_1;
    }
    
    return matrix[index_vertex_1][index_vertex_2];
}

template<typename Vertex>
int Graph<Vertex>::get_num_vertices() {
    
    return matrix.size();
}

#endif
