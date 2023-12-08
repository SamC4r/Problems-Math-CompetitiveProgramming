#include<bits/stdc++.h>
using namespace std;

const int M = 998244353;

void solve(){
    /***
     * Beautiful set 
     * {3,6,18}
     * for every two number either one divides the other or both. 
     * Lets sort them.
     * 
     * 3, 6, 18
     * 3,9,18 --> a, a*3,a*3*2,4*3*3. UN cuantro eslo mismo que poner 2 "2" y 5 ya se excede. Es decir, se puede implementar con 2 o con 3. un por 5 se implementa con 2*2
     * 3, 6,12 --> a,a*2,a*2*2. can put 3s, 2s in combinations
     * 3,9,27 --> a,a*3,a*3*3, a*3*3*2
     * all powers will work
     * 
     * 
     * max possible size if every  following number is multiplied by 2.  2^x * first = r -> x=log2(r/l) (+ 1 due to the first number)
     * max possible size if every next number is mult by 3. y = log3(r / l)s
     * 
     * total sets: max_size
     * 
     * -number of beautiful sets
     * 
     * 
     * 
    */
    int l,r;
    cin >> l >> r;

    int max_size = log2(r / l) + 1; //this is already max size

    //two can be put in max_size -1 positions
/**
 * ACCCCCCCCCCCCCCCCCEPTED yes!. I did not remember the solution and I tried to figure it out and succeded
*/
    //2 2 2 2 --> 
    //3 3 3 3
    //2 3 2 2
    //a, 2a,22a,322a,3322a --> 2 ^ 2 ,  3^2 potencias te da 4 nuevos numeros. 
    //2^(x) = r / l --> numero de posibles 2s
    //3 ^(x) = r / l  --> numero de posibles 3s
    //2*max_size elements to place in max_size - 1 * (max_size - 1)

    int last_first = r / pow(2,max_size - 1);
    int last_first_for_2s_and_threes = r/((1 << max_size - 2) * 3);

    int total = (last_first - l + 1) + max(0,(last_first_for_2s_and_threes - l + 1)*(max_size - 1));
    total %= M;
    cout << max_size << " "  << total << endl;


}


int main(){
    int t;
    cin >> t;
    while(t--) solve();
}