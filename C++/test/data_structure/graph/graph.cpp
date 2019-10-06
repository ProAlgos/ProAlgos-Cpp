#include "third_party/catch.hpp"
#include "data_structure/graph/graph.hpp"

TEST_CASE("Graph Data Struct", "[graph_data_struct]") {

        Graph graph_struct;
        SECTION("push_nodes") {
                graph_struct.push_node(3);

                REQUIRE(graph_struct.size() == 3);
                SECTION("get_node|first_node|last_node|remove_node"){

                        SECTION("get_node") {
                                REQUIRE(&graph_struct[1] == &graph_struct.get_node(1));
                                SECTION("first_node|last_node|remove_node") {

                                        SECTION("first_node") {
                                                REQUIRE(&graph_struct[0] == &graph_struct.first_node());
                                        }
                                        SECTION("last_node") {
                                                REQUIRE(&graph_struct[graph_struct.size() - 1] == &graph_struct.last_node());
                                        }

                                        SECTION("remove_node") {
                                                graph_struct.remove_node(graph_struct[1]);
                                                REQUIRE(graph_struct.size() == 2);
                                                SECTION("node add_connection|node remove_connection") {
                                                        graph_struct[0].add_connection(graph_struct[1]);
                                                        REQUIRE(graph_struct[0].get_connection_to_another().at(0) == &graph_struct[1]);
                                                        REQUIRE(graph_struct[1].get_connection_to_me().at(0) == &graph_struct[0]);
                                                        REQUIRE(graph_struct[0].get_connection_to_me().size() == 0);
                                                        REQUIRE(graph_struct[0].get_connection_to_another().size() == 1);
                                                        REQUIRE(graph_struct[1].get_connection_to_me().size() == 1);
                                                        REQUIRE(graph_struct[1].get_connection_to_another().size() == 0);

                                                        graph_struct[0].remove_connection(graph_struct[1]);
                                                        REQUIRE(graph_struct[0].get_connection_to_me().size() == 0);
                                                        REQUIRE(graph_struct[0].get_connection_to_another().size() == 0);
                                                        REQUIRE(graph_struct[1].get_connection_to_me().size() == 0);
                                                        REQUIRE(graph_struct[1].get_connection_to_another().size() == 0);

                                                }
                                        }

                                }
                        }

                }
        }

}
