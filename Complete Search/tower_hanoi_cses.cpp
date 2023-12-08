#include<bits/stdc++.h>
using namespace std;

int N;
int cont = 0;
string moves="";

void solve(int n, char from, char to, char aux){
    if(n == 0) return;

    //most interesting case of the recursion when there are 2 blocks to move
    solve(n - 1,from,aux,to); //move one to one place
    printf("disco %d movido desde %c hasta %c\n",n,from,to);
    cont++;
    solve(n-1,aux,to,from);// move the block below it to the auxiliary place of the previous one
}

int main(){
    int n;
    cin >> n;
    N = n;
    solve(n,'A','C','B');
    cout << cont << endl << moves;
}