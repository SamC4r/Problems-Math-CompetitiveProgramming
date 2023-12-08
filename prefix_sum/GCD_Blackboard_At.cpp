#include<bits/stdc++.h>

using namespace std;

const int mx = 1e5 + 1;

int pr[mx];
int suf[mx];

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i<n;++i) cin >> a[i];

    pr[0] = 0;
    suf[n + 1] = 0;

    for(int i = 1;i<=n;i++) pr[i] = gcd(pr[i-1],a[i-1]); //gcd(a,b,c) = gcd(gcd(a,b),c)

    for(int i = n; i>=1;--i) suf[i] = gcd(suf[i + 1],a[i-1]);

    int ans = 0;

    for(int i = 1;i<=n;i++){
        ans = max(ans,gcd(pr[i-1],suf[i+1])); //gcd considering taking out element i
    }   
    cout << ans;

}