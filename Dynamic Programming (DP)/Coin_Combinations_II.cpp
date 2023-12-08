#include<bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define forn(n) for(int i=0;i<int(n);i++)
#define endl "\n"



using namespace std;


const int p = 1e9+7;

int main(){
    //setIO("");
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,x;
    cin >> n >> x;
    int dp[x+1];
    memset(dp,0,sizeof(dp));    
    dp[0] = 1;
    //quite like a knapsack?
    for(int j = 0; j<n;j++){
        int c; cin >> c;
        for(int i = c;i<=x;i++){
            if(i>=c){   
                dp[i] += dp[i-c];
                dp[i] %= p;
            }
        }
        // debug(dp);
    }
    cout << dp[x];
}
