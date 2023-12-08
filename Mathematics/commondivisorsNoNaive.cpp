#include<bits/stdc++.h>
#define vi vector<int>

using namespace std;




int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vi div(1e6 + 1);
	
	int n;
	cin >> n;

	div[1] = n;
	
	for(int i = 0; i<n;i++){
		int a;
		cin >> a;
		div[a]++;
		int up = sqrt(a);	
		for(int j = 2; j <= up; j++){			
			if(a % j == 0){
				div[j]++; //the divisor divides it
				//a[i]/=j;///?divide de number. NO otherwise you might avoid counting others
				// avoid double counting. CASE 16/4 gives for and you will be counting 4 two times. One for the divisor and other for the results
				if(j != a/j) div[a/j]++; //the result of the division also divides it				
								//
			}
		
		}
	}
	
	
	for(int i = 1e6; i>=1;i--){
		//cout << div[i] << " " << i << endl;
		if(div[i] >= 2) {
			cout << i;
			return 0;	
		}
	}

}
