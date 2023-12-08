#include<bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

typedef long long ll;

using namespace std;

int main(){
    int n,t;
    cin >> n >> t;
    vector<int> a(n);

    for(int i = 0; i<n;i++) cin >> a[i];

    int l = 0, r = 0;

    ll sum = 0;
    int ans = 0;
    while(l < n){

        while(sum + a[r] <= t && r < n){
            sum += a[r];
            r++; 
          //  cout << "l " << l << " r " <<  r <<  " --sum-- " << sum << endl;
        }
       //
      // cout << "> l " << l << " r " <<  r <<  " --sum-- " << sum << endl;

        ans = max(ans, r - l);
        sum -= a[l];
        l++;
    }

    cout << ans;
    
    
}

/**
 * 
 * 4 5
 * 3 1 2 1
 * [1 2 1]
 * ps = 3,4,6,7
 * 
 * longest 
 * a_i + a_(i+1) + ... +  a_(i + r) <= t
 * 
 * 
 * two pointers?
 * 
 * suppose its the full array 
 * 3 1 2 1
 * |     |
 * 3 4 6 7
 * 7 -1 or 7 - 3 : 6, 4
 * until sum is less or equals than t
 * 
 * 2 2 3
 * 2 4 7
 * 2 4
 * 
*/