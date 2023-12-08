#include<bits/stdc++.h>
using namespace std;

int main(){

    freopen("hps.in","r", stdin);
    freopen("hps.out","w", stdout);


    int n; cin >> n;

    vector<vector<int>> wins(4,vector<int>(n + 2));//n),vector<int> wins_p(n), vector<int> wins_h(n);
    
    for(int i = 1; i<=n;i++){
        char x;
        cin >> x;
        if(x == 'P'){ //S wins
            wins[1][i] = wins[1][i-1] + 1;
            wins[2][i] = wins[2][i-1];
            wins[3][i] = wins[3][i-1];

        }
        if(x == 'H'){ //p Wins
            wins[2][i] = wins[2][i-1] + 1;
            wins[1][i] = wins[1][i-1];
            wins[3][i] = wins[3][i-1];
        }
        if(x == 'S') { //H wins
            wins[3][i] = wins[3][i-1] + 1;
            wins[2][i] = wins[2][i-1];
            wins[1][i] = wins[1][i-1];
        }
    }

    // for(auto a : wins){
    //     for(auto b : a){
    //         cout << b << " ";
    //     }
    //     cout << endl;
    // }
    
    int best = 0;

    for(int j = 1; j<=3;j++){
        for(int k = 1; k<=3;k++){
            if(k == j) continue;
            for(int i =  0; i<n;i++){
                //cout << (wins[k][n-i] - wins[k][n-i-1]) << endl;
                if(i == 0) best = max(best,wins[j][n]);
                else best = max(best, (wins[j][n - i] + (wins[k][n] - wins[k][n-i])));
            }
        }
    }
    cout << best;

}


//count/know when to change.
// find the one that produces the biggest sum first.
// find the other one that produces the biggest sum from the point where the other stops?