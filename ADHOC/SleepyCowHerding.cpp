#include<bits/stdc++.h>

#define endl '\n'

using namespace std;


int main(){
    //freopen("herding.in", "r", stdin);
	//freopen("herding.out", "w", stdout);

    
    vector<int> cows(3);
    
    for(int i = 0; i<3;i++)
        cin >> cows[i];
     
    sort(cows.begin(),cows.end()); 

    int first_abs = abs(cows[0]-cows[1]) - 1;
    int second_abs = abs(cows[2] - cows[1]) - 1;
    
    if(first_abs == 0 && second_abs  == 0) cout << "0" << endl;
    else if (first_abs == 1 || second_abs == 1) cout << "1" << endl;
    else cout << "2" << endl;

    
    cout << max(first_abs, second_abs) << endl;



    /*
        4 (5,6) 7 (8) 9

        1. can only move endpoints
        2. new move has to be within the endpoints.
        3. always only three

        4 --> 8
        
        7 8 9

        res = abs(7 - 9) = 2;
        if(res > 1) there is a spot in there
        if(res == 3) there are 2 spots
        if(res == n) there are n - 1 spots

        for the case of the minumum moves, insert it in the position where res is the minimum provided that it is > 1.
        


        abs(7 - 4) = 3;

        6 11 21
        6 (4) 11 (9) 21
        for the miniomum it can only be 1 or 2. 

        1 if some abs() is 1. 2 Otherwise

        1 2 5 --> 1
        1 90 123 --> 2


        in the case of the maximum just return the max of both absolute values. 




    */

}