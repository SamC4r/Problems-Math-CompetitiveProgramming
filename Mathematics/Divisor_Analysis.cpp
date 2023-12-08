#include<bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define forn(n) for(int i=0;i<int(n);i++)
#define endl "\n"



using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

//For debugging
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int p = 1e9 + 7;

ll expo(ll a, ll b, ll mod){
    ll res = 1;
    while(b > 0){
        if(b & 1) res = res * a  % mod;
        a = a* a % mod;
        b >>= 1;
    }
    return res;
}

int modInv(int a){
    return expo(a,p - 2,p);
}


int main(){
    //setIO("");
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<ll,ll>> factors;
    ll number = 1;
    ll num2 = 1;
    for(int i = 0; i<n;i++){
        ll a, b;
        cin >> a >> b;
        factors.push_back({a,b});
        number *= (b + 1);
        num2 *= (b + 1);
        num2 %= (p - 1);
        number %= p;
    }   

    ll sum = 1;

    for(auto fact : factors){
        sum = sum * ((expo(fact.first,fact.second + 1,p) - 1)  * modInv(fact.first - 1) % p) % p ;
    }

    ll prod = 1;

    for(auto fact : factors){
        
        ll bef = ((fact.second  * num2)/2) % (p-1);

        
        //cout << bef << endl;
        prod = prod % p * expo(fact.first,bef % (p-1),p);
        prod %= p;
    }




//     ll prod = 1;
//     int xd = 0;
//     ll num1=1;
//     for(auto &[a,b] : factors){     
//         if(b % 2 == 1 && xd == 0){
//             num1 *= (b +1)/2;
//             num1 %= (p-1);
//             xd = 1;
//         }else{
//             num1*=(b + 1);
//             num1 %= (p-1);
//         }     
//    }
//     if(xd==0){
//         for(auto &[a,b]: factors) b /= 2;
//     }

//     ll orig = 1;
//     // debug(factors);
//     for(auto i : factors){
//         orig *= expo(i.first,i.second,p);
//         orig %= p;
//     }
//     prod = expo(orig,num1,p);
//     prod %= p;
     cout << number << " " << sum << " " << prod << endl;
    

}
