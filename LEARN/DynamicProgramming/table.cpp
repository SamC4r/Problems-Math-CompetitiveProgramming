#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int n;
	cin >> n;
	multiset<int> s;
	//TLE
	for(int i = 1; i<=n;i++){
		for(int j = 1; j<=n;j++){
			s.insert(i*j);
		}
	}
	for(auto a : s)cout <<a <<' ';
	cout << *next(s.begin(),n*n/2);

}