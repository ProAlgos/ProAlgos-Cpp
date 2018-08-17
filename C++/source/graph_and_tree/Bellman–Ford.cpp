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
	int n;									//number of vertex
	int *vertex;							//distance array

	stack <int> wayPath;
	int *path;								//parents array
	bool *pathCheck;						//check parents usage array
	int minimun(int num);					//relax function
	void parent(int child, int *edgeSum);	//find nagative cycle
public:
	int **g;	//the 2d array for graph
	graph(int n) {
		vertex = new int[n];
		path = new int[n];
		pathCheck = new bool[n];
		g = new int *[n];
		for (int i = 0; i < n; i++) {
			g[i] = new int[n];
		}

		this->n = n;
	}

	bool bellmanford();
protected:
};

int graph::minimun(int num){
	for (int k = 0; k < n; k++) {
		if (vertex[num] > (g[k][num] + vertex[k])) {
			vertex[num] = g[k][num] + vertex[k];
			path[num] = k;
		}
	}
	return vertex[num];
}

bool graph::bellmanford() {
	int *tempV;
	tempV = new int[n];

	vertex[0] = 0;
	for (int i = 1; i < n; i++) {
		vertex[i] = 1000;

	}
	for (int i = 0; i < n; i++) {
		path[i] = 1000;
		pathCheck[i] = false;
	}

	bool findWay = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tempV[j] = vertex[j];
			vertex[j] = minimun(j);
			if (i == n - 1 && vertex[j] != tempV[j]) {
				//In FALSE mode
				vertex[j] = tempV[j];
				findWay = true;
			}
		}
		//print the vertex matrix
		for (int i = 0; i < n; i++) {
			cout << setw(5) << vertex[i];
		}
		cout << endl;
	}
	if (findWay) {
		//print path matrix
		cout << endl << endl << "Parents: ";
		for (int i = 0; i < n; i++) {
			cout << setiosflags(ios::left) << setw(5) << path[i];
		}

		//In FALSE mode
		int *num;
		num = new int;
		for (int i = 0; i < n; i++) {
			(*num) = 0;
			parent(i, num);
			if ((*num) >= 0) {
				for (int j = 0; j < n; j++) {
					pathCheck[j] = false;
				}
			}
			else {
				break;
			}
		}
	} else {
		//In TURE mode
		cout << "\n\nDistances: ";
		for (int i = 0; i < n; i++) {
			cout << vertex[i] << " ";
		}
		return true;
	}
}

void graph::parent(int child, int *edgeSum) {
	//if print==true: cout<<cycle
	pathCheck[child] = true;
	if (pathCheck[path[child]] == false) {
		wayPath.push(child);
		(*edgeSum) += g[path[child]][child];
		parent(path[child], edgeSum);
	} else {
		wayPath.push(child);
		if (path[child] != 1000) {
			(*edgeSum) += g[path[child]][child];
		}

		if ((*edgeSum) <0) {
			int num;
			cout << "\nNegative cycle: ";
			while (!wayPath.empty()) {
				num = wayPath.top();
				cout << num << " ";
				wayPath.pop();
			}
		} else {
			while (!wayPath.empty()) {
				wayPath.pop();
			}
		}
	}
}

int main() {
	int n;
	cin >> n;

	graph a(n);
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			cin >> a.g[i][j];
		}
	}
	cout << "\nCalculation:\n";
	a.bellmanford();
	cin.get();
	return 0;
}