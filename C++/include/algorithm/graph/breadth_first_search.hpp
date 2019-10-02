/*  Breadth First Search
    -------------------
    Breadth First Search algorithm traverses the graph, level by level.
    You have to a give a graph in which you want to travel,after you have to add the start node.
    After that you need to add the final deep level what is the last deep level until algotithm goes from start node.
    You can overwrite the next deep level what will be the first deep level from start node where algorithm will start.
    This gives you a chance to select a part of graph where you want to travel.

    Time complexity
    ---------------
     O(|V|) where |V| is the number of nodes

    Space complexity
    ----------------
     O(|V|) where |V| is the number of nodes
*/

#ifndef BREADTH_FIRST_SEARCH_HPP
#define BREADTH_FIRST_SEARCH_HPP

#include "data_structure/graph/graph.hpp"

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
        cout << "node id:" << node->get_id() << "   " << "deep level:" << static_cast<unsigned int>(next_deep_level) << endl;
}
#endif //BREADTH_FIRST_SEARCH_HPP
