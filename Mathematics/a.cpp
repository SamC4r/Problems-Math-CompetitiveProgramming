#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int q = 0; q < n; q++) {
		int x;
		int div_num = 0;
		cin >> x;
		for (int i = 1; i * i <= x; i++) {
			if (x % i == 0) { 
				if(i*i == x) div_num++; //reach last iteration. 
				else div_num += 2;//If that divisor is less than the square root of n then it has as corresponding ddivisor greater than the square root of it. 
			//	div_num += i * i == x ? 1 : 2; 
			}
		}
		cout << div_num << '\n';
	}
}




























