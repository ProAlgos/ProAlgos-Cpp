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

void dijkstra (vector <pair <int,int> > adj[],vector <bool> &visited,vector <int> &dist,int start) {
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
	int num_vertex,num_edges,source;
	cout<<"Enter no. of vertex and edges in graph ";
	cin>>num_vertex>>num_edges;
	vector < pair <int,int> > adj[num_vertex+1];
	vector <bool> visited (num_vertex+1,0);
	vector <int> dist (num_vertex+1,INT_MAX);
	cout<<"Enter edges and cost associated with that edge\n";
	while (num_edges--) {
		int vertex1,vertex2,cost;
		cin>>vertex1>>vertex2>>cost;
		adj[vertex1].push_back(make_pair(cost,vertex2));
		adj[vertex2].push_back(make_pair(cost,vertex1));
	}
	cout<<"Enter source vertex\n";
	cin>>source;
	dijkstra(adj,visited,dist,source);
	cout<<"Minimum distence from source vertex to all other vertex is \n";
	for (int i=1;i<=num_vertex;i++) {
		cout<<dist[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
