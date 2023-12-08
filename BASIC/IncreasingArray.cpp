#include<bits/stdc++.h>

#define int long long
using namespace std;


signed main(){

	int n;
	cin >> n;

	vector<int> a(n);

	for(int i = 0; i<n;i++){
		cin >> a[i];
	}


	int moves = 0, mov = 0;
	for(int i = 1; i<n;i++){
		if(a[i-1] > a[i]){
			moves += a[i-1] - a[i];
			mov = a[i-1] - a[i];
			a[i] = a[i] + mov;
			//cout << " moves : " << moves <<endl;
		}
	}

	cout << moves << endl;


}