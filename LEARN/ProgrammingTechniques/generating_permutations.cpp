#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> chosen;
vector<int> perm;



void search(){

	/*
	Each function call appends a new element to permutation and records
	that it has benn included in chosen. 
	If size of perm equals the size of the set there is a permutation. 
	Otherwise continue adding elements to perm that are not already in the
	permutation.
	*/

	if(perm.size() == n){
		for(auto a : perm){
			cout << a << " ";
		}
		cout << endl;
	}
	else{
		for(int i = 1; i<=n;i++){
			if(chosen[i]) continue;
			chosen[i] = true;
			perm.push_back(i);
			search();
			chosen[i] = false;
			perm.pop_back();
		}
	}
}



int main(){

	/*
	Generating permutations!!!

	perms of {1,2,3} are (1, 2, 3), (1, 3, 2), (2, 1, 3), (2, 3, 1),
	(3, 1, 2), and (3, 2, 1) --> 3!


	

	*/

	n = 3;
	chosen.resize(n + 1);
	search();

}