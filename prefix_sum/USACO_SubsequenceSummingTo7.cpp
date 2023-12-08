#include<bits/stdc++.h>
#define int long long
using namespace std;


//SOLVEDD!!!! 

const int m = 7;

signed main(){
    freopen("div7.in","r",stdin);
    freopen("div7.out","w",stdout);
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i = 0; i<N;i++) cin >> a[i];

    map<int,int> mp;    //number, minimum position of appeareance
    mp[0] = 0;

    int ps = 0;
    int ans = 0;
    for(int i = 1; i<=N;i++){
        ps += a[i - 1];
        int exp = ps % m;
        //check if it exists
        if(mp.count(exp)){
            ans = max(ans,i - mp[exp]);
            //cout << ans << " i: " << i << ' ' << mp[exp] << " " << exp << " ps: " << ps << endl;
        }
        if(mp[exp] == 0) mp[exp] = i;
        else mp[exp] = min(mp[exp],i);
    }
    cout << ans;

}