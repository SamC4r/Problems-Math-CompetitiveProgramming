#include<bits/stdc++.h>
using namespace std;
int main(){
	/*

	Models a problem as a set of events that are processed in sorted
	order.
	
	EX: 
	There is a restaurant and we know the
	arriving and leaving times of all 
	customers on a certain day. Our task 
	is to find out the maximum number of 
	customers who visited the restaurant at the same time.

SOL:

To find the maximum number of customers, we maintain
a counter whose value increases when a customer arrives and decreases when a
customer leaves. The largest value of the counter is the answer to the problem.

4
1 2
3 4
5 6
1 4

SETS: (1,2),(3,4),(5,6),(1,4)
FULL:

ALL SORTED: 1 1 2 3 4 4 5 6
ADD/SUBST?: + + - + - - + - max = 2;


for i in 6;


	*/

	int n;
	cin >> n;
	vector<pair<int,int>> a;


	for(int i = 0; i<n;i++){
		int x,y;
		cin >> x >> y;
		a.push_back(pair<int,int>(x,1));
		a.push_back(pair<int,int>(y,-1));
	}

	sort(a.begin(),a.end());

	int counter = 0;
	int maxC = 0;

	for(int i = 0; i<2*n;i++){
		
		counter+=a[i].second;
		maxC = max(maxC,counter);

	}

	cout << maxC << endl;

}