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

// void setIO(string name = "") { 	

// 	if (!name.empty()) {

// 		freopen((name + ".in").c_str(), "r", stdin);  // see Input & Output

// 		freopen((name + ".out").c_str(), "w", stdout);

// 	}

// }
int n,t;
vector<int> a;
bool f(ll x){
    ll total = 0;
    forn(n){
        total+= x / a[i];
        if(total >= t) break;//QUEEEEEEEEEEEEEEEEEEEEEEEEE????????????????? PARA NO TENER OVERFLOWS DE LONG LONG
    }
    return total >= t;
}

int main(){
    //setIO("");
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> t;
    a.resize(n);
    forn(n) cin >> a[i];
    ll l = 0, r = LLONG_MAX;

    while(l < r - 1){
        ll mid = (l + r) / 2;

        if(f(mid)){
            r = mid;
        }else{
            l = mid;
        }
    }
    cout << r;

}
/*

3 7(t products)
2 3 5

how many products in x time = p. BS X
if p==t function returns true

can you make t products or more in this time? BS for minimum time

in time = 8

m1: 8/2 = 4
m2: 8/3 = 2
m3: 8/5 = 1


sum is 
if you can do 2t products in this time => you can do t products


*/