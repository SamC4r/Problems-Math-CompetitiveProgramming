#include<bits/stdc++.h>
using namespace std;
#define int long long


signed main(){
	int j,i;
	cin >> j >> i;
	vector<vector<int>> a(j+1,vector<int> (i+1));


	for(int n = 1; n<=j;n++){
		for(int k = 1; k<=i;k++){
			if(n <= k){//solo por encima de la diagonal de la matriz
				if (k % 2 == 0){
					//cout << (k-1)*(k-1) + n<<endl;
					a[n-1][k-1] = (k-1)*(k-1) + n;
				}else{
					//cout << k*k - n + 1<<endl;
					a[n-1][k-1] = k*k - n + 1;
				}
			}else{
				if(n % 2 == 0){
					//cout << n*n - k + 1<< endl;
					a[n-1][k-1] = n*n - k + 1;
				}else{
					//cout << (n-1)*(n-1) + k << endl;
					a[n-1][k-1] = (n-1)*(n-1) + k;
				}
			}
		}
	}

	for(auto r : a){
		for(auto b : r){
			cout << b << "  ";
		}
		cout << endl;
	}
}