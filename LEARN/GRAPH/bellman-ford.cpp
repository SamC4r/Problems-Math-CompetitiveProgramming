#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main(){
	
	int n = 5; //number of nodes
	int x = 1; //starting node
	int y = 4; // finishing node..

	vector<tuple<int,int,int>> grafito = {
		{4,5,2},		
		{1,2,2},
		{1,3,1},
		{1,4,7},
		{2,4,3},
		{2,5,5},
		{3,4,3},
	};
	
	vector<int> distance(n + 1,INF);// distance from node 1 to node i. distance[2] --> stores the distance from 1 to 2	
	

	distance[x] = 0;

	for(int i = 1; i<=n - 1;i++){
		for(auto edge : grafito){//iterates trough all m edges. 
		
			int a,b,w;
			tie(a,b,w) = edge; //unpacks the tuple values to the variable names. So e.first = a, e.second = b, e.third = w; --> std::ignore if you want to skip that position
			//cout << a << " " << b << " " << w << endl;
			distance[b] = min(distance[b], distance[a] + w); //min of previous distance or the sum 
			cout << distance[b] << "\n";
		}
	}
	
	for(int i = 0; i<n;i++){
		cout << "Min from 1 to " << i+1 << " " << distance[i + 1] << "\n";
	}


}
