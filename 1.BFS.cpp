 // ____  ______ _____            _                  _ _   _               
 // |  _ \|  ____/ ____|     /\   | |                (_) | | |              
 // | |_) | |__ | (___      /  \  | | __ _  ___  _ __ _| |_| |__  _ __ ___  
 // |  _ <|  __| \___ \    / /\ \ | |/ _` |/ _ \| '__| | __| '_ \| '_ ` _ \ 
 // | |_) | |    ____) |  / ____ \| | (_| | (_) | |  | | |_| | | | | | | | |
 // |____/|_|   |_____/  /_/    \_\_|\__, |\___/|_|  |_|\__|_| |_|_| |_| |_|
 //                                   __/ |                                 
 //                                  |___/                                  

//Github Repository : https://github.com/ProAlgos/ProAlgos-Cpp

//Importing Libraries
#include<iostream>
#include<list>
#include<queue>
using namespace std;

// Graph class with adjacency list representation 
class Graph
{
	int V;
	list<int> *adjlist;

public:
	// Constructor
	Graph(int vertex);

	// Function to add An edge to Graph 
	void addEdge(int source, int destination);

	//Print Graph	
	void printList();

	//BFS Algorithm
	void bfs(int src);
};	

//Memory Allocation
Graph::Graph(int vertex)
{
	V = vertex;
	adjlist = new list<int>[V];
}

//Add Edge
void Graph::addEdge(int source, int destination)
{
	adjlist[source].push_back(destination);
	adjlist[destination].push_back(source);
}

//Print the Graph , All Vertex followed by its neighbours
void Graph::printList()
{
	cout<<"Graph Vertex and Edges: "<<endl;
	for(int node=0;node<V;node++)
	{
		cout<<node<<"->";
		for(int neighbour:adjlist[node])
			cout<<neighbour<<", ";
		cout<<endl;
	}
}

//Breadth First Search Algorithm
void Graph::bfs(int src)
{
	cout<<"\nBFS OF "<<src<<" Vertex is as Followed:"<<endl;
	
	//Initizialtion of Queue
	queue<int> q;
	bool *visted = new bool[V]{0};
	
	//push the Source node
	q.push(src);
	visted[src]=true;

	//Looping till Queue becomes empty
	while(!q.empty())
	{
		int node= q.front();
		q.pop();
		cout<<node<<" ";

		//Iterate through the neighbours
		for(int neighbour: adjlist[node])
		{
			if(visted[neighbour]==0)
			{
				q.push(neighbour);
				visted[neighbour]=true;
			}
		}
	}
	cout<<endl;	
}

int main()
{
	cout<<" ======================================================="<<endl;
	cout<<"| BreadthFirst Search -> Graph Traversal Algorithmn      |"<<endl;
	cout<<" =======================================================\n"<<endl;

	int nodes,edges,u,v;
//Creating Graph

	cin >> nodes;

	Graph g(nodes);

	cin >> edges;

//Add the Edges param(src, dest)
	
	for(int i=0; i<edges; i++)
	{
		cin >> u >> v;
		g.addEdge(u,v);
	}
	
// 0 1
// 0 4
// 1 2
// 2 4
// 2 3
// 4 3
// 5 3
	
//Print the Graph	
	g.printList();

//BFS traversal param(source)
	g.bfs(2);

	return 0;
}