#include<bits/stdc++.h>

#define endl "\n"
using namespace std;

typedef long long ll;
const int mod = 6;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int a = 9;
    int b = 12;
   // for(int a = 0; a<1e9;a++){
     //   for(int b = 0; b < 1e9;b++){

           for(int n = 0; n <1e9;n++){

                int c;
                int w;
                
                if(n % 6 == 0)c= a;
                else if(n % 6 == 1)c = b;
                else if(n  % 6 == 2)c = (b - a);// << endl;
                else if(n % 6 == 3)c=-a;// << endl;
                else if(n % 6 == 4) c=-b;// << endl;
                else c=(a - b);// << endl;


              
            }
        
    
}