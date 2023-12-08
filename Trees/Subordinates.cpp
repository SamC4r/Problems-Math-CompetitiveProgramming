#include<bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define forn(n) for(int i=0;i<int(n);i++)
#define endl "\n"



using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

//For debugging
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


int n;
vector<int> subordinates;
vector<vector<int>> adj;

void dfs(int node, int parent){
    // debug(node,parent);
    for(int no : adj[node]){
        if(no == parent) continue;
        dfs(no,node);
        subordinates[node - 1] += subordinates[no - 1] + 1;
    }
}

int main(){
    //setIO("");
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    subordinates.resize(n);
    adj.resize(n + 1);

    forn(n - 1){
        int x;
        cin >> x;
        adj[i + 2].push_back(x);
        adj[x].push_back(i+2);
    }
    // debug(adj);

    dfs(1,-1);

    for(auto s : subordinates) cout << s << " ";

    
}
