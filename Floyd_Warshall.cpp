/* Alogorithm implemented: Floyd Warshall.
Complexity: O(n^3)
To find the shortest path between all pairs of vertices in the graph.*/
#include<bits/stdc++.h>
using namespace std;

#define infinity 1e9
int graph[100][100];
int distance_array[100][100];

int main()
{
	//take the graph as input.

	//loop to initialise the distance array to infinity.
	for(int node_u=0;node_u<100;node_u++)
	{
		for(int node_v=0;node_v<100;node_v++)
		{
			distance_array[node_u][node_v]=infinity;
		}
	}

	// O(n^3) algorithm to find all pairs shortest path between nodes in the graph.

	for(int k=0;k<100;k++)
	{
		for(int j=0;j<100;j++)
		{
			for(int i=0;i<100;i++)
			{
				if(distance_array[i][j]>distance_array[i][k]+distance_array[k][j])
				{
					distance_array[i][j]=distance_array[i][k]+distance_array[k][j];
				}
			}
		}
	}

	//output the distance array.

	return 0;
}
