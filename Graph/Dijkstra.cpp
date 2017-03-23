/*
	Dijkstra Algorithm
	Finding Shortest Paths from Given Vertex to all Other Vertices.
	Time Complexity: 
	O(M log N), M is the number of edges and N is the number of vertices in a graph
	Space Complexity: O(M), M is the number of edges in a graph.
*/
#include <iostream>
#include <vector>
#include <queue>

const int INF = INT_MAX;

using namespace std;

typedef vector<vector< pair<int, int>>> Graph; 

vector<int> dijkstra(const int &start, const Graph& graph) {
    vector<int> distances(graph.size(), INF);
    distances[start] = 0;
    priority_queue<pair<int,int>> queue; // we hold vertices in queue
   
    queue.push({0, start});

    while(!queue.empty()) {
         
        int value = queue.top().second;
	    int dist = -queue.top().first;
	    queue.pop();

	    if(dist > distances[value]) continue;
        
		for(int i = 0; i < graph[value].size(); ++i) {
	     
		    int to = graph[value][i].first, dist_temp = graph[value][i].second;

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
    int vertices, edges;
    cout << "Enter the number of vertices and edges : " << endl;
    cin >> vertices >> edges;

    Graph graph;
    graph.resize(vertices + 1);

    cout << "Enter the edges in the format:" << "\n";
    cout << "a w b" << "\n";
    cout << "where \'a\' and \'b\' are vertices, and \'w\' is the distance between them." << "\n";

    for(int i = 0; i < edges; ++i) {
        int temp_start, temp_end, temp_distance;
        cin >> temp_start >> temp_distance >> temp_end;
        graph[temp_start].push_back({temp_end, temp_distance});
    }
	
    vector<int> min_distances = dijkstra(1, graph);
    
	for(int i = 2; i <= vertices; ++i)
        cout << "Distance from 1 to " << i << " is equal to : " << min_distances[i] << endl;

    return 0;
}
