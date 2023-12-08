#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    string s;
    cin >> n >> s;
    vector<int> a(n);
    for(int i = 0; i<n;i++) a[i] = s[i] - '1';
    //for(auto p : a) cout << p << " ";
    
    map<int,int> mp;
    mp[0] = 1;
    int  ps = 0;
    int cont = 0;
    for(auto p : a){
        ps+=p;
        cont += mp[ps];
        mp[ps]++;
    }
    cout << cont << endl;

}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}