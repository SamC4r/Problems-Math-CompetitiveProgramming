#include<bits/stdc++.h>
#define vi vector<int>
#define endl "\n"
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	cin >> n;
	while(n--){
		int x;
		cin >> x;
		int sum = 0;
		int ones = 0, twos = 0;
		for(int i = 0; i<x;i++){
			int y;
			cin >> y;
			sum+=y;
			if(y == 1) ones++;
			else twos++;
		}
		if(sum % 2 != 0){
			cout << "NO" << endl;
		}else{
			int twos_rem = twos % 2;
			if(twos_rem == 1){
				ones-=2*twos_rem;
				ones = max(-1,ones);
			}
			
			if(ones % 2 == 0) cout << "YES" << endl;
			else cout << "NO" << endl;
		}

	}
}