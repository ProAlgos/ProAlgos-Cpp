/*
    Depth First Search
    -----------
    Depth First Search gets around all the way in a graph.

    Time complexity
    ---------------
    O(n) where n is the number of nodes in the tree.

    Space complexity
    ----------------
    O(d) where d is the maximum depth of the tree
*/

#ifndef DEPHT_FIRST_SEARCH_HPP
#define DEPHT_FIRST_SEARCH_HPP

#include "..\..\data_structure\graph\graph.hpp"

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
