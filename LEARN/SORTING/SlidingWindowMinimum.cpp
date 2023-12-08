#include<bits/stdc++.h>
using namespace std;
int main(){
	//Subset of array. For each subset of that len find some characteristics.
	//2 1 4 5 3 4 1 2  0
	int n = 9;
	int m = 4; //report for every sliding window of size 4 the smallest value
	vector<int> a = {2,1,4,5,3,4,1,2,0};
	
	queue<pair<int,int>> q;
	
	
	/*
	 *First sliding: 2 1 4 5 --> q={2}
	 *
	 * */
	
	int l = 0;
	int r = 0;
	//Now i guess that it is indeed O(n)
	while(r<n){

		if(!q.empty() && q.front().second + 1 <= l) q.pop();
			
		while(!q.empty() && a[r] <= q.front().first){
			q.pop();
		}
	
		if(!q.empty()) cout << q.front().first << " "  << a[r]  << endl;
		
		q.push({a[r],r});
		if(r>=m-1)l++;
		//if(r >= m-1)cout << q.front().first << " ";// << r << " ";
		r++;
			
	}





}
