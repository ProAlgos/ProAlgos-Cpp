 //  ______ _                 _  __          __            _           _ _ 
 // |  ____| |               | | \ \        / /           | |         | | |
 // | |__  | | ___  _   _  __| |  \ \  /\  / /_ _ _ __ ___| |__   __ _| | |
 // |  __| | |/ _ \| | | |/ _` |   \ \/  \/ / _` | '__/ __| '_ \ / _` | | |
 // | |    | | (_) | |_| | (_| |    \  /\  / (_| | |  \__ \ | | | (_| | | |
 // |_|    |_|\___/ \__, |\__,_|     \/  \/ \__,_|_|  |___/_| |_|\__,_|_|_|
 //                  __/ |                                                 
 //                 |___/                                                  

// C++ Program for Floyd Warshall Algorithm 
#include<iostream>
using namespace std; 

// Number of vertices in the graph 
#define V 4 

/* Define Infinite as a large enough 
value.This value will be used for 
vertices not connected to each other */
#define INF 99999 

// A function to print the solution matrix 
void printSolution(int dist[][V]) 
{ 
	cout<<"The following matrix shows the shortest distances"
			" between every pair of vertices \n"; 
	for (int i = 0; i < V; i++) 
	{ 
		for (int j = 0; j < V; j++) 
		{ 
			if (dist[i][j] == INF) 
				cout<<"INF"<<"	 "; 
			else
				cout<<dist[i][j]<<"	 "; 
		} 
		cout<<endl; 
	} 
} 

// Solves the all-pairs shortest path 
void floydWarshall (int graph[][V]) 
{ 
	/* dist[][] will be the output matrix 
	that will finally have the shortest 
	distances between every pair of vertices */
	int dist[V][V], i, j, k; 

	/* Initialize the solution matrix same 
	as input graph matrix. Or we can say 
	the initial values of shortest distances 
	are based on shortest paths considering 
	no intermediate vertex. */
	for (i = 0; i < V; i++) 
		for (j = 0; j < V; j++) 
			dist[i][j] = graph[i][j]; 

	/* Add all vertices one by one to 
	the set of intermediate vertices. 
	---> Before start of an iteration, 
	we have shortest distances between all 
	pairs of vertices such that the 
	shortest distances consider only the 
	vertices in set {0, 1, 2, .. k-1} as 
	intermediate vertices. 
	----> After the end of an iteration, 
	vertex no. k is added to the set of 
	intermediate vertices and the set becomes {0, 1, 2, .. k} */
	for (k = 0; k < V; k++) 
	{ 
		// Pick all vertices as source one by one 
		for (i = 0; i < V; i++) 
		{ 
			// Pick all vertices as destination for the 
			// above picked source 
			for (j = 0; j < V; j++) 
			{ 
				// If vertex k is on the shortest path from 
				// i to j, then update the value of dist[i][j] 
				if (dist[i][k] + dist[k][j] < dist[i][j]) 
					dist[i][j] = dist[i][k] + dist[k][j]; 
			} 
		} 
	}

	for(i = 0; i < V; i++)
	{
		if(dist[i][i]<0)
		{
			printf("Graph contains negative weight cycle"); 
			return; // If negative cycle is detected, simply return 
		}
	}
 
	// Print the shortest distance matrix 
	printSolution(dist); 
} 



// Driver code 
int main() 
{ 
/* 
Let us create the following weighted graph
Graphical Represesntaion: 
   		10 
	(0)------->(3) 
	 |	     /|\ 
   5 |	      | 
     |	      | 1 
	\|/	      | 
	(1)------->(2) 
		  3	
 */
	int graph[V][V] = { {0, 5, INF, 10}, 
						{INF, 0, 3, INF}, 
						{INF, INF, 0, 1}, 
						{INF, INF, INF, 0} 
					}; 

	// Print the solution 
	floydWarshall(graph); 
	return 0; 
} 
