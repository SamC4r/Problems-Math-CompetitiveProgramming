#include<bits/stdc++.h>
using namespace std;





int main(){
	int n,x;
	cin >> n >> x;
	vector<int>h(n); //price of each book
	vector<int> s(n); //numbetr of pages

	for(int i = 0; i<n;i++){
		cin >> h[i];
	}
	for(int i = 0; i<n;i++){
		cin >> s[i];
	}

	vector<vector<int>> dp;
	dp.resize(n + 1,vector<int>(x + 1));

	for(int i = 1; i<=n;i++){
		int price = h[i-1];
		int pages = s[i-1];
		for(int j = 1; j<=x;j++){
				


			if(j - price >= 0){
				dp[i][j] = dp[i-1][j - price] + pages;
			}

			dp[i][j] = max({dp[i][j-1],dp[i-1][j], dp[i][j]});
			//cout << dp[i][j] << " i: " << i << " j: " << j << endl;
		}
	}	
	
	cout << dp[n][x] << endl;

}

/*

4 8 5 3 //h
5 12 8 1 //s
*/