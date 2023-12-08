#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;cin>>n;
		vector<int> a(n);
		for(int i = 1; i<=n;i++){
			if(i % 2 == 0)
				a[i-1] = i;
			else
				a[i/2 + (i-1)] = i; 
		}
		for(auto b : a){
			cout << b << " ";
		}
		cout << endl;
	}
}