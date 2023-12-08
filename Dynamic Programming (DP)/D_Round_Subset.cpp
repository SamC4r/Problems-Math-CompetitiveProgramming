#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

int N = 207;
int C = 6000;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n,k;
    cin >> n >> k;
    vector<ll> pw5(n);
    vector<ll> pw2(n);

    for(int i = 0; i<n;i++){

        ll x2; 
        cin >> x2;
        ll x5 = x2;

        while((!(x2 & 1))){
            pw2[i]++;
            x2 >>= 1;
        }
        while(x5 % 5 == 0){
            pw5[i]++;
            x5 /= 5;
        }
    }

    ll dp[k+1][C];

    for(int i = 0; i<=k;i++){
        for(int j = 0; j<C;j++){
            dp[i][j] = -1;
        }
    }

    dp[0][0] = 0;
    //dp[i][j][l]  --> max power of 2 going through first i numbers, choosing j of them with a power of five equal to l!
    for(int i = 0; i<n;i++){
        for(int j = k; j>=0;--j){
            for(int b = C - 1; b>=0;--b){
                if(dp[j][b] >= 0 && j + 1 <= k && b + pw5[i] < C){
                    dp[j + 1][b + pw5[i]] = max(dp[j+1][b + pw5[i]],dp[j][b] + pw2[i]);
                }
            }
        }
    }

    ll ans = 0;
    for(ll i = 1; i<C;++i){
        ans = max(ans, min(i,dp[k][i])); //max of the minimum of powers of 5 or poweros of 2!   ---> wat
    }
    cout << ans;


}