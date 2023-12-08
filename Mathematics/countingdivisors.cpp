#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6  +1;
int max_div[MAX_N + 1];

int main(){
//SIEVE. LARGEST PRIME THAT DIVIDES A NUMBER. OTW YOU GET TLE	
	for (int i = 2; i <= MAX_N; i++) {

		if (max_div[i] == 0) {

			for (int j = i; j <= MAX_N; j += i) { max_div[j] = i; }

		}

	}

	int n;
	cin >> n;
	while(n--){
		
		int x;
		cin >> x;
		int s = 1;
		int c  =0;
		for(int i  = 2; i*i <=x + 1;i++){	
			while(x % i == 0){
				c++;
				x/=i;
			
			//cout << i << endl;
			}
			s *= (c+1);
			c = 0;
		}
		
		cout << s << "\n";
	
	
	
	
	}

}
