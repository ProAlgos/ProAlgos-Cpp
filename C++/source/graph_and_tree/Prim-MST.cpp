/*
	Prim’s Minimum Spanning Tree (MST)
	----------------------
	Prim's algorithm is a greedy algorithm that finds a minimum spanning tree for
	a weighted undirected graph. It finds a subset of the edges that forms a tree
	that includes every vertex, where the total weight of all the edges in the
	tree is minimized.

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

	int * mst_prim(int start);
protected:
};

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

int * graph::mst_prim(int start) {
	//Start begin with 0 to N
	int *key, *p;
	bool *visited;
	p = new int[number_of_vertices];
	p[start] = 1000;
	key = new int[number_of_vertices];

	visited = new bool[number_of_vertices];
	for (int i = 0; i<number_of_vertices; i++) {
		visited[i] = false;
	}
	key[start] = 0;
	for (int i = 1; i<number_of_vertices; i++) {
		key[i] = 1000;
	}

	while (1) {
		bool queue_empty = true;
		for (int i = 0; i < number_of_vertices; i++) {
			if (visited[i] == false)
				queue_empty = false;
		}
		if (queue_empty) {
			//Find parent with p and index of p
			break;
		}
		else {
			//Find Minimun number that is not visited
			int min = 1000, min_index = 0;
			for (int i = 0; i < number_of_vertices; i++) {
				if (key[i] <= min && visited[i] == false) {
					min = key[i];
					min_index = i;
				}
			}
			visited[min_index] = true;

			for (int i = 0; i < number_of_vertices; i++) {
				if (graph_values[min_index][i] != 1000 && visited[i] == false) {
					if (graph_values[min_index][i] < key[i]) {
						p[i] = min_index;
						key[i] = graph_values[min_index][i];
					}
				}
			}
		}
	}
	return p;
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
	int *prim_result;
	prim_result = input_graph.mst_prim(0);

	cout << "Prim result:" << endl;
	for (int i = 0, num = 1; i < size; i++)
		if (prim_result[i] != 1000)
			cout << num++ << "| i=" << prim_result[i] << " j=" << i << " key=" << input_graph.graph_values[i][prim_result[i]] << endl;
	cout << '\n';
	return 0;
}