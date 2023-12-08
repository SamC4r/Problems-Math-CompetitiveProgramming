#include<bits/stdc++.h>

#define int long long


using namespace std;


const int oo = 1e9 + 13;

signed main(){
    //setIO("");
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    vector<int> dp(n + 1,-1);
    vector<int> h(n + 1);
    for(int i = 1; i<=n;i++) cin >> h[i];
    dp[1] = 0;
    for(int i = 2; i<=n;i++){
        dp[i] = oo;
        for(int jump = 1; jump<=k && jump < i;jump++){
            dp[i] = min(dp[i], dp[i-jump] + abs(h[i - jump] - h[i]));
        }
    }
   // debug(dp);
    cout << dp[n];

}
