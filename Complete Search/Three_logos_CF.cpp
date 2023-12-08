#include<bits/stdc++.h>

using namespace std;

int x1,y1,x2,y2,x3,y3;
int square_size;
vector<vector<char>> grid;



void solve(int k){
    if(k == 3){
        //check if valid
        if(x1 + x2 >= square_size)
        return;
    }
}

int main(){

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int sum = x1*y1 + x2*y2 + x3*y3;
    int sq = sqrt(sum);
    if(sq*sq != sum){
        cout << -1;
    }else{
        square_size = sq;
        grid.resize(square_size,vector<char>(square_size));
        //generate all subset of flipped/unflipped
        solve(0,x1,y1,x2,y2,x3,y3);
    }
}