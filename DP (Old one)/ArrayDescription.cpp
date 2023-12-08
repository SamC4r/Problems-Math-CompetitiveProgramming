#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int n,m;


signed main(){

	cin >> n >> m;
	vector<int>a(n);

	for(int i = 0;i<n;i++){
		cin >> a[i];
	}

	vector<vector<int>> dp(n,vector<int>(m + 1,0));

	if(a[0] != 0){
		dp[0][a[0]] = 1;
	}else{
		for(int i = 1; i<=m;i++){
			dp[0][i] = 1;
		}
	}

	for(int i = 1; i<n;i++){

		if(a[i] == 0){

			for(int j = 1; j<=m;j++){
				//three cases. j,j-1,j+1 are the 2 possible cases that match the description
					

				/*
					1
				2   2  2
					3
					4
				*/
				// looking to the previous node	
				dp[i][j] += dp[i-1][j];
				dp[i][j]%=mod;


				//looking to previous and down.

				if(j - 1 >= 1){
					dp[i][j] += dp[i-1][j-1];
					dp[i][j]%=mod;

				}


				//looking previous and up
				if(j + 1 <= m){
					dp[i][j]+= dp[i-1][j+1];
					dp[i][j]%=mod;
				}


			}
		}else{

			//previous. 2 -- 2
			dp[i][a[i]] += dp[i-1][a[i]];
			dp[i][a[i]]%=mod;


			//previous and down
			if(a[i] - 1 >= 1){

				dp[i][a[i]] += dp[i-1][a[i] - 1];
				dp[i][a[i]]%=mod;
			}

			//previous and up
			if(a[i] + 1 <= m){

				dp[i][a[i]] += dp[i-1][a[i] + 1];
				dp[i][a[i]]%=mod;
			}

		}

	}

	long long total = 0;

	//sum all possible path that arrive at last layer!!
	for(int i = 1; i<=m;i++){
		total += dp[n-1][i];
		total %= mod;
	}
	cout << total;



}