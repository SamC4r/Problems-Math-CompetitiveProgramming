#include<bits/stdc++.h>

using namespace std;





/// BINARY SEARCH

/*


	TO FIND THE POSITION WHERE THE VALUE OF A *FUNCITON* CHANGES

	- ALWAYS FOR A SORTED ARRAY. Because it guides the sear
	*/

bool check(int x){
	if(x <= 233) return true;
	else return false;
}



void smallestValue(int n, vector<int> array){

//Suppose that we wish to find the smallest value k that is a
//valid solution for a problem. We are given a function check ( x )
// that returns true if x -->
//is a valid solution and false otherwise. In addition, we know -->
	// that --> 
//check ( x ) is false when x < k and true when x >= k (FOR SMALLEST SOL). 

// SMALL SOL = FIRST VALUE OF X FOR WHICH THE PROBLEM SOLVES. =====>    -,-,-,-,+,+,+,+
//BIGGEST SOL = LAST VALUE OF X FOR WHICH THE PROBLEM SOLVES. =====>    +,+,+,+,-,-,-,-

	int x = -1;
	int z = 1e9;

//The initial -->
//jump length z has to be large enough, -->
//for example some value for which we know beforehand that -->
// ok ( z ) is true for smallest solution.
	

	for(int b = z; b >= 1; b/=2){
		while(!ok(x+b)){
			x += b;
		}
	}

	int k = x + 1;

	//The search finds the largest value of x -->
	//for which ok ( x ) is false . Thus, the next -->
//	  value k = x + 1 is the smallest possible value -->
// 	  for which ok ( k ) is true .

}


void largestValue(int n, vector<int> array){

	

}




int main(){
	int n;
	cin >> n;
	vector<int> array(n);

	for(int i = 0; i<n;i++){
		cin >> array[i];
	}

	sort(array.begin(),array.end());


	//Problema
	smallestValue(n,array);

}