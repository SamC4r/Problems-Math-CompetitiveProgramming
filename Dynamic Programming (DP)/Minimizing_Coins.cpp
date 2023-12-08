#include<bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define forn(n) for(int i=0;i<int(n);i++)
#define endl "\n"



using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;



const int INF = 1e7 + 13;

int main(){
    //setIO("");
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n,x;
    cin >> n >> x;
    vector<int> coins(n);

    for(int i =0;i<n;i++) cin >> coins[i];

    vector<int> dp(x + 1);

    dp[0] = 0;

    for(int i = 1; i<=x;i++){
        dp[i] = INF;
        for(int c : coins){
            if(i - c >= 0){
                dp[i] = min(dp[i], dp[i-c] + 1);
            }
        }
    }
    cout << (dp[x] == INF ? -1 : dp[x]);


}
