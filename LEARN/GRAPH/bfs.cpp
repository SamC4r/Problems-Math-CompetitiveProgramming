#include<bits/stdc++.h>
using namespace std;

int nodes = 6;

int main(){
	//Implementatinon:

	//Queue that contains nodes to be processed in increasing order of their distance.
	//New nodes always added to the end of the queue and the node to be processed is always at the top.

	vector<int> visited(nodes);
	vector<int> distance(nodes);
	queue<int> q;

	vector<vector<int>> adj(nodes);

	adj[1].push_back(2);
	adj[1].push_back(3);

	adj[2].push_back(4);

	adj[3].push_back(2);
	

	int x = 1; // starting node

	visited[x] = true;
	distance[x] = 0;
	

	q.push(x);

	while(!q.empty()){
		int s = q.front();
		q.pop();
		for(auto u : adj[s]){//all the nodes connected to s;

			if(visited[u])continue;
			visited[u] = true;
			distance[u] = distance[s] + 1;
			q.push(u);

		}
	}

	//distance vector just keeps track of the distances from x to i. 
	// x is the starting node. 

	// 

	//Complexity: O(n + m)


}
