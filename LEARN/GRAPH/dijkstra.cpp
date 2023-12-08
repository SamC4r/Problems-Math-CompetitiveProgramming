#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main(){

	//Implemented as  adjacency lists. adj[a] has pair (b,w)
	//priority_queue()
	int n = 5;
	int x = 1; //starting node
	
	vector<vector<pair<int,int>>> adj = {
		{{0,0}},
		{{5,1},{2,5}},
		{{1,5},{3,2}},
		{{2,2},{4,6}},
		{{3,6},{5,2}},
		{{1,1},{4,2}}
	};
	
	vector<int> distance(n + 1, INF);
	distance[x] = 0;
	priority_queue<pair<int,int>> q;
	q.push({0,x}); // current distance to node x = 1 is 0
	
	vector<bool> visited(n + 1);

	while(!q.empty()){
	
		int a = q.top().second;//acces next node whose distance is as minimum as possible
		q.pop();
		
		if(visited[a]) continue; //can have many instances of a node due to stdlib issues but there are other algs
					 //
		
		visited[a] = true;

		for(auto k : adj[a]){
			
			int b  = k.first, w = k.second;
			if(distance[a] + w < distance[b]){
				distance[b] = distance[a] + w;
				q.push({-distance[b], b}); // distance just used for accesing later. This improves performance
							    //

			}
		
		}

	
	}

	for(int i = 1; i<=n;i++){
		cout << "MIN DIST FROM 1 TO " << i << " IS:  " << distance[i] << endl;
	}	

}




