#include<bits/stdc++.h>
using namespace std;



/*

Combines greedy, recursion and complte search.
USed for 

1. YES/NO.
2. counting number of solutoins.
3. finding an optimal solution to problem.

Applied if the problem can be divided into smaller subproblems.
That's when recursion concept comes into light. 

Example coin problem:

Given a set
of coin values coins = { c 1 , c 2 , . . . , c k } and a target sum of money n, our task is to
form the sum n using as few coins as possible.


//Recurive formulation

solve(x) --> minimum coins required to form a sum x;
coins = {1,3,4}

base case: solve(0) = 0
		   solve(1) = 1;

continuing with the recursive calls:

solve(2) = 2;
solve(3) = 1;
...
...
...
solve(9) = 3;

at least 3 coins needed to form a sum of 9.
4 + 4 + 1;


trick:

1. Think of base cases
2. Try to get a recursive formulae
3. For better visualisation use trees!!!



base: solve(0) = 0
recursive formula: solve(x) = min(solve(x - 1) + 1, solve(x-3)+1,solve(x-4) + 1)
solve(x) = min(solve(x-c) + 1)


*/


vector<int> coins = {1,3,4};
vector<bool> visited;
vector<int> values;


int solveMemo(int n){
	
	int best = 1e9;

	if(n == 0){
		return 0;
	}
	if(visited[n]) return values[n];

	for(int i = 0; i<coins.size();i++){
		if(n - coins[i] >= 0){
			best = min(solveMemo(n - coins[i]) + 1,best);
		}
	}
	values[n] = best;
	visited[n] = true;
	return best;

}



int solveRecursion(int n){
	
	int best = 1e9;

	if(n == 0){
		return 0;
	}

	for(int i = 0; i<coins.size();i++){
		if(n - coins[i] >= 0){
			best = min(solveRecursion(n - coins[i]) + 1,best);
		}
	}

	return best;

}


int main(){
	int x = 9;
	visited.resize(x+1);
	values.resize(x+1);
	cout << solveRecursion(x) << endl;
	cout << solveMemo(x) << endl;

	//Iterative solution
	vector<int> dp(x+1);

	dp[0] = 0;

	for(int i = 1;i <=x;i++){
		dp[i] = 1e9;
		for(auto a : coins){
			if(i - a >= 0){
				dp[i] = min(dp[i], dp[i - a] + 1);
			}
		}
	}
	cout << dp[x] << endl;


}