
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

map<int,int> mp;
int k;
vector<int> sol;

bool valid(int x){
    sol.clear();
    int size = 0;
    
    for(auto el : mp){
        int occurrences = min(el.second / x, k - size);
        size+=occurrences;
        for(int i = 0; i<occurrences;i++){
            sol.push_back(el.first);
        }
    }

    return size == k;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n >> k;

    vector<int> a(n);
    
    for(int i = 0; i<n;i++){
        cin >> a[i];
        mp[a[i]]++;
    }

    int l = 1, r = n;
// Bs for max repetitionss of any subsequence
    // We generate the susbequence later
    while(l <= r){
        
        int x = (l + r) / 2;
        // debug(l,r,x,valid(x));
        if(valid(x)){
            l = x + 1;
        }else{
            r = x - 1;
        }
    }

    valid(r); 
        
    for(auto el : sol) cout << el << ' ';
    // cout << r << endl;
}


