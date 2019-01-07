// Author : Abdelrahman Hammam
//Github handle : AbdoHammam
#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;
vector<int> Dist; // Distance between the root and the other nodes
vector<pair<int,int> > *G;// Graph nodes , adj list and cost
void Dijkstra(int source, int N)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int> > > Q; // Min heap
    Dist.assign(N,1e9);
    Dist[source] = 0;
    Q.push({0,source});
    while(!Q.empty())
    {
        int u = Q.top().second;
        Q.pop();
        for(auto &c : G[u])
        {
            int v = c.second;
            int w = c.first;
            if(Dist[v] > Dist[u]+w)
            {
                Dist[v] = Dist[u]+w;
                Q.push({Dist[v],v});
            }
        }
    }
}
int main()
{
	int n,m; // n is the number of vertices and m is the number of edges
	int u,v,w;
	scanf("%d%d",&n,&m);
	G = new vector<pair<int,int> >[n+1];
	for(int i=0 ; i < m ; i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		G[u].PB(MP(v,w));
		G[v].PB(MP(u,w));
	}
	int src; // Tree root
	scanf("%d",&src);
	Dijkstra(src,n);
	for(int i=0 ; i < n ; i++)
		printf("%d ",Dist[i]);
}
