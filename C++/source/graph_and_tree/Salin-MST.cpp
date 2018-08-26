/*
	Salin’s Minimum Spanning Tree (MST)
	----------------------
	Salin's algorithm is a greedy algorithm that finds a minimum spanning tree for
	a weighted undirected graph.

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
	int num_of_vertices;			//number of vertices
	void link(int x, int y, int *p, int *r);
	int find_set(int x, int *p);
public:
	int **graph_values;		//the 2d array for graph
	graph(int size) {
		graph_values = new int *[size];
		for (int i = 0; i < size; i++) {
			graph_values[i] = new int[size];
		}
		this->num_of_vertices = size;
	}

	vector <node> mst_salin();
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

vector <node> graph::mst_salin() {
	vector <node> last;
	int *set;
	bool **visited;
	set = new int[num_of_vertices];
	for (int i = 0; i < num_of_vertices; i++) {
		set[i] = i;
	}

	visited = new bool *[num_of_vertices];
	for (int i = 0; i < num_of_vertices; i++) {
		visited[i] = new bool[num_of_vertices];
	}
	for (int i = 0; i < num_of_vertices; i++) {
		for (int j = 0; j < num_of_vertices; j++) {
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < num_of_vertices; i++) {
		int min = 1000, min_index = 0;
		for (int j = 0; j < num_of_vertices; j++) {
			if (graph_values[i][j] < min) {
				min = graph_values[i][j];
				min_index = j;
			}
		}
		if (visited[i][min_index] == false) {
			node a;
			a.info = min;
			a.node_i = i;
			a.node_j = min_index;
			last.insert(last.end(), a);
			visited[i][min_index] = true;
		}
	}
	return last;
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
	vector <node> salin_result;
	salin_result = input_graph.mst_salin();

	cout << "Salin result:" << endl;
	int number_of_salin_result = salin_result.size();
	for (int i = 0, num = 1; i < number_of_salin_result; i++)
		cout << num++ << "| i=" << salin_result[i].node_i << " j=" << salin_result[i].node_j << " key=" << salin_result[i].info << endl;
	cout << '\n';
	return 0;
}