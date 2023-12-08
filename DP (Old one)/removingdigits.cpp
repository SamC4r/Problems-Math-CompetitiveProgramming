#include<bits/stdc++.h>
using namespace std;


int func(int n){


	int mx = 0;

	while(n>0){
		mx = max(mx,n % 10);
		n/=10;
	}	
	return mx;

}





int main(){
	int n;
	cin >> n;
	vector<int> dp(n + 1,1);
	dp[0] = 0;
	for(int i = 1;i<=n;i++){
		int mx = func(i);
		dp[i] = dp[i - mx] + 1;
		//cout << mx << " " << i << " " << dp[i] << endl;
	}

	cout << dp[n];

}