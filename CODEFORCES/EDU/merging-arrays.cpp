#include<bits/stdc++.h>
using namespace std;
int main(){

	int n,m;
	cin >> n >> m;

	vector<int> a(n),b(m);
	vector<int> ans;


	for(int i = 0; i<n;i++) cin >> a[i];
	for(int i = 0; i<m;i++) cin >> b[i];

	a.push_back(1e9 + 7);
	b.push_back(1e9 + 7);



	int l = 0;
	int r=0;

	while(l < n || r < m){

		if(a[l] < b[r]){
			ans.push_back(a[l]);
			l++;
		}else{
			ans.push_back(b[r]);
			r++;
		}

	}

	for(auto a : ans) cout << a << " ";


}