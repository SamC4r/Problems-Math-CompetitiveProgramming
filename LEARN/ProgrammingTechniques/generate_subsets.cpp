#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> subset;
void search(int k){
	if(k == n + 1){
		for(auto a : subset){
			cout << a << " ";
		}
		cout << endl;
	}
	else{
		//include k in subset
		subset.push_back(k);
		search(k + 1);
		subset.pop_back();


		//dont include k
		search(k + 1);
	}
}


int main(){

	//WITH RECURSION
	/*
	Generating all subsets of a set of n elements. 
	{1,2,3}
	
	At each function call,
	either the upper branch (k is included in the subset) or the lower branch (k is not
	included in the subset) is chosen.
	LOOK AT PICTURE!!.

	*/
	n = 3;
	search(1);
}