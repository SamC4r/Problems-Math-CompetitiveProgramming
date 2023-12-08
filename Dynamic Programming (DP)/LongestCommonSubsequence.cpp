
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

void read(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); //file input.txt is opened in reading mode i.e "r"
    freopen("output.txt","w",stdout);  //file output.txt is opened in writing mode i.e "w"
    #endif
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    string s1,s2;
    cin >> s1 >> s2;

   //they
    int n = s1.size();
    int m = s2.size();
    if(n < m){
        swap(s1,s2);
        swap(n,m);
    }
    vector<vector<int>> dp(m, vector<int> (n));

    for(int i = 0; i<m;i++){
        for(int j = 0; j<n;j++){
            
            if(i > 0)
                dp[i][j] = dp[i-1][j];

           
            if(j > 0)
                dp[i][j] = max(dp[i][j],dp[i][j-1]);

            if(i > 0 && j > 0 && s1[j] == s2[i]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
        }
    }
     
    cout << dp[m - 1][n - 1];
}

