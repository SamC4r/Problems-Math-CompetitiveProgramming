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
vector<double> place;
vector<double> speed;
bool f(double t){
    //for each person you have max and min range in a time interval
    vector<pair<double,double>> range(n);

    forn(n){
        range[i] = {max((double)0,place[i] - speed[i]*t),min(1e9,place[i] + speed[i]*t)};
    }
    
    // debug(range,t);
    double l = 0;//range[n - 1].first;
    double r = 1e9;

    forn(n){
        l = max(l,range[i].first);
        r = min(r, range[i].second);
    }
    if(l<=r) return true;

    return false;
}

int main(){
    //setIO("");
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin  >> n;

    place.resize(n);
    speed.resize(n);
    
    forn(n) cin >> place[i];
    forn(n) cin >> speed[i];

    double l = 0.0, r = 1e9;

    while(abs(l - r) > 1/1e6){
        double mid = (l + r) / 2;
        if(f(mid)){
            r = mid;
        }else{
            l = mid;
        }
        //debug(l,r);
    } 
    cout << setprecision(16) << fixed;
    cout << l;

}
/*
3
1 3 7
2 1 1 

min time to get to a position p
will be abs((pos - start_x)/speed) = t



*/