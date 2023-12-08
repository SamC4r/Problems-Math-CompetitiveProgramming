#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){

	int t;
	cin >> t;
	while(t--){

		int n;
		cin >> n;
		vector<int> a(n);

		for(int i = 0; i<n;i++) cin >> a[i];

		int neg = 0;
		for(int i = 0; i<n;i++){
			if(a[i] < 0) neg++;
		}
		int s = 0;
		if(neg % 2 == 0){

			for(int i = 0; i<n;i++){
				s+=abs(a[i]);
			}
		}else{
			for(int i = 0; i<n;i++)a[i] = abs(a[i]);
			sort(a.begin(),a.end());

			a[0]*=-1;
			for(int i = 0; i<n;i++) s+=a[i];
		}
		cout << s << endl;



	}

}