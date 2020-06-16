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
        
        // returns the index of the added vertex
        // or -1 if it already exists
        int add_vertex(const Vertex& v);

        // returns EXIT_SUCCESS
        // or -1 if it already exists
        int add_edge   (int weight, const Vertex& v1, const Vertex& v2);
        int remove_edge(const Vertex& v1, const Vertex& v2)            ;
   


        /* get methods */  
        int get_index               (const Vertex& v)                   ;
        int get_weight              (const Vertex& v1, const Vertex& v2);
        int get_num_vertices        ()                                  ;
        vector<Vertex>& get_vertices()                                  ; 
    
    private:

        // this integer identifies each vertex in our map.
        // we increase it every time we add a vertex. 
        // It never decreases
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


template<typename Vertex>
int Graph<Vertex>::get_index(const Vertex& v) {
    for (auto it : indices) {
        if (it.second == v) {
            return it.first;
        }
    }
    return -1;
}

template<typename Vertex>
int Graph<Vertex>::add_vertex(const Vertex& v) { 
    
    int idx = get_index(v);
    
    if (idx != -1) {
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

//will silently fail if either v1 or v2 does not exist
template<typename Vertex>
int Graph<Vertex>::add_edge(int weight, const Vertex& v1, const Vertex& v2) {
    
    int idx_v1, idx_v2;
    if (v1 != v2) {
        idx_v1 = get_index(v1);
        idx_v2 = get_index(v2);
    } else {
        idx_v1 = get_index(v1);
        idx_v2 = idx_v1;
    }
    
    if (matrix[idx_v1][idx_v2] != 0) {
        return -1;
    } else {
        if (!directed) {
            printf("OK\n");
            matrix[idx_v1][idx_v2] = weight;
            matrix[idx_v2][idx_v1] = weight;
        } else {
            matrix[idx_v1][idx_v2] = weight;
        }
    }
    return EXIT_SUCCESS; 
}

template<typename Vertex>
int Graph<Vertex>::remove_edge(const Vertex& v1, const Vertex& v2) {
    int idx_v1, idx_v2; 
    if (v1 != v2) {
        idx_v1 = get_index(v1);
        idx_v2 = get_index(v2);
    } else {
        idx_v1 = get_index(v1);
        idx_v2 = idx_v1;
    }
    
    if (matrix[idx_v1][idx_v2] == 0) {
        return -1;
    } else {
        if (!directed) {
            matrix[idx_v1][idx_v2] = 0;
            matrix[idx_v2][idx_v1] = 0;
        } else {
            matrix[idx_v1][idx_v2] = 0;
        }
    }
    return EXIT_SUCCESS;
}

template<typename Vertex>
int Graph<Vertex>::get_weight(const Vertex& v1, const Vertex& v2) {
    int idx_v1, idx_v2; 
    if (v1 != v2) {
        idx_v1 = get_index(v1);
        idx_v2 = get_index(v2);
    } else {
        idx_v1 = get_index(v1);
        idx_v2 = idx_v1;
    }
    
    return matrix[idx_v1][idx_v2];
}

template<typename Vertex>
int Graph<Vertex>::get_num_vertices() {
    
    return matrix.size();
}

template<typename Vertex>
vector<Vertex>& Graph<Vertex>::get_vertices() {
    vector<Vertex> vertices;
    for (auto it : indices) {
        vertices.push_back(it.second);
    }
    return *vertices;
}

#endif
