 // _____  ______ _____            _                  _ _   _               
 // |  __ \|  ____/ ____|     /\   | |                (_) | | |              
 // | |  | | |__ | (___      /  \  | | __ _  ___  _ __ _| |_| |__  _ __ ___  
 // | |  | |  __| \___ \    / /\ \ | |/ _` |/ _ \| '__| | __| '_ \| '_ ` _ \ 
 // | |__| | |    ____) |  / ____ \| | (_| | (_) | |  | | |_| | | | | | | | |
 // |_____/|_|   |_____/  /_/    \_\_|\__, |\___/|_|  |_|\__|_| |_|_| |_| |_|
 //                                    __/ |                                 
 //                                   |___/ 

//Github Repository : https://github.com/ProAlgos/ProAlgos-Cpp

//Importing Libraries
#include<iostream>
#include<list>
#include<stack>
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

	//DFS Algorithm
	void dfs(int src);
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

//Depth First Search Algorithm
void Graph::dfs(int src)
{
	cout<<"\nDFS OF "<<src<<" Vertex is as Followed:"<<endl;

	 // Initialize All verices as Not visited 
	bool *visited = new bool[V]{0};
  
    // Create a Stack for DFS 
    stack<int> s; 
  
    // Push the source node. 
    s.push(src); 
  
    while (!s.empty()) 
    { 
        // Pop a vertex from stack and print it 
        src = s.top(); 
        s.pop(); 
        
        if (visited[src]==0) 
        { 
            cout << src << " "; 
            visited[src] = true; 
        } 
  
        //Iterate through the neighbours and if not visted then push to stack
        
        for(auto neighbour=adjlist[src].rbegin(); neighbour!=adjlist[src].rend(); neighbour++)
        {
            if (visited[*neighbour]==0) 
                s.push(*neighbour); 
   		}
   	}	 
}

int main()
{
	cout<<" ======================================================="<<endl;
	cout<<"| Depth First Search -> Graph Traversal Algorithmn      |"<<endl;
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

//DFS traversal param(source)
	g.dfs(2);

	return 0;
}   