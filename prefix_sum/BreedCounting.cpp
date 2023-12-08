//#/bin/usr/c++
#include<bits/stdc++.h>
#define endl "\n"

using namespace std;


int main(){
    freopen("bcount.in","r",stdin);
    freopen("bcount.out","w",stdout);

    int n,q;
    cin >> n >> q;

    vector<int> cows(n);

    for(int i = 0; i<n;i++) cin >> cows[i];

    vector<int> type1(n + 1),type2(n + 1),type3(n + 1);

    for(int i = 1; i<=n;i++){
        int c = cows[i - 1];
        if(c == 1){
            type1[i] = type1[i-1] + 1;
            type2[i] = type2[i-1];
            type3[i] = type3[i-1];
        }
        if(c == 2){
            type2[i] = type2[i-1] + 1;
            type1[i] = type1[i-1];
            type3[i] = type3[i-1];
        }
        if(c == 3){
            type3[i] = type3[i-1] + 1;
            type2[i] = type2[i-1];
            type1[i] = type1[i-1];
        }
    }

    while(q--){
        int a,b;
        cin >> b >> a;
        b--;

        cout << type1[a] - type1[b] << " " << type2[a] - type2[b] << " " << type3[a] - type3[b] << endl;

    }


}