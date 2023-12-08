#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long

signed main(){
	int n;
	cin >> n;
	// / n--;

	int sum = 0;
	int ans = (n*(n+1))/2;
	for(int i = 0; i < n-1;i++){
		int x;
		cin >> x;
		sum += x;
	}

	cout << ans - sum;
 
}