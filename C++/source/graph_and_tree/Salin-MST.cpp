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

	vector <node> MST_Salin();
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

vector <node> graph::MST_Salin() {
	vector <node> last;
	int *set;
	bool **visited;
	set = new int[n];
	for (int i = 0; i < n; i++) {
		set[i] = i;
	}

	visited = new bool *[n];
	for (int i = 0; i < n; i++) {
		visited[i] = new bool[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++) {
		int min = 1000, minIndex = 0;
		for (int j = 0; j < n; j++) {
			if (g[i][j] < min) {
				min = g[i][j];
				minIndex = j;
			}
		}
		if (visited[i][minIndex] == false) {
			node a;
			a.info = min;
			a.nodeI = i;
			a.nodeJ = minIndex;
			last.insert(last.end(), a);
			visited[i][minIndex] = true;
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
	int n;
	cin >> n;

	graph a(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a.g[i][j];
		}
	}
	vector <node> salinResult;
	salinResult = a.MST_Salin();

	cout << "Salin result:" << endl;
	int numberOfSalinResult = kruskalResult.size();
	for (int i = 0, num = 1; i < numberOfSalinResult; i++)
		cout << num++ << "| i=" << kruskalResult[i].nodeI << " j=" << kruskalResult[i].nodeJ << " key=" << kruskalResult[i].info << endl;
	cout << '\n';
	return 0;
}