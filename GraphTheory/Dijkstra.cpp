#include <iostream>
#include <vector>
#include <queue>

using namespace std;


vector<vector< pair<int, int>>> g; // global graph
int vertices, edges;

vector<int> dijkstra(const int &start) {
    const int INF = 1000000; // initially all distances are equal infinity
	vector<int> distances(g.size(), INF);
	distances[start] = 0;
	priority_queue<pair<int,int>> queue; // we hold vertices in queue
	queue.push({0, start});

	while(!queue.empty()) {
		int value = queue.top().second;
		int dist = -queue.top().first;
		queue.pop();

		if(dist > distances[value]) continue;
		for(int i = 0; i < g[value].size(); ++i) {
			int to = g[value][i].first, dist_temp = g[value][i].second;
			if(distances[value] + dist_temp < distances[to]) {
				distances[to] = distances[value] + dist_temp;
				queue.push({-distances[to], to});
			}
		}
	}
	return distances;
}

int main() {
	ios_base::sync_with_stdio(0);
	cout << "Enter the number of vertices and edges : " << endl;
	cin >> vertices >> edges;

	g.resize(vertices + 1);

	cout << "Now enter your edges format: \"u v w\". Where u and w are vertices and w is the distance between them." << endl;
	for(int i = 0; i < edges; ++i) {
		int temp_start, temp_end, temp_distance;
		cin >> temp_start >> temp_end >> temp_distance;
		g[temp_start].push_back({temp_end, temp_distance});
	}

	vector<int> d = dijkstra(1);
	//cout << "Distances from the first vertix to the rest : " << endl;
    for(int i = 2; i <= vertices; ++i)
        cout << "Distance from 1 to " << i << " is equal to : " << d[i] << endl;

}
