#include<bits/stdc++.h>
using namespace std;


vector<int>a;
vector<bool> visited;
vector<int> values;
const int m = 1e9 + 7;
int main(){
	int n,x;
	cin >> n >> x;
	a.resize(n);
	visited.resize(x);
	values.resize(x);

	for(int i = 0; i<n;i++) cin >> a[i];

	vector<int> dp(x + 1);
	dp[0] = 1;

	for(int i =0;i<n;i++){
		for(int j = 1;j<=x;j++){
			if(j - a[i] >= 0){
				dp[j] += dp[j - a[i]];
				dp[j] %= m;
			}
		}
	}

	cout << dp[x] << endl;

}