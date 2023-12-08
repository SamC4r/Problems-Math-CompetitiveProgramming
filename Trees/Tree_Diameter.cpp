/*
Start at any node and do dfs. Calculate position of the most distant leaf.
Then from that leaf do another dfs and the solution is the most distant leaf
from it. In essence, the most distant leaf from the most distant leaf from 
an arbitrary node. :)
*/
#include<bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define forn(n) for(int i=0;i<int(n);i++)
#define endl "\n"

using namespace std;

vector<vector<int>> adj;
vector<int> distances;
vector<int> distances2;



void dfs1(int node, int parent){
    for(auto no : adj[node]){
        if(no == parent) continue;
        distances[no] = distances[node] + 1;
        dfs1(no,node);
    }
}

void dfs2(int node, int parent){
    for(auto no : adj[node]){
        if(no == parent) continue;
        distances2[no] = distances2[node] + 1;
        dfs2(no,node);
    }
}


int main(){
    //setIO("");
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    adj.resize(n + 1);
    distances2.resize(n + 1);
    distances.resize(n + 1);

    for(int i = 1; i<n;i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    //Tree, not forest => can start at any node

    dfs1(1,-1);
    
    auto max_pos = max_element(all(distances));
    dfs2(max_pos - distances.begin(),-1);

    int c = *max_element(all(distances2));
    cout << c;



}
