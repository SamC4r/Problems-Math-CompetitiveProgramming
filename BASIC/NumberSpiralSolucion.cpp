#include<bits/stdc++.h>
using namespace std;
#define int long long
 
void solve(){
	int n,k;
	cin >> n >> k;
 
	if(n < k){
		if (k % 2 == 0){
			cout << (k-1)*(k-1) + n<<'\n';
		}else{
			cout << k*k - n + 1<<'\n';
		}
	}else{
		if(n % 2 == 0){
			cout << n*n - k + 1<< '\n';
		}else{
			cout << (n-1)*(n-1) + k << '\n';//cambiar por endl y ayuda a mejorar la efifiencai
		}
	}
}
 
signed main(){

	//Con esto pasa de 0.21s a 0.05s WAT????
	ios_base::sync_with_stdio(0);
    cin.tie(0);


	int T;
	cin >> T;
	while(T--){
		solve();
	}
}