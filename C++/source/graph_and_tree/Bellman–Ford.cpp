/*
	Bellman–Ford
	----------------------
	The Bellman–Ford algorithm is an algorithm that computes shortest paths
	from a single source vertex to all of the other vertices in a weighted digraph.
	Given a graph and a source vertex src in graph, find shortest paths from src to
	all vertices in the given graph. The graph may contain negative weight edges.
 	Time complexity
	---------------
	O(VE), where V is the number of vertices and E is number of edges.
 	Space complexity
	----------------
	O(V + E), where V is the number of vertices and E is number of edges.
*/

 #include <iostream>
#include <fstream>
#include <stack>
#include <iomanip>

 using namespace std;

 class graph {
private:
	int num_of_vertices;					//number of vertices
	int *vertex;							//distance array
 	stack <int> way_path;
	int *path;								//parents array
	bool *path_check;						//check parents usage array
	int minimun(int num);					//relax function
	void parent(int child, int *edge_sum);	//find nagative cycle
public:
	int **graph_values;	//the 2d array for graph
	graph(int size) {
		vertex = new int[size];
		path = new int[size];
		path_check = new bool[size];
		graph_values = new int *[size];
		for (int i = 0; i < size; i++) {
			graph_values[i] = new int[size];
		}
 		this->num_of_vertices = size;
	}
 	bool bellmanford();
protected:
};
 int graph::minimun(int num){
	for (int k = 0; k < num_of_vertices; k++) {
		if (vertex[num] > (graph_values[k][num] + vertex[k])) {
			vertex[num] = graph_values[k][num] + vertex[k];
			path[num] = k;
		}
	}
	return vertex[num];
}
 bool graph::bellmanford() {
	int *temp_ver;
	temp_ver = new int[num_of_vertices];
 	vertex[0] = 0;
	for (int i = 1; i < num_of_vertices; i++) {
		vertex[i] = 1000;
 	}
	for (int i = 0; i < num_of_vertices; i++) {
		path[i] = 1000;
		path_check[i] = false;
	}
 	bool find_way = false;
	for (int i = 0; i < num_of_vertices; i++) {
		for (int j = 0; j < num_of_vertices; j++) {
			temp_ver[j] = vertex[j];
			vertex[j] = minimun(j);
			if (i == num_of_vertices - 1 && vertex[j] != temp_ver[j]) {
				//In FALSE mode
				vertex[j] = temp_ver[j];
				find_way = true;
			}
		}
		//print the vertex matrix
		for (int i = 0; i < num_of_vertices; i++) {
			cout << setw(5) << vertex[i];
		}
		cout << endl;
	}
	if (find_way) {
		//print path matrix
		cout << endl << endl << "Parents: ";
		for (int i = 0; i < num_of_vertices; i++) {
			cout << setiosflags(ios::left) << setw(5) << path[i];
		}
 		//In FALSE mode
		int *num;
		num = new int;
		for (int i = 0; i < num_of_vertices; i++) {
			(*num) = 0;
			parent(i, num);
			if ((*num) >= 0) {
				for (int j = 0; j < num_of_vertices; j++) {
					path_check[j] = false;
				}
			}
			else {
				break;
			}
		}
	} else {
		//In TURE mode
		cout << "\n\nDistances: ";
		for (int i = 0; i < num_of_vertices; i++) {
			cout << vertex[i] << " ";
		}
		return true;
	}
}
 void graph::parent(int child, int *edge_sum) {
	//if print==true: cout<<cycle
	path_check[child] = true;
	if (path_check[path[child]] == false) {
		way_path.push(child);
		(*edge_sum) += graph_values[path[child]][child];
		parent(path[child], edge_sum);
	} else {
		way_path.push(child);
		if (path[child] != 1000) {
			(*edge_sum) += graph_values[path[child]][child];
		}
 		if ((*edge_sum) <0) {
			int num;
			cout << "\nNegative cycle: ";
			while (!way_path.empty()) {
				num = way_path.top();
				cout << num << " ";
				way_path.pop();
			}
		} else {
			while (!way_path.empty()) {
				way_path.pop();
			}
		}
	}
}
 int main() {
	int size;
	cin >> size;
 	graph g(size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> g.graph_values[i][j];
		}
	}
	cout << "\nCalculation:\n";
	g.bellmanford();
	cin.get();
	return 0;
} 