#include<bits/stdc++.h>
 
#define all(x) (x).begin(), (x).end()
#define forn(n) for(int i=0;i<int(n);i++)
#define endl "\n"
 
 
 
using namespace std;
 
typedef long long ll;
 
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
 
 
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int x,n; cin >> x >> n;
    set<int> street;
    street.insert(0); street.insert(x);
    int ans = 0;
    multiset<int> lengths;
    lengths.insert(x);
    forn(n){
        int t; cin >> t;
 
        auto it1 = street.lower_bound(t);
        auto it2 = it1;
        it2--;
        int dr =abs(t - *it1);
        int dl = abs(t - *it2);
 
 
        lengths.erase(lengths.find(*it1 - *it2));
        lengths.insert(dr);
        lengths.insert(dl);
        ans = *--lengths.end();
        cout << ans << " ";
 
        street.insert(t);
 
    }
}
/**
 * 
 * 
 * 0##3##6#8
 * 
 * 
 * 
 * 
*/