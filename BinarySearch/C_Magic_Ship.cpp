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

ll x1,y11,x2,y2;
ll n;
string s;


bool f(ll x){
    ll wind_x = 0, wind_y = 0;
    ll start_x = x1, start_y = y11, end_x = x2, end_y = y2;

    for(char c : s){
        if(c == 'U') wind_y++;
        if(c == 'D') wind_y--;
        if(c == 'L') wind_x--;
        if(c == 'R') wind_x++;
    }

    wind_x *= x / n;
    wind_y *= x / n;
    ll rem = x % n;

   for(ll i=0; i<rem;i++){
        char c = s[i];
        if(c == 'U') wind_y++;
        if(c == 'D') wind_y--;
        if(c == 'L') wind_x--;
        if(c == 'R') wind_x++;
    }

    start_x += wind_x;
    start_y += wind_y;

    return abs(start_x - end_x) + abs(start_y - end_y) <= x;



}

int main(){
    //setIO("");
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> x1 >> y11 >> x2 >> y2 >> n >> s;

    ll l = 0, r = 1e18;

    while(l < r){
        ll mid = (l + r) / 2;
        debug(l,r,mid);
        if(f(mid)){
            r = mid;
        }else{
            l = mid + 1; //you cant reach it at mid. In the next iteration checks mid + 1
        }
        debug(l,r);

    } 
    if(r >= 1e18) r = -1;
    cout << r;
    

}
