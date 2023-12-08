#include<bits/stdc++.h>
using namespace std;
int main(){
	/*
	A backtracking algorithm begins with an empty solution and extends 
	the solution step by step. The search recursively goes through all
	different ways how a solution can be constructed.
	
	PROBLEM: Number of ways n queens can be placed on an n*n board
	such that they don't attack each other.

	Possible solution:
	placing queens row by row.
	Exactly one queen will be placed on each row so that no queen attacks
	any of the queens placed before. (RECURSION!)


	IMPLEMENTATION

	void search(int y) {
		if (y == n) {
			count++;
			return;
		}
		for (int x = 0; x < n; x++) {

			if (col[x] || diag1[x+y] || diag2[x-y+n-1]) continue;
			
			col[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
			
			search(y+1);
			
			col[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
	
			}
		}
	


	CURIOSITY:

	3.2.2 Two Queens Problem

Given an n × n chessboard, our next problem is to count the number of ways we can
place two queens on the board in such a way that they do not attack each other. For
example, as Fig. 3.2 shows, there are eight ways to place two queens on the 3 × 3
board. Let q(n) denote the number of valid combinations for an n × n board. For
example, q(3) = 8, and Table 3.3 shows the values of q(n) for 1 ≤ n ≤ 10.
To start with, a simple way to solve the problem is to go through all possible ways
to place two queens on the board and count the combinations where the queens do
not attack each other. Such an algorithm works in O(n4) time, because there are n2
ways to choose the position of the first queen, and for each such position, there are
n2 − 1 ways to choose the position of the second queen.
Since the number of combinations grows fast, an algorithm that counts combina-
tions one by one will certainly be too slow for processing larger values of n. Thus, to
create an efficient algorithm, we need to find a way to count combinations in groups.
One useful observation is that it is quite easy to calculate the number of squares that
a single queen attacks (Fig. 3.3). First, it always attacks n − 1 squares horizontally
and n − 1 squares vertically. Then, for both diagonals, it attacks d − 1 squares where
d is the number of squares on the diagonal. Using this information, we can calculate
in O(1) time the number of squares where the other queen can be placed, which
yields an O(n2) time algorithm.
Another way to approach the problem is to try to formulate a recursive function
that counts the number of combinations. The question is: if we know the value of
q(n), how can we use it to calculate the value of q(n + 1)?
To get a recursive solution, we may focus on the last row and last column of the n ×
n board (Fig. 3.4). First, if there are no queens on the last row or column, the number
of combinations is simply q(n − 1). Then, there are 2n − 1 positions for a queen on
the last row or column. It attacks 3(n − 1) squares, so there are n2 − 3(n − 1) − 1
positions for the other queen. Finally, there are (n − 1)(n − 2) combinations where
both queens are on the last row or column. Since we counted those combinations
twice, we have to remove this number from the result. By combining all this, we get
a recursive formula
q(n) = q(n − 1) + (2n − 1)(n2 − 3(n − 1) − 1) − (n − 1)(n − 2)
= q(n − 1) + 2(n − 1)2(n − 2),
which provides an O(n) solution to the problem.
Finally, it turns out that there is also a closed-form formula

q(n) = n^4/2 - 5n^3/3 + 3n^2/2 -n/3

which can be proved using induction and the recursive formula. Using this formula,
we can solve the problem in O(1) time






























	*/

}