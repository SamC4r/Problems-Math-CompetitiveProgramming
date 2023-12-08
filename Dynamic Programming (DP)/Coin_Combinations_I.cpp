#include<bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define forn(n) for(int i=0;i<int(n);i++)
#define endl "\n"



using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int p = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int i = 0; i<n;i++) cin >> coins[i];
    vector<int> dp(x + 1);

    dp[0] = 1; //by using 0 coins you have 1 way

    for(int i =1; i<=x;i++){
        for(int c : coins){
            if(i >= c){
                dp[i] += dp[i-c];
                dp[i] %= p;
            }
        }
    }
    cout << dp[x];
}
