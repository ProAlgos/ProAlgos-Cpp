/*
    Dinic MaxFlow Algorithm
    --------------------
    Given a graph which represents a flow network where every edge has a capacity. 
	Also given two vertices source ‘s’ and sink ‘t’ in the graph, 
	find the maximum possible flow from s to t with following constraints :
    	1. Flow on an edge doesn’t exceed the given capacity of the edge.
    	2. Incoming flow is equal to outgoing flow for every vertex except s and t

    Time complexity
    ---------------
    O(EV^2), where E is the number of Edges and V is the number of nodes.

    Space complexity
    ----------------
    O(E + V), the variables same as time complexity.

    Author
    ------
    Abdelrahman Tarek (@fuboki10)
*/

#ifndef DINIC_MAXFLOW_HPP
#define DINIC_MAXFLOW_HPP


#include <vector>
#include <queue>


struct Edge {
	int u, v;
	long long cap, flow;
	Edge() {}
	Edge(int u, int v, long long cap) : u(u), v(v), cap(cap), flow(0) {}
};

struct Dinic {
	int N;
	std::vector<Edge> E;
	std::vector<std::vector<int>> g;
	std::vector<int> d, pt;

	Dinic(int N) : N(N), E(0), g(N), d(N), pt(N) {}

	void AddEdge(int u, int v, long long cap) {
		if (u != v) {
			E.emplace_back(Edge(u, v, cap));
			g[u].emplace_back(E.size() - 1);
			E.emplace_back(Edge(v, u, 0));
			g[v].emplace_back(E.size() - 1);
		}
	}

	bool BFS(int S, int T) {
		std::queue<int> q({ S });
		fill(d.begin(), d.end(), N + 1);
		d[S] = 0;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			if (u == T) break;
			for (int k : g[u]) {
				Edge &e = E[k];
				if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
					d[e.v] = d[e.u] + 1;
					q.emplace(e.v);
				}
			}
		}
		return d[T] != N + 1;
	}

	long long DFS(int u, int T, long long flow = -1) {
		if (u == T || flow == 0) return flow;
		for (int &i = pt[u]; i < g[u].size(); ++i) {
			Edge &e = E[g[u][i]];
			Edge &oe = E[g[u][i] ^ 1];
			if (d[e.v] == d[e.u] + 1) {
				long long amt = e.cap - e.flow;
				if (flow != -1 && amt > flow) amt = flow;
				if (long long pushed = DFS(e.v, T, amt)) {
					e.flow += pushed;
					oe.flow -= pushed;
					return pushed;
				}
			}
		}
		return 0;
	}

	long long MaxFlow(int S, int T) {
		long long total = 0;
		while (BFS(S, T)) {
			fill(pt.begin(), pt.end(), 0);
			while (long long flow = DFS(S, T))
				total += flow;
		}
		return total;
	}
};


#endif // DINIC_MAXFLOW_HPP