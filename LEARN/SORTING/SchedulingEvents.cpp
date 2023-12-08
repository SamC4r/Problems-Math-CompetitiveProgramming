#include<bits/stdc++.h>
using namespace std;
int main(){
	// Many scheduling problems can be solved using greedy algorithms.

	/*

	EXAMPLE:

	Given n events with their starting
	and ending times, find a schedule 
	that includes as many events as possible.


SOL:
sort the events according to their ending times and always select
the next possible event that ends as early as possible




In a movie festival n movies will be shown. You know the starting and ending time of each movie. What is the maximum number of movies you can watch entirely?

Input

The first input line has an integer n: the number of movies.

After this, there are n lines that describe the movies. Each line has two integers a and b: the starting and ending times of a movie.

Output

Print one integer: the maximum number of movies.

Constraints

    1≤n≤2⋅105


1≤a<b≤109


Example

Input:
3
3 5
4 9
5 8

Output:
2


	*/

	int n;
	cin >> n;
	vector<pair<int,int>> a;
	for(int i = 0; i<n;i++){
		int x,y;
		cin >> x >> y;
		a.push_back(pair<int,int>(y,x));
	}
	sort(a.begin(),a.end());
	int contador = 1;
	int endingTime = a[0].first;
	for(int i = 1; i<n;i++){
		if(a[i].second >= endingTime){
			contador++;
			endingTime = a[i].first;
		}
	}
	cout << contador << endl;

}
