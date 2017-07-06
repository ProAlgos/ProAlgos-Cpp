//Dijkstra algorithm using adjacency list representation of graph
// used for finding shortest path in a graph from one vertex to all other vertex
//Time complexity O(n + m)
//space complexity O()

#include<bits/stdc++.h>
using namespace std;

#define MAX 10001

vector < pair <int,int> > adj[MAX];
bool visited[MAX];
int dist[MAX];

void initialise (int n) {

	for (int i=0;i<=n;i++) {
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

	int n,m,s;
	cout<<"Enter no. of vertex and edges in graph ";
	cin>>n>>m;
	initialise(n);
	cout<<"Enter edges \n";
	while (m--) {
		int a,b,c;
		cin>>a>>b>>c;
		adj[a].push_back(make_pair(c,b));
		adj[b].push_back(make_pair(c,a));
	}
	cout<<"Enter source vertex\n";
	cin>>s;
	dijkstra(s);
	cout<<"Minimum distence from source vertex to all other vertex is \n";
	for (int i=1;i<=n;i++) {
		cout<<dist[i]<<" ";
	}
	cout<<"\n";

}
