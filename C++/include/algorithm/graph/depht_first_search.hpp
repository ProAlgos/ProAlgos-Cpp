/*  Depht First Search
    -------------------
     Depth first algorithm goes to every nodes of graph.
     You have to give a pointer to a node of graph.
     The algorithm walks on every  way once.

    Time complexity
    ---------------
      O(|V|) where |V| is the number of nodes

    Space complexity
    ----------------
      O(h) where h is the maximal depth of the graph
*/
#ifndef DEPHT_FIRST_SEARCH_HPP
#define DEPHT_FIRST_SEARCH_HPP

#include "data_structure/graph/graph.hpp"

void depth_first_search(Graph::Node* node) {
        uint16_t counter(0);
        while (counter < node->get_connection_to_another().size())
        {
                if (!node->get_connection_to_another().at(counter)->it_was())
                        depth_first_search(node->get_connection_to_another().at(counter));
                counter++;
        }
        node->set_was(true);
}

#endif //DEPHT_FIRST_SEARCH_HPP
