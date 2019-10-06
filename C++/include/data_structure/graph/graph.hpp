#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>

using std::iostream;
using std::vector;

class Graph
{
public:
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
                static unsigned node_id;
        protected:
        };
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
        void clear_nodes();
private:
        vector<Graph::Node*> nodes;
        typedef vector<Graph::Node*>::iterator npvi_t;
        Graph::npvi_t& find_delete_node(Graph::npvi_t&, Graph::Node*) const;
protected:
};
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
//NODE
unsigned Graph::Node::node_id = 0;
Graph::Node::Node() : id(Graph::Node::node_id++) {

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
