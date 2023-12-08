#include<bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define forn(n) for(int i=0;i<int(n);i++)
#define endl "\n"



using namespace std;

typedef long long ll;

int MX = 100000;

int main(){
    //setIO("");
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i<n;i++){
        cin >> a[i];
    }

    vector<vector<bool>> dp(n + 1, vector<bool> (MX + 1));

    dp[0][0] = true;

    set<int> nums;
    int ans = 0;

    for(int i = 1; i<=n;i++){
        for(int j = 0;j <=MX;j++){
            dp[i][j] = dp[i][j] | dp[i-1][j];
            
            if(j >= a[i-1]){
                dp[i][j] =  dp[i][j] | dp[i-1][j - a[i-1]];
            }    
            
            if(dp[i][j]){
                if(j!=0)nums.insert(j);
            }
        }
    }

    //  for(int i = 0; i<=n;i++){
    //     for(int j = 1;j <=20;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << nums.size() << endl;
    for(auto i : nums) cout << i << " ";


    

}
