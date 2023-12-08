#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >>n;
					// arr,dep   index in original
	vector<pair<pair<int,int>,int>> v1(n);
	multiset<pair<int,int>> m;

	for(int i = 0; i<n;i++){
		cin >> v1[i].first.first >> v1[i].first.second;
		v1[i].second = i;
	}

	sort(v1.begin(),v1.end());

	vector<int> roomAssigned(n,-1);
	int roomId = 1;
				//  data type(departure,room)   //container: queue of pair<int,int>			// comparator: to get the smallest value on top
	priority_queue< pair<int,int>,                 vector<pair<int,int>>,          greater<pair<int,int>>> rooms;

	for(int i = 0; i<n;i++){
		if(rooms.size() == 0){
			roomAssigned[v1[i].second] = roomId++;
			rooms.push(make_pair(v1[i].first.second,roomId-1));

		}else{

			if(rooms.top().first < v1[i].first.first){
				roomAssigned[v1[i].second] = rooms.top().second;
				pair<int,int> x = rooms.top();
				rooms.pop();
				rooms.push(make_pair(v1[i].first.second,x.second));
			}else{
				roomAssigned[v1[i].second] = roomId++;
				rooms.push(make_pair(v1[i].first.second,roomId-1));
			}

		}
	}
	cout << roomId - 1 << endl;
	for(int i = 0; i<n;i++){
		cout <<roomAssigned[i] << " ";
	}
}


	/*
/*
10
6 6
5 5
6 6
10 10
7 7
10 10
6 6
8 8
3 3
9 9


3 3
5 5
6 6
6 6
6 6
7 7
8 8
9 9
10 10
10 10


10
7 7
7 9
10 10
8 9
10 10


1 2
2 3
2 6
5 6
5 7
7 7
7 9
8 9
10 10
10 10



	int cont = 0;
	m.insert(pair<int,int>(v1[0].second,++cont));
	vector<int> cont_v;
	cont_v.push_back(1);


	for(int i = 1;i<n;i++){

		bool pushi = true;
			// cout << " " << v1[i].first << " " << m[j].second << endl;
		pair<int,int> act = *m.begin();
		if(v1[i].first > act.first){
			act.first = v1[i].second;
			pushi = false;
			cont_v.push_back(act.second);
		}
		
		if(pushi){
			m.insert(pair<int,int>(v1[i].second,++cont));
			cont_v.push_back(cont);
		}

 	
 		///cout << " push: " << pushi << endl;

	}

	for(auto k : m){
		cont = max(k.second,cont);
		// cout << m[k].first << " " << m[k].second << endl;
	}
	cout << cont << endl;

	for(int i = 0; i<cont_v.size();i++) cout << cont_v[i] << " ";



}

*/