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

vector<int> a;
int med;
int n,k;
bool f(int x){
    ll needed = 0;
    for(int i = n/2;i<n;i++){
        needed+=max(0,x - a[i]); //only if its below the median
    }
    if(needed <= k) return true;
    else return false;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> k;
    a.resize(n);
    forn(n) cin >> a[i];
    sort(all(a));
   



    ll l = 0, r =2e9 + 1;
    while(l < r - 1){
        ll mid = (l + r) /2;
        if(!f(mid)){
            r = mid;
        }else{
            l = mid;
        }
 //       debug(l,r);
    }   
    cout << l;

}

/**
 * 
 * 7 7
 4 1 2 4 3 4 4

 >> 1 2 3 4 4 4 4 
*/
