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

void setIO(string name = "") { 	

	if (!name.empty()) {

		freopen((name + ".in").c_str(), "r", stdin);  // see Input & Output

		freopen((name + ".out").c_str(), "w", stdout);

	}

}

int n,k;
vector<int> a;

bool f(ll x){
    
    int op = 0;
    ll s = 0;

    forn(n){
        if(a[i] > x) return false;
        if(s + a[i] > x){
            ++op;
            s = 0;
        }
        s += a[i];
    }
    if(s > 0) op++;
    return op <= k;


}

int main(){
    //setIO("");
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    
    cin >> n >> k;
    
    a.resize(n);
    forn(n) cin >> a[i];
    
    ll l = *max_element(all(a)), r = 1e15 + 1;

    while(l < r - 1){
    
        //ebug(l,r);
        ll mid = (r + l) / 2;

        if(f(mid)){
            r = mid;
        }else{
            l = mid;
        }

        //debug(l,r);
    }
    if(f(l)) 
        cout << l;
    else 
        cout << r;

}
