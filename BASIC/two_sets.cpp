//SOLVEEEED!!

#include<bits/stdc++.h>
using namespace  std;
#define int long long
vector<int> a;
vector<bool> chosen;

void set1(int n,int s){
	
	int ss = s / 2; //subset sum
	a.resize(n);
	chosen.resize(n);
	for(int i = 0; i<n;i++){
		a[i] = i + 1;
	}

	int x = n - 1;
	int y = 0;
	while(ss > 0){
		if(a[x] <= ss){
			chosen[x] = true;	
			ss -= a[x];
			y++;
		}

		x--;	
	}	
	cout << y << endl;
	for(auto i : a){	
		if(chosen[i - 1]){
			cout << i << " ";
		}
	}
	cout << endl << n - y << endl;	
//	inoremap { {}<left>}}
	for(auto i : a){	
		if(!chosen[i - 1]){
			cout << i << " ";
		}
	}
}

signed main(){

	int n;
	cin >> n;
	int s = n*(n + 1) / 2;
	string ans = "";
	if(s % 2 == 0)
		ans = "YES";
	else
		ans = "NO";	
	cout << ans << endl;
	if(ans == "YES")
		set1(n,s);
}
