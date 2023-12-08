#include<bits/stdc++.h>

#define vi vector<int>
#define vb vector<bool>
#define endl "\n"
#define pb push_back


using namespace std;

const int N = 1001;

vector<vi> adj;
bool visited[N];

void dfs(int node){

    if(visited[node]){
        printf("%d ",node);
        return;
    }

    visited[node] = true;
    
    for(auto a : adj[node]){
        dfs(a);
    }


}

int main(){

    int n;
    scanf("%d",&n);

    adj.resize(n + 1);

    for(int i = 1; i<=n;i++){
        int a;
        scanf("%d",&a);
        adj[i].pb(a);
    }

    for(int i = 1; i<=n;i++){
        //done = false;
        memset(visited,0,sizeof(visited)); //set all values to 0
        dfs(i);
    }
}