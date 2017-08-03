/*

	Dijkstra algorithm using adjacency list representation of graph
	
	-----------

	Used for finding shortest path in a graph from one vertex to all other vertex
	
	Time complexity 
	-----------
	O(n + m)

	Space complexity 
	-----------
	O(n^2)

*/

#include<iostream>
#include<utility>
#include<vector>
#include<set>
#include<climits>
using namespace std;

#define MAX 10001

vector < pair <int,int> > adj[MAX];
bool visited[MAX];
int dist[MAX];

void initialise (int total_vertex) {
	for (int i=0;i<=total_vertex;i++) {
		dist[i] = INT_MAX;
		visited[i] = 0;
	}
}

void dijkstra (int start) {
	dist[start] = 0;
	multiset < pair <int,int> > s;
	s.insert(make_pair(0,start));

	while (!s.empty()) {

		pair <int,int> p = *s.begin();
		s.erase(s.begin());
		int x = p.second;
		if (visited[x]) 
			continue;
		visited[x] = 1;
		for (int i=0;i<adj[x].size();i++) {
			int y = adj[x][i].first;
			if (dist[x] + y < dist[adj[x][i].second]) {
				dist[adj[x][i].second] = dist[x] + y;
				s.insert(make_pair(dist[adj[x][i].second],adj[x][i].second));
			}
		}

	}
}

int main () {
	int no_of_vertex,no_of_edges,source;
	cout<<"Enter no. of vertex and edges in graph ";
	cin>>no_of_vertex>>no_of_edges;
	initialise(no_of_vertex);
	cout<<"Enter edges and cost associated with that edge\n";
	while (no_of_edges--) {
		int vertex1,vertex2,cost;
		cin>>vertex1>>vertex2>>cost;
		adj[vertex1].push_back(make_pair(cost,vertex2));
		adj[vertex2].push_back(make_pair(cost,vertex1));
	}
	cout<<"Enter source vertex\n";
	cin>>source;
	dijkstra(source);
	cout<<"Minimum distence from source vertex to all other vertex is \n";
	for (int i=1;i<=no_of_vertex;i++) {
		cout<<dist[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
