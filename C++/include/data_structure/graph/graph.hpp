#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>

using std::iostream;
using std::vector;

class Graph
{
private:
        class Node {
        public:
                Node();
                ~Node();
                void add_connection(Graph::Node*);
                void add_connection(Graph::Node&);
                void remove_connection(Graph::Node*);
                void remove_connection(Graph::Node&);
                const vector<Graph::Node*>& get_connection_to_another() const;
                const vector<Graph::Node*>& get_connection_to_me() const;
                const unsigned& get_id() const;
                const unsigned& set_id(const unsigned);
                const bool& it_was() const;
                const bool& set_was(const bool);
        private:
                friend class Graph;
            vector<Graph::Node*> connections_to_another;
                vector<Graph::Node*> connections_to_me;
                bool was = false;
                unsigned id;
                static unsigned NODE_ID;
        protected:
        };
        typedef vector<Graph::Node*>::iterator npvi_t;
        vector<Graph::Node*> nodes;
        void clear_nodes();
        void depth_first_search_core(Graph::Node*);
        void breadth_first_search_core(Graph::Node*, const uint16_t, uint16_t, uint16_t);
        Graph::npvi_t& find_delete_node(Graph::npvi_t&, Graph::Node*) const;
public:
        Graph();
        ~Graph();
        Graph::Node& push_node(const unsigned = 1);
        void remove_node(Graph::Node&);
        void remove_node(Graph::Node*);
        void remove_node(const unsigned int);
        Graph::Node& first_node() const;
        Graph::Node& last_node() const;
        Graph::Node& get_node(const unsigned int&) const;
        Graph::Node& operator[](const unsigned int&) const;
        size_t size() const;
        const vector<Graph::Node*>& get_all_nodes() const;
        void depth_first_search(Graph::Node*);
        void breadth_first_search(Graph::Node*,const uint16_t);
protected:
};
//-----------------------------Graph Class implementation----------------------------
Graph::Graph() {


}
Graph::~Graph() {
        for (Graph::npvi_t delete_iter = this->nodes.begin(); delete_iter != this->nodes.end(); delete_iter++) {
                free(*delete_iter);
        }
}
Graph::Node& Graph::push_node(const unsigned elements) {
        for (unsigned counter(0);counter < elements;++counter)
                this->nodes.push_back(new Graph::Node());
        return *this->nodes.back();
}
void Graph::remove_node(Graph::Node& delete_node) {
        Graph::npvi_t iter = this->nodes.begin();
        if (this->find_delete_node(iter, &delete_node) == this->nodes.end())return;
        delete *iter;
        this->nodes.erase(iter);
}
void Graph::remove_node(Graph::Node* delete_node) {
        this->remove_node(*delete_node);
}
void Graph::remove_node(const unsigned int delete_node) {
        Graph::npvi_t iter = this->nodes.begin();
        iter += delete_node;
        delete *iter;
        this->nodes.erase(iter);
}
Graph::npvi_t& Graph::find_delete_node(Graph::npvi_t &iter, Graph::Node* node_ptr) const {
        for (;iter != this->nodes.end() && *iter != node_ptr;iter++);
        return iter;
}
Graph::Node& Graph::first_node() const {
        return *this->nodes.front();
}
Graph::Node& Graph::last_node() const {
        return *this->nodes.back();
}
size_t Graph::size() const {
        return this->nodes.size();
}
Graph::Node& Graph::get_node(const unsigned int&index) const {
        return *this->nodes.at(index);
}
Graph::Node& Graph::operator[](const unsigned int&index) const {
        return *this->nodes.at(index);
}
void Graph::clear_nodes() {
        for (Graph::npvi_t iter = this->nodes.begin(); iter != this->nodes.end(); iter++)
                (*iter)->was = false;
}
//-------------------------------Graph Algorithms-------------------------------
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
//-------------------------------Depth First Search-------------------------------
void Graph::depth_first_search_core(Graph::Node* node) {
        uint16_t counter(0);
        while (counter < node->get_connection_to_another().size())
        {
                if (!node->get_connection_to_another().at(counter)->it_was())
                        depth_first_search_core(node->get_connection_to_another().at(counter));
                counter++;
        }
        node->set_was(true);
        cout << "Node ID: " <<  node->get_id() << endl;
}
//-------------------------Check Before Call The Algorithm-------------------------
void Graph::depth_first_search(Graph::Node *node) {

        if (node && find(this->nodes.begin(), this->nodes.end(), node) != nodes.end()) {
                Graph::depth_first_search_core(node);
                this->clear_nodes();
        }
}
/*
        Breadth First Search
        -----------
        Breadth First Search algorithm goes in a graph, until the end, by level by level.
        You have to add the "start node",what is a pointer to a node. "Next deep level" is the  next deep level where the algorithm will go from the start node,this default value is 1
        "Final Deep level" is the last deep level where the algotithm will go.This give you a chance to select a part in the graph you want to search in.

        Time complexity
        ---------------
        O(n) where n is the number of nodes in the tree.

        Space complexity
        ----------------
        O(n)
*/
//-------------------------------Breadth First Search-------------------------------
void Graph::breadth_first_search_core(Graph::Node*node, const uint16_t final_deep_level, uint16_t next_deep_level = 1, uint16_t actual_deep = 0) {
        if (actual_deep != next_deep_level) {
                uint16_t counter(0);
                while (counter < node->get_connection_to_another().size())
                {
                        if (!(node->get_connection_to_another().at(counter)->it_was() == true && (actual_deep + 1) == next_deep_level))
                                breadth_first_search_core(node->get_connection_to_another().at(counter), final_deep_level, next_deep_level, actual_deep + 1);
                        counter++;
                }
                if (actual_deep == 0) {
                        this->clear_nodes();
                        if (next_deep_level < final_deep_level)
                                breadth_first_search_core(node, final_deep_level, next_deep_level + 1);
                }
                return;
        }
        node->set_was(true);
        cout << "Node ID: " << node->get_id() << " Deep Level: " << static_cast<unsigned int>(next_deep_level) << endl;
}
//-------------------------Check Before Call The Algorithm-------------------------
void Graph::breadth_first_search(Graph::Node* node, const uint16_t final_deep_level) {

        if (node && find(this->nodes.begin(), this->nodes.end(), node) != this->nodes.end())
                Graph::breadth_first_search_core(node,final_deep_level);
}
//-----------------------------Node Class implementation----------------------------
unsigned Graph::Node::NODE_ID = 0;
Graph::Node::Node() : id(Graph::Node::NODE_ID++) {

}
Graph::Node::~Node()
{
        Graph::npvi_t iter_ctm = this->connections_to_me.begin(), iter_cta = this->connections_to_another.begin();
        while (iter_ctm != this->connections_to_me.end() || iter_cta != this->connections_to_another.end())
        {
                if (iter_ctm != this->connections_to_me.end())
                        for (Graph::npvi_t iter_cta_up_node = (*iter_ctm)->connections_to_another.begin(); iter_cta_up_node != (*iter_ctm)->connections_to_another.end(); iter_cta_up_node++) {
                                if (*iter_cta_up_node == this) {
                                        (*iter_ctm)->connections_to_another.erase(iter_cta_up_node);
                                        iter_ctm++;
                                        break;
                                }
                        }
                if (iter_cta != this->connections_to_another.end())
                        for (Graph::npvi_t iter_cta_down_node = (*iter_cta)->connections_to_me.begin(); iter_cta_down_node != (*iter_cta)->connections_to_me.end(); iter_cta_down_node++) {
                                if (*iter_cta_down_node == this) {
                                        (*iter_cta)->connections_to_me.erase(iter_cta_down_node);
                                        iter_cta++;
                                        break;
                                }
                        }
        }

}
void Graph::Node::add_connection(Graph::Node* connect_node) {
        this->connections_to_another.push_back(connect_node);
        connect_node->connections_to_me.push_back(this);
}
void Graph::Node::add_connection(Graph::Node& connect_node) {
        this->connections_to_another.push_back(&connect_node);
        connect_node.connections_to_me.push_back(this);
}
void Graph::Node::remove_connection(Graph::Node* remove_connect_node) {
        for (Graph::npvi_t iter_cta = this->connections_to_another.begin(); iter_cta != this->connections_to_another.end(); iter_cta++) {
                if (*iter_cta == remove_connect_node)
                {
                        this->connections_to_another.erase(iter_cta);
                        for (Graph::npvi_t iter_ctm = remove_connect_node->connections_to_me.begin(); iter_ctm != remove_connect_node->connections_to_me.end(); iter_ctm++)
                        {
                                if (*iter_ctm == this) {
                                        remove_connect_node->connections_to_me.erase(iter_ctm);
                                        break;

                                }
                        }
                        break;
                }
        }
}
void Graph::Node::remove_connection(Graph::Node &remove_connect_node) {
        this->remove_connection(&remove_connect_node);
}
const vector<Graph::Node*>& Graph::Node::get_connection_to_another() const {
        return this->connections_to_another;
}
const vector<Graph::Node*>& Graph::Node::get_connection_to_me() const {
        return this->connections_to_me;
}
const unsigned& Graph::Node::get_id() const {
        return this->id;
}
const unsigned& Graph::Node::set_id(const unsigned new_id) {
        return this->id = new_id;
}
const bool& Graph::Node::it_was() const {
        return this->was;
}
const bool& Graph::Node::set_was(const bool new_was) {
        return this->was = new_was;
}
const vector<Graph::Node*>& Graph::get_all_nodes() const {
        return this->nodes;
}
#endif // GRAPH_HPP
