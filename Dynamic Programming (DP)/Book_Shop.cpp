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


int main(){
    //setIO("");
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n,h;
    cin >> n >> h;
    int price[n];
    int pages[n];

    for(int i = 0; i<n;i++){
        cin>>price[i];
    }

    for(int i = 0; i<n;i++){
        cin>>pages[i];
    }

    vector<vector<int>> dp(n + 1, vector<int> (h + 1)); //dp[i][j] = max pages using i books at the price j

    for(int i = 1; i<=h;i++){
        if(i >= price[0])
            dp[1][i] = pages[0];
    }

    for(int i = 2; i<=n;i++){
        for(int j = 1; j<=h;j++){
            dp[i][j] = dp[i-1][j];
            if(j > 1) dp[i][j] = max(dp[i][j],dp[i][j-1]);
            if(j >= price[i-1]){
                dp[i][j] = max(dp[i][j],dp[i-1][j - price[i-1]] + pages[i-1]);
            }
        }
    }
    cout << dp[n][h];

    

}
