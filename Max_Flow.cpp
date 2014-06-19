/* alogorithm used :- Edmunds Karp algorithm, that is modified version of Ford Fulkerson using a bfs to find the augmenting path.*/


#include<bits/stdc++.h>
#define MAX 500 // the maximum number of vertices in the graph;
using namespace std;

int graph[MAX][MAX];//adjacency matrix to store the graph.
int residual_graph[MAX][MAX];//residual graph to ensure we can undo or backtrack.
int vis[MAX];// visited array to keep track of the visisted nodes.
int parent[MAX];//parent array to keep track of the augmenting path found at each step.
int source,sink;

//function to check if an augmenting path exists using bfs and if it does to form the parent array that can track the augmenting path.
bool bfs()
{
	memset(vis,0,sizeof(vis));//clear the visited array.

	queue<int> q;
	q.push(source);//push the source into the queue.
	parent[source]=-1;//the parent of the source is initialised to -1;

	//loop to find the shortest augmenting path present in the current residual graph. It breaks if the path is found returning true.
	while(!q.empty())
	{
		int node_u=q.front();
		q.pop();

		//loop to check over the adjacent edges in the graph.
		for(int node_v=0; node_v < MAX; node_v++)
		{
			//if the node is not visited so far and the edge value/current capacity is positive then we add it to the queue.
			if(!vis[node_v] and residual_graph[node_u][node_v]>0)
			{
				vis[node_v]=1;
				q.push(node_v);
				parent[node_v]=node_u;
			}
		}

		if(vis[sink]==1)
			return true;
	}
	return false;
}

//function to find the maximum possible flow in the graph.
void flow()
{
	int max_flow=0;//contains the maximum flow from source to sink in the graph.

	//loop to initialise the residual graph with the original graph.
	for(int node_u=0; node_u < MAX; node_u++)
		for(int node_v=0; node_v < MAX; node_v++)
			residual_graph[node_u][node_v]=graph[node_u][node_v];

	//loop to add upp the flows found in the various augmenting paths.
	while(bfs())
	{
		int path_flow=0;//contains the maximum possible flow in that particular path.

		/*loop to backtrack the path from the sink to source using the parent array,
		 found through bfs to get the maximum possible flow in that path.*/
		for(int node_v=sink; node_v!=source ; node_v=parent[node_v])
		{
			int node_u=parent[node_v];
			path_flow=min(path_flow,residual_graph[node_u][node_v]);
		}

		//loop to make the changes in the edges of the residual graph.
		for(int node_v=sink; node_v!=source; node_v=parent[node_v])
		{
			int node_u=parent[node_v];
			residual_graph[node_u][node_v]-=path_flow;
			residual_graph[node_v][node_u]+=path_flow;
		}

		max_flow+=path_flow;//adds the maximum possible flow through that particular augmenting path to the max_flow of the graph;
	}

	cout<<max_flow<<"\n";// outputs the maximum flow in the graph.
}



int main()
{
	//take graph input.
	flow();
	return 0;
}
