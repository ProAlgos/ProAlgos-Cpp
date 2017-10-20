/*
	Depth First Search
	---------------------
	The Depth First Search or DFS Algorithm is a tree parsing algorithm with widespread applications such as 
	Strongly Connected Components Algorithm and Diameter of a Tree Algorithm.
	It is applied on a directed/undirected graph containing 'V' vertices and 'E' edges.

	Time Complexity: O(V) 		(with adjacency list, where V is the number of vertices)
	
	Space Complexity: O(V + E)		(Where V is the number of vertices and e is the number of edges)
*/
#include <iostream>
#include <vector>

using namespace std;

vector < vector < int> > graph;
vector <int> isVisited;

void dfs(int start) {
	isVisited[start] = 1;
	cout << 's' << start + 1 << " ";
	for(auto j = graph[start].begin() ; j != graph[start].end() ; j++) {
		if(!isVisited[*j]) {
			dfs(*j);
		}
	}
	cout << 'e' << start + 1 << " ";
	return;
}

int main() {
	int vertices, edges;
	cin >> vertices >> edges;
	graph.resize(vertices); isVisited.resize(vertices);
	int temp1, temp2;
	for(int i = 0 ; i < edges ; i++) {
		cin >> temp1 >> temp2; 
		temp1--; 
		temp2--;
		graph[temp1].push_back(temp2);
		graph[temp2].push_back(temp1);
	}
	for(int i = 0 ; i < vertices ; i++) {
		if(!isVisited[i]) {
			dfs(i);
		}
	}
	cout << endl;
	return 0;
}