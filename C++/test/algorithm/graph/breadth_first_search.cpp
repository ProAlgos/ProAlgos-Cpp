
#include "data_structure/graph/graph.hpp"

TEST_CASE("Breadth First Search", "[breadth_first_search]") {

	Graph graph_struct;
	//add 4 nodes to graph
	graph_struct.push_node(4);
	//make a pearl graph connection
	graph_struct[0].add_connection(graph_struct[1]);
	graph_struct[1].add_connection(graph_struct[2]);
	graph_struct[2].add_connection(graph_struct[3]);

	breadth_first_search(graph_struct, &graph_struct.first_node(),0,0); //deep from 0 until level (0)
	REQUIRE(graph_struct[0].it_was() == true);
	graph_struct.clear_nodes();

	breadth_first_search(graph_struct, &graph_struct.first_node(), 1); //deep from (1 !Default) until level (1)
	REQUIRE(graph_struct[1].it_was() == true);
	graph_struct.clear_nodes();

	breadth_first_search(graph_struct, &graph_struct.first_node(), 2); //deep from (1 !Default) until level (2)
	REQUIRE((graph_struct[1].it_was() == true && graph_struct[2].it_was() == true));
	graph_struct.clear_nodes();

	breadth_first_search(graph_struct, &graph_struct.first_node(), 3); //deep from (1 !Default) until level (3)
	REQUIRE((graph_struct[1].it_was() == true && graph_struct[2].it_was() == true && graph_struct[3].it_was() == true));
	graph_struct.clear_nodes();

	breadth_first_search(graph_struct, &graph_struct.first_node(),3,2); //deep from (2) until level (3)
	REQUIRE((graph_struct[2].it_was() == true && graph_struct[3].it_was() == true));
	graph_struct.clear_nodes();

}

