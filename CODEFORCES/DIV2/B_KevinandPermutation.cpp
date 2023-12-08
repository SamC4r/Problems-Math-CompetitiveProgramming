#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n);
		int first = n/2;
		int j = 1;
		int m = 1;
		for(int i = 0; i<n;i++){
			if(i % 2 != 0){
			 a[i] = j;
			 j++;
			}else {
				a[i] = first + m;
				m++;
			}
			//cout << m << " " << j << endl;
		}
		for(auto b : a){
			cout << b << " ";
		}
		cout << endl;
	}
}