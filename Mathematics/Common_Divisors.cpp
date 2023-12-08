#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 1;

int gcds[MAX + 1];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i = 0; i<n;i++){
        int x; cin >> x;
        gcds[x]++;
    }

    for(int k = MAX;k>=1;k--){
        int cnt = 0;
        int mult = 1;
        while(k * mult <= MAX){
            cnt += gcds[k*mult];
            mult++;
        }
        if(cnt > 1){
            cout << k;
            break;
        }
    }


}

























// #include<bits/stdc++.h>

// using namespace std;

// const int MAX = 1e6;

// int gcds[MAX + 1];

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(NULL);
//     int n;
//     cin >> n;

//     for(int i = 0; i<n;i++){
//         int x;
//         cin >> x;
//         gcds[x]++;
//         for(int f = 2; f*f <= x;f++){
//             if(x % f == 0){
//                 gcds[f]++;
//                 if(f != x / f) gcds[x / f]++;
//             }
//         }

//     }


//     int sol = 0;
//     for(int i = MAX; i>=1;i--){
//         if(gcds[i] > 1){
//             sol = i;
//             break;
//         }
//     }
//     cout << sol;

// }