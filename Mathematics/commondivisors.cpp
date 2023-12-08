#include<bits/stdc++.h>
using namespace std;

const int INF = 1e6 + 1;
vector<int> max_p(INF + 1);


int gcd(int a,int b){
	if(a == 1 || b == 0) return a;

	return gcd(b,a % b);
}
	
int main(){
	
	
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i<n;i++) cin >> a[i];

	//sort(a.begin(),a.end());

	//Naive approach
	//
	int sol = 0;
	for(int i = 0; i<n-1;i++){
		
		for(int j = i + 1; j<n;j++){
			
			sol = max(sol,gcd(a[i],a[j]));	
			
		}
	
	}
	cout << sol;
	

}
