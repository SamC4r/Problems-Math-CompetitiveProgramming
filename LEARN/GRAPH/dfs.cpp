/*
DFS = Depth First Search

*/


#include<bits/stdc++.h>
using namespace std;

int n = 5; //5 nodes
vector<bool> visited(n+1);
vector<pair<int,int>> grafito;

int counta = 0;

// void dfs_adj(int s){
//     if(visited[s]){
//         return;
//     }
//     visited[s] = true;

//     for(auto a : adjacency_list){
//         dfs_adj(a);
//     }

// }


void dfs(int s){ //With edge list
    counta++;
    if(visited[s]){
        return;
    }    
    visited[s] = true;

    for(int i = 1; i<=n;i++){
        //cout << "i " << i << " y s: " << s << " y visited[i] " << visited[i] << "\n";
        if(!visited[grafito[i].second] && grafito[i].first == s){
            printf("del %d al %d\n", grafito[i].first,grafito[i].second);
            dfs(grafito[i].second);
        }
    }

}



int main(){
    
 // --> represent book's graph
    grafito.push_back(pair<int,int>(0,0));
    grafito.push_back(pair<int,int>(1,3));
    grafito.push_back(pair<int,int>(1,2));
    grafito.push_back(pair<int,int>(5,3));
    grafito.push_back(pair<int,int>(1,5));
    grafito.push_back(pair<int,int>(2,4));

    dfs(1); //start at node 1
    cout << "Total recursive calls: " << counta << endl;

}