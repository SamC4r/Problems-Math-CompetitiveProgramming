#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

vector<int> dp;
vector<bool> boi;

int solve(int n){
		
	if(boi[n]){
		return dp[n];
	}

	if(n == 0){
		return 1;
	}

	int best = 0;

	for(int i = 1; i <= 6;i++){
		if(n - i >= 0){
			best += solve(n - i);
			best %= mod;
		}
	}
	

	dp[n] = best;
	boi[n] = true;

	return best;
}



int main(){
	int n;
	cin >> n;
	dp.resize(n);
	boi.resize(n);
	cout << solve(n);
}