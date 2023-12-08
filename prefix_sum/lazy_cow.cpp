//very difficult
#include<bits/stdc++.h>
#define int long long
using namespace std;

int mx = 400;

signed main(){
    freopen("lazy.in","r",stdin);
    freopen("lazy.out","w",stdout);

    int N,k;
    cin >> N >> k;
    int new_n = 2*N - 1;

    vector<vector<int>> grid(new_n,vector<int>(new_n));

    //read input and store it rotated by 45 degrees

    for(int i = 0; i<N;i++){
        for(int j = 0; j<N;j++){
            cin >> grid[i + j][N - i + j - 1];
        }
    }

    // for(auto a : grid){
    //     for(auto b : a) cout << b << " ";
    //     cout << endl;
    // }

    vector<vector<int>> ps(mx + 1, vector<int>(mx + 1));

    for(int i =1;i<=new_n;i++){
        for(int j = 1; j<=new_n;j++){
            ps[i][j] = grid[i-1][j-1] + ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
        }
    }
    int mx = 0;

     for(int i =1;i<new_n-k;i++){
        for(int j = 1; j<new_n-k;j++){
            int p = (ps[i-1][j-1] + ps[i + 2*k][j + 2*k]) - (ps[i+2*k][j-1] + ps[i-1][j+2*k]);
            //cout << p << endl;
            mx = max(mx,p);
        }
    }


    cout << mx;

  





}