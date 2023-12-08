#include<bits/stdc++.h>
using namespace std;

/*



Problems where a set of objects is given, and
subsets with some properties have to be found. 
solved using dynamic programming.



problem: 

Given a list of weights
[w1 , w2 , . . . , wn ], determine all sums that can be constructed using the weights.
For example, if the weights are [1, 3, 3, 5], the following sums are possible:

0,1,3,4,5,6,7,8,9,11,12


	
possible(x,k) = true

means that it is possible to construct the sum x with the first k weights.

possible(x,k) = possible(x - w_k, k - 1) || possible(x,k - 1);

we can either use or not the weight w_k.


base case:

possible(x,0) = true if x = 0, else false --> cant form the sum

The formula is based on the fact that we can either use or not use the weight wk
in the sum. If we use wk , the remaining task is to form the sum x − wk using the
first k − 1 weights. If we do not use wk , the remaining task is to form the sum
x using the first k − 1 weights.

*/






int main(){

	int n,W; //form sum n and k weight values follow
	cin >> n >> W;

	vector<vector<bool>> possible;
	possible.resize(n + 1,vector<bool>(W + 1));
	vector<int> w(W);

	for(int i = 0; i<W;i++){
		cin >> w[i];
	}

	possible[0][0] = true;

	for(int k = 1; k<=n;k++){
		for(int x = 0; x<=W;x++){
			if(x - w[k] >= 0)
				possible[x][x] = possible[x - w[k]][k - 1];
			possible[x][k] = possible[x][k-1];
		}
	}

	cout << possible[n][n] << endl;

}