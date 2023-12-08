//generating subsets

#include<bits/stdc++.h>
#define int long long
using namespace std;
 
int sum = 0;
int sum_subset = 0;
int n;
vector<int> a;
int ans = 1e9;
void generate_subset(int k){
 
    if(k == n){
        //the recursion  reached the limit 
        ans = min(ans,abs(sum - sum_subset));
 
    }else{
        generate_subset(k + 1);
        sum_subset += a[k];
        sum-=a[k];
        generate_subset(k + 1);
        sum_subset -= a[k];
        sum+=a[k];
 
    }
 
 
}
 
signed main(){
     //up to 2^n
    cin >> n;
    a.resize(n);
    for(int i = 0; i<n;i++){
        cin >> a[i];
        sum += a[i];
    }
 
    generate_subset(0);//by taking positions
    cout << ans;
 
}
 
/**
 * 
 * 5
 * 3 2 7 4 1
 * go through each subset. 
 * 
*/