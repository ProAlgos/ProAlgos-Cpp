
#include "data_structure/graph/graph.hpp"

TEST_CASE("Depht First Search", "[depth_first_search]") {
	Graph graph_struct;
	//add 4 nodes to graph
	graph_struct.push_node(4);
	//make a diamond graph connection
	graph_struct[0].add_connection(graph_struct[1]);
	graph_struct[0].add_connection(graph_struct[2]);
	graph_struct[1].add_connection(graph_struct[3]);
	graph_struct[2].add_connection(graph_struct[3]);
    //call depth_first_search function (after clean the nodes)
	depth_first_search(&graph_struct.first_node());
	//if a node has been set to true, it means algorithm was there, i check if every node would set to true
	for (vector<Graph::Node*>::const_iterator iter = graph_struct.get_all_nodes().begin(); iter != graph_struct.get_all_nodes().end(); iter++)
		REQUIRE((*iter)->it_was() == true);

}
