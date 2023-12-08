#include <bits/stdc++.h>
using namespace std;

vector<int> cows;

bool arraySorted(int n){
    bool sorted = true;
    for (int i = 1; i <= n && sorted; i++){
        if (cows[i - 1] != i)
            sorted = false;
    }
    // for(auto a : cows){
    //     cout << a << " ";
    // }
    // cout << endl;
    return sorted;
}

int main(){

    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);

    int n;
    cin >> n;
    bool sorted = true;

    for (int i = 1; i <= n; i++){
        int cow;
        cin >> cow;
        cows.push_back(cow);
        if (cow != i){
            sorted = false;
        }
    }

    if (sorted){
        cout << "0" << endl;
        return 0;
    }

    int decreasingSubsequence = 1;

    for(int i = n - 1;i>=1;i--){
        if(cows[i] > cows[i-1]) decreasingSubsequence++;
        else break;
    }

    //cout << mx << " " << mn << endl;
    cout << n - decreasingSubsequence << endl;

}
    /* Passed all except 10,11

    int moves = 0;
    while (!arraySorted(n) && moves < 10){

        int top = cows[0];
        int positionToInsert = -1;

        if (top == 1){
            
            //first pos that is not sorted. Taking into account last element
            for(int i = n - 1; i>=0 && positionToInsert < 0;i--){
               if(cows[i-1] > cows[i]) positionToInsert = i - 1;
            }
          
        }

        if (top == n){
            positionToInsert = n - 1;
        }
        
        // search for position that is higher than top and insert it before. 

        int seek = top;
        for(int i = n - 1;i>=0;i--){
            if(cows[i] > seek){
                positionToInsert = i - 1;
                seek = min(seek,cows[i]);
            }
        }

        for (int i = 0; i < positionToInsert; i++){
            cows[i] = cows[i + 1];
        }
        cows[positionToInsert] = top;

        moves++;
    }
    
    cout << moves;
*/
    /*

        1 2 4 3
        _ _ _ _

        2 4 1 3 +1
        4 1 2 3  +1
        1 2 3 4  +1
              =  3

        1 3 2 4 5
        1 2 3 4 5

        1 3 2
        3 1 2
        1 2 3\


            5 1 3 2 4
        1 3 2 4 5
        3 1 2 4 5


        2 1 4 3

        1 3 2 4


        3 2 4 1
        2 3 4 1
        3 4 1 2
        4 1 2 3
        1 2 3 4

        one inserted after first value that is out of position
        last value inserted like the others --> after i - 1

    */
