#include<bits/stdc++.h>
using namespace std;
#define endl "\n";
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> arr(n);

	for(int i = 0; i<n;i++){
		cin >> arr[i];
	}

	//THIS CODE GIVES THE NUMBER OF INDICES BUT NOT THE LIS.

	vector<int> dp;


	dp.push_back(arr[0]);
	for(int i = 1; i<n;i++){

		int actual = arr[i];

		int j = lower_bound(dp.begin(),dp.end(),arr[i]) - dp.begin();

		if(actual <= dp[j]){
			dp[j] = actual;
		}else{
			dp.push_back(actual);
		}
		// cout << dp[i] << endl;
	}
	cout << dp.size() << endl;
}