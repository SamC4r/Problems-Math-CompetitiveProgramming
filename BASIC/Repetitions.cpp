#include<bits/stdc++.h>

using namespace std;

int main(){
	string x;
	cin >> x;
	char l = x[0];
	int maxs = 1;
	int mx = 1;
	for(int i = 1; i<x.length();i++){
		// /cout << x[i] << " " << l << " ";
		if(x[i] == l){
			maxs++;
			mx = max(mx,maxs);
		}else{
			maxs = 1;
			l = x[i];
		}
	}
	cout << mx;
}