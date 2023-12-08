//generating permutations

#include<bits/stdc++.h>
using namespace std;

int chosen[26];

string new_s = "";
string s;
string solution;
int cont = 0;
int n;

void solve(){
    if((int) new_s.length() == n){
        cont++;
        solution += new_s + "\n";
    }else{
        for(int i = 0; i<26;i++){
            if(chosen[i] > 0){
                chosen[i]--;
                new_s += (char)('a' + i);
                solve();
                chosen[i]++;
                new_s.pop_back();
            }
        }
    }
}

int main(){
    cin >> s;
    n = s.length();
    sort(s.begin(),s.end());
    for(char c : s) chosen[c-'a']++;
    solve();
    cout << cont << "\n" << solution;
}