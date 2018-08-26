/*
	Kruskal’s Minimum Spanning Tree (MST)
	----------------------
	Kruskal's algorithm is a minimum-spanning-tree algorithm which finds an edge
	of the least possible weight that connects any two trees in the forest. It is
	a greedy algorithm in graph theory as it finds a minimum spanning tree for a
	connected weighted graph adding increasing cost arcs at each step.  This means
	it finds a subset of the edges that forms a tree that includes every vertex,
	where the total weight of all the edges in the tree is minimized.

	Time complexity
	---------------
	O(E log V), where V is the number of vertices and E is number of edges.

	Space complexity
	----------------
	O(V + E), where V is the number of vertices and E is number of edges.
*/

#include <iostream>
#include <time.h>
#include <queue>

using namespace std;

struct node {
	int info, node_i, node_j;
};

class graph {
private:
	int number_of_vertices;			//number of vertices
	void link(int x, int y, int *p, int *r);
	int find_set(int x, int *p);
public:
	int **graph_values;		//the 2d array for graph
	graph(int size) {
		graph_values = new int *[size];
		for (int i = 0; i<size; i++) {
			graph_values[i] = new int[size];
		}
		this->number_of_vertices = size;
	}

	vector <node> mst_kruskal();
protected:
};

vector <node> graph::mst_kruskal() {
	vector <node> last;
	int *p, *r;
	p = new int[number_of_vertices];
	r = new int[number_of_vertices];
	for (int i = 0; i < number_of_vertices; i++) {
		p[i] = i;
		r[i] = 0;
	}
	//the 2d array for graph visted
	bool **visted_matrix;
	visted_matrix = new bool *[number_of_vertices];
	for (int i = 0; i < number_of_vertices; i++) {
		visted_matrix[i] = new bool[number_of_vertices];
	}
	//Initialize gVisted with 0 number
	for (int i = 0; i < number_of_vertices; i++) {
		for (int j = 0; j < number_of_vertices; j++) {
			visted_matrix[i][j] = false;
		}
	}
	//queue for min values
	queue <node> edges;
	for (int k = 0; k < number_of_vertices * number_of_vertices; k++) {
		int min = 1000, min_i = 0, min_j = 0;
		//Find min value
		for (int i = 0; i < number_of_vertices; i++) {
			for (int j = i; j < number_of_vertices; j++) {
				if (graph_values[i][j] < min && visted_matrix[i][j] == false) {
					min = graph_values[i][j];
					min_i = i;
					min_j = j;
				}
			}
		}
		//
		if (min != 1000) {
			node a;
			a.info = min;
			a.node_i = min_i;
			a.node_j = min_j;
			edges.push(a);
			visted_matrix[min_i][min_j] = true;
		}
	}

	int number_of_edges = edges.size();
	for (int i = 0; i < number_of_edges; i++) {
		int v = edges.front().node_i, u = edges.front().node_j, key = edges.front().info;
		if (find_set(u, p) != find_set(v, p)) {
			//A<-A U {u,v}
			node a;
			a.node_i = v;
			a.node_j = u;
			a.info = key;
			last.insert(last.end(), a);

			link(find_set(u, p), find_set(v, p), p, r);
		}
		edges.pop();
	}
	return last;
}

int graph::find_set(int x, int *p) {
	if (x != p[x]) {
		p[x] = find_set(p[x], p);
	}
	return p[x];
}

void graph::link(int x, int y, int *p, int *r) {
	if (r[x]>r[y]) {
		p[y] = x;
	}
	else {
		p[x] = y;
	}
	if (r[x] == r[y]) {
		r[y] = (r[y]) + 1;
	}
}

void sleep(clock_t wait) {
	clock_t goal;
	goal = wait + clock();
	while (goal > clock());
}

int main() {
	int size;
	cin >> size;

	graph input_graph(size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> input_graph.graph_values[i][j];
		}
	}
	vector <node> kruskal_result;
	kruskal_result = input_graph.mst_kruskal();

	cout << "Kruskal result:" << endl;
	int number_of_kru_result = kruskal_result.size();
	for (int i = 0, num = 1; i < number_of_kru_result; i++)
		cout << num++ << "| i=" << kruskal_result[i].node_i << " j=" << kruskal_result[i].node_j << " key=" << kruskal_result[i].info << endl;
	cout << '\n';
	return 0;
}