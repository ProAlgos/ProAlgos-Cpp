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

	vector <node> MST_Kruskal();
protected:
};

vector <node> graph::MST_Kruskal() {
	vector <node> last;
	int *p, *r;
	p = new int[n];
	r = new int[n];
	for (int i = 0; i<n; i++) {
		p[i] = i;
		r[i] = 0;
	}
	//the 2d array for graph visted
	bool **gVisted;
	gVisted = new bool *[n];
	for (int i = 0; i<n; i++) {
		gVisted[i] = new bool[n];
	}
	//Initialize gVisted with 0 number
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			gVisted[i][j] = false;
		}
	}
	//queue for min values
	queue <node> edges;
	for (int k = 0; k<n*n; k++) {
		int min = 1000, minI = 0, minJ = 0;
		//Find min value
		for (int i = 0; i<n; i++) {
			for (int j = i; j<n; j++) {
				if (g[i][j]<min && gVisted[i][j] == false) {
					min = g[i][j];
					minI = i;
					minJ = j;
				}
			}
		}
		//
		if (min != 1000) {
			node a;
			a.info = min;
			a.nodeI = minI;
			a.nodeJ = minJ;
			edges.push(a);
			gVisted[minI][minJ] = true;
		}
	}

	int edgeNum = edges.size();
	for (int i = 0; i<edgeNum; i++) {
		int v = edges.front().nodeI, u = edges.front().nodeJ, key = edges.front().info;
		if (findSet(u, p) != findSet(v, p)) {
			//A<-A U {u,v}
			node a;
			a.nodeI = v;
			a.nodeJ = u;
			a.info = key;
			last.insert(last.end(), a);
			
			link(findSet(u, p), findSet(v, p), p, r);
		}
		edges.pop();
	}
	return last;
}

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
	vector <node> kruskalResult;
	kruskalResult = a.MST_Kruskal();
	
	cout << "Kruskal result:" << endl;
	int numberOfKruResult = kruskalResult.size();
	for (int i = 0, num = 1; i < numberOfKruResult; i++)
		cout << num++ << "| i=" << kruskalResult[i].nodeI << " j=" << kruskalResult[i].nodeJ << " key=" << kruskalResult[i].info << endl;
	cout << '\n';
	return 0;
}