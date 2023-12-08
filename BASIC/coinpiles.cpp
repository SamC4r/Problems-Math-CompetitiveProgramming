#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
 
    while(n--){
        int x,y;
        cin >> x >> y;
 
        if(max(x,y) <= 2*min(x,y) && (x + y) % 3 == 0){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
 
    }
 
 
 
}