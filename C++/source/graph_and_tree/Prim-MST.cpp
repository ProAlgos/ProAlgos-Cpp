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
	int info, nodeI, nodeJ;
};

class graph {
private:
	int n;			//number of vertex
	void link(int x, int y, int *p, int *r);
	int findSet(int x, int *p);
public:
	int **g;		//the 2d array for graph
	graph(int n) {
		g = new int *[n];
		for (int i = 0; i<n; i++) {
			g[i] = new int[n];
		}
		this->n = n;
	}

	int * MST_Prim(int start);
protected:
};

int graph::findSet(int x, int *p) {
	if (x != p[x]) {
		p[x] = findSet(p[x], p);
	}
	return p[x];
}

void graph::link(int x, int y, int *p, int *r) {
	if (r[x]>r[y]) {
		p[y] = x;
	} else {
		p[x] = y;
	}
	if (r[x] == r[y]) {
		r[y] = (r[y]) + 1;
	}
}

int * graph::MST_Prim(int start) {
	//Start begin with 0 to N
	int *key, *p;
	bool *visited;
	p = new int[n];
	p[start] = 1000;
	key = new int[n];

	visited = new bool[n];
	for (int i = 0; i<n; i++) {
		visited[i] = false;
	}
	key[start] = 0;
	for (int i = 1; i<n; i++) {
		key[i] = 1000;
	}

	while (1) {
		bool queueEmpty = true;
		for (int i = 0; i<n; i++) {
			if (visited[i] == false)
				queueEmpty = false;
		}
		if (queueEmpty) {
			//Find parent with p and index of p
			break;
		} else {
			//Find Minimun number that is not visited
			int min = 1000, minIndex = 0;
			for (int i = 0; i<n; i++) {
				if (key[i] <= min && visited[i] == false) {
					min = key[i];
					minIndex = i;
				}
			}
			visited[minIndex] = true;

			for (int i = 0; i<n; i++) {
				if (g[minIndex][i] != 1000 && visited[i] == false) {
					if (g[minIndex][i] < key[i]) {
						p[i] = minIndex;
						key[i] = g[minIndex][i];
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
	int n;
	cin >> n;

	graph a(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a.g[i][j];
		}
	}
	int *primResult;
	primResult = a.MST_Prim(0);

	cout << "Prim result:" << endl;
	for (int i = 0, num = 1; i < n; i++)
		if (primResult[i] != 1000)
			cout << num++ << "| i=" << primResult[i] << " j=" << i << " key=" << a.g[i][primResult[i]] << endl;
	cout << '\n';
	return 0;
}