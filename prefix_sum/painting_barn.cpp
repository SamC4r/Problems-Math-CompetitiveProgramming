#include<bits/stdc++.h>
using namespace std;

int MX = 1000;
int main(){
    freopen("paintbarn.in","r",stdin);
    freopen("paintbarn.out","w",stdout);

    int N,K;
    cin >> N >> K;
    vector<vector<int>> times_painted(MX + 1,vector<int>(MX + 1));

    for(int i = 0; i<N;i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = x1;i<x2;i++){
            times_painted[i][y1]++;
            times_painted[i][y2]--;
        }
        
    }

    // All x and y values are in the range 0…1000, and all rectangles have positive area. 
    int cont = 0;
    for(int i =0; i<=MX;i++){
        int s = 0;
        for(int j = 0;j<=MX;j++){
            s+=times_painted[i][j];
            cont += (s == K);
        }
    }
    cout << cont;


}