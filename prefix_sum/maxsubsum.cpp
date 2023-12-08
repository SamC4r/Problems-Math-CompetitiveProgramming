#include<bits/stdc++.h>

#define int long long
using namespace std;
signed main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i<n;i++) cin >> a[i];

    int mx = a[0];
    int best = 0;

    // 8 9 1 0 -2 9 1 0 9 -4
    // -1 -2 -3 -5 -2 9
    for(int i = 0; i<n;i++){
        best = max(a[i], best + a[i]);
        mx = max(mx,best);
    }

    cout << mx << endl;

}