#include<bits/stdc++.h>
#define int long long
using namespace std;

int main(){
    int n,m,a;
    cin >> n >> m >> a;
    
    int one = n/a + (n%a > 0);
    int two = m/a + (m%a > 0);
    int ans = one*two;
    cout << ans;


}
