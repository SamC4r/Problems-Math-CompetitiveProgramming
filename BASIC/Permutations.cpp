#include<bits/stdc++.h>


using namespace std;

void calcular(int n){

	vector<int> a(n);
	int it = 2;
	int mult = 1;
	for(int i = 0; i<n;i++){
		a[i] = it;
		it+= 2;// * mult;
		if(it>n){
			it = 1;
			//mult *= -1;
		}
	}

	for(auto c : a){
		cout << c << " ";
	}

}



int main(){
	int n;
	cin >> n;
	if(n <= 3 && n != 1){
		cout << "NO SOLUTION" <<endl;
	}else if (n == 1){
		cout << 1;
	}else{
		calcular(n);
	}
}