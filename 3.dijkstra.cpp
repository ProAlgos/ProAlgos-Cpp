 //  _____  _ _ _        _                         _                  _ _   _               
 // |  __ \(_|_) |      | |                  /\   | |                (_) | | |              
 // | |  | |_ _| | _____| |_ _ __ __ _      /  \  | | __ _  ___  _ __ _| |_| |__  _ __ ___  
 // | |  | | | | |/ / __| __| '__/ _` |    / /\ \ | |/ _` |/ _ \| '__| | __| '_ \| '_ ` _ \ 
 // | |__| | | |   <\__ \ |_| | | (_| |   / ____ \| | (_| | (_) | |  | | |_| | | | | | | | |
 // |_____/|_| |_|\_\___/\__|_|  \__,_|  /_/    \_\_|\__, |\___/|_|  |_|\__|_| |_|_| |_| |_|
 //         _/ |                                      __/ |                                 
 //        |__/                                      |___/                                  

//Github Repository : https://github.com/ProAlgos/ProAlgos-Cpp

//Importing Libraries
#include<iostream>
#include<list> 	 
#include<vector>
#include<queue>
#include<limits>
using namespace std; 

//Abbreviation for Pair
typedef pair<int, int> pp; 

// Graph class with adjacency list representation 
class Graph 
{ 
	int V;
	list<pp> *adj; 

public: 
	// Constructor
	Graph(int Vertex);  

	// Function to add An edge to Graph 
	void addEdge(int src, int dest, int weight); 

	// Function of Shortest path from source using Dijkstra Algorithmn 
	void dijkstra_shortest_path(int src); 
}; 

//Memory Allocation
Graph::Graph(int Vertex) 
{ 
	V = Vertex; 
	adj = new list<pp> [V]; 
} 

//Add Edge
void Graph::addEdge(int src, int dest, int weight) 
{ 
	adj[src].push_back(make_pair(dest, weight));
	adj[dest].push_back(make_pair(src, weight)); 
} 
// Dijkstra Algorithmn
void Graph::dijkstra_shortest_path(int src) 
{ 
	
	priority_queue< pp, vector <pp> , greater<pp> > pq; 

	// Create a distance vector and initialize all distances as infinite[INT_MAX] 
	vector<int> distance(V, INT_MAX); 

	// Insert source in priority queue and initialize distance as 0. 
	pq.push(make_pair(0, src)); 
	distance[src] = 0; 

	/* Looping till priority queue becomes empty */
	while (!pq.empty()) 
	{ 
		
		int node = pq.top().second; 
		pq.pop(); 

		for (pp neighbour : adj[node]) 
		{ 
			// Get vertex and weight of current adjacent 
			int vertex = neighbour.first; 
			int weight = neighbour.second; 

			// Relaxing of Edge 
			if (distance[vertex] > distance[node] + weight) 
			{ 
				// Updating distance of Vertex 
				distance[vertex] = distance[node] + weight; 
				pq.push(make_pair(distance[vertex], vertex)); 
			} 
		} 
	} 

	// Printing Shortest distances from Source 
	cout<<"Shortest Distance from Source Node: "<<src<<endl; 
	for (int vertex = 0; vertex < V; vertex++) 
		cout<<src<<"->"<<vertex<<": "<<distance[vertex]<<endl; 
} 

// Main to Run Graph Algorithmns
int main() 
{ 
	cout<<" ======================================================="<<endl;
	cout<<"| Dijkstra Algorithmn - Shortest Path in Graph          |"<<endl;
	cout<<" =======================================================\n"<<endl;

	// Creation of the graph with V vertex 
	int V = 9; 
	Graph g(V); 

	// Adding Edges 
	g.addEdge(0, 1, 4); 
	g.addEdge(0, 7, 8); 
	g.addEdge(1, 2, 8); 
	g.addEdge(1, 7, 11); 
	g.addEdge(2, 3, 7); 
	g.addEdge(2, 8, 2); 
	g.addEdge(2, 5, 4); 
	g.addEdge(3, 4, 9); 
	g.addEdge(3, 5, 14); 
	g.addEdge(4, 5, 10); 
	g.addEdge(5, 6, 2); 
	g.addEdge(6, 7, 1); 
	g.addEdge(6, 8, 6); 
	g.addEdge(7, 8, 7); 

	g.dijkstra_shortest_path(0); 

	return 0; 
} 
