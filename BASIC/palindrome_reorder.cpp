//SOLVED!!!!

#include<bits/stdc++.h>

using namespace std;
int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	unordered_map<char,int>a;

	for(int i = 0; i<s.length();i++){
		if(a.count(s[i])){
			a[s[i]]++;	
		}else{
			a.insert({s[i],1});
		}

	}
	string s2 = "";
	int ones = 0;
	string ons = "";
	for(auto i : a){
		if(i.second % 2 != 0){
		       	ones++;
			ons += i.first;
		}
		for(int j = 1; j<=i.second/2;j++) s2 += i.first;
	}
	 
	if(ones > 1)
		cout << "NO SOLUTION";
	else{
		cout << s2; 
		cout << ons;
		reverse(s2.begin(),s2.end());
		cout << s2;
	}
}
