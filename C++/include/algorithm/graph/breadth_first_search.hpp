/*
    Breadth First Search
    -----------
    Breadth First Search algorithm goes in a graph, (what you have to add) until the end, by level by level.
    You have to add the "start node",what is a pointer to a node. "Next deep level" is the  next deep level where the algorithm will go from the start node,this default value is 1 but you can overwrite it first time.
    "Final Deep level" is the last deep level where the algotithm will go.This give you a chance to select a part in the graph you want to search in.

    Time complexity
    ---------------
    O(n) where n is the number of nodes in the tree.

    Space complexity
    ----------------
    O(n)
*/


#ifndef BREADTH_FIRST_SEARCH_HPP
#define BREADTH_FIRST_SEARCH_HPP

#include "..\..\data_structure\graph\graph.hpp"

void breadth_first_search(Graph& graph, Graph::Node*node,const uint8_t final_deep_level, uint8_t next_deep_level = 1, uint8_t actual_deep = 0) {
        if (actual_deep != next_deep_level) {
                uint16_t counter(0);
                while (counter < node->get_connection_to_another().size())
                {
                        if (!(node->get_connection_to_another().at(counter)->it_was() == true && (actual_deep + 1) == next_deep_level))
                                breadth_first_search(graph,node->get_connection_to_another().at(counter), final_deep_level, next_deep_level, actual_deep + 1);
                        counter++;
                }
                if (actual_deep == 0) {
                        graph.clear_nodes();
                        if (next_deep_level < final_deep_level)
                                breadth_first_search(graph,node,final_deep_level, next_deep_level + 1);
                }
                return;
        }
        node->set_was(true);
        cout << "id: " << node->get_id() << " deep: " << static_cast<unsigned int>(next_deep_level) << endl;
}
#endif //BREADTH_FIRST_SEARCH_HPP
