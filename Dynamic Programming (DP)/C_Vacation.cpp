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

    int n;
    cin >> n;
/*
To solve this problem, we will maintain a 2D array, dp[n][3].
dp[i][0] will store the maximum points we can gain by doing activity A on day i.
dp[i][1] will store the maximum points we can gain by doing activity B on day i.
dp[i][2] will store the maximum points we can gain by doing activity C on day i. 
*/
    vector<vector<int>> dp(n + 1,vector<int>(4));

    vector<vector<int>> hap(n + 1, vector<int>(4)); 

    for(int i = 1; i<=n;i++){
        for(int j = 1; j <= 3;j++){
            cin >> hap[i][j];
        }
    }

    dp[1][1] = hap[1][1];
    dp[1][2] = hap[1][2];
    dp[1][3] = hap[1][3];

    for(int i = 2; i<=n;i++){
        for(int j = 1; j<=3;j++){
            for(int a = 1; a<=3;a++){
                if(a == j) continue;
                dp[i][j] = max(dp[i][j],dp[i-1][a]);
            }
            dp[i][j] += hap[i][j];
        }
    }

    cout << *max_element(dp[n].begin(),dp[n].end());



//     int last_pos = -1;
//     int mx = 0;
//     for(int i = 0; i<3;i++){
//         if(hap[1][i] > mx){
//             last_pos = i;
//         }
//     }
//    // debug(last_pos);

//     for(int  i =2 ; i<=n;i++){
//         int lp = -1;
//         for(int pos = 0; pos < 3 ; pos++){
//             if(pos != last_pos){
//                 if(dp[i-1] + hap[i][pos] >= dp[i]){
//                     dp[i] = dp[i-1] + hap[i][pos];
//                     lp = pos;
//                 }
//             }
//         }
//         last_pos = lp;

//     }
//     //debug(dp);
//     cout << dp[n];


}
