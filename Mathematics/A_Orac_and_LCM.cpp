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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b,a % b);
}

int main(){
    //setIO("");
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<ll> a(n);
    for(int i = 0; i<n;i++){
        cin >> a[i];
    }
    vector<ll> gcds = {a[n-1]};

    for(int i=n - 2; i>=0;i--){
        gcds.push_back(gcd(gcds.back(),a[i]));
    }
   // debug(gcds);
    vector<ll> g(n-1);
    for(int i = 0; i<n-1;i++){
        g[i] = a[i] * gcds[n -i-2];
        g[i]/=gcds[n-i-1];
    }
    //debug(g);
    ll sol = g[0];
    for(int i = 1; i<g.size();i++){
        sol = gcd(sol,g[i]);
      //  cout << sol << " ";
    }
    cout << sol;



}
