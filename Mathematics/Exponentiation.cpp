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

const int m = 1e9 + 7;

ll expo(ll a, ll b){
    if(b == 0) return 1;

    a %= m;

    ll tmp = expo(a,b / 2);
    tmp %= m; 
    ll res = tmp*tmp % m;
    if(b % 2){
        res *=a;
        res %= m;
    }

    return (res);


}


ll faster_expo(ll a, ll b){
    
    ll res = 1;
    while(b > 0){
        if(b & 1){
            res = res * a % m;
        }
        a = a * a % m;
        b >>=1; // b/=2;
    }   

    return res;

}







ll exponentiation(ll a, ll b){ //a ^ b
    

    if(b == 1) return a;

    a%=m;

    ll back = exponentiation(a,b/2);
    back%=m;

    ll res = back * back % m;

    if(b & 1) {
        res = res * a;
        res %= m;
    }
    return res;

}

ll exponentiation2(ll a, ll b){
    ll res =1 ;
    while(b > 0){
        if(b & 1) res = res * a;

        b >>=1;
        a = a * a ; // a^2 b/2 times 

    }

    return res;
}



int main(){
    //setIO("");
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        cout << exponentiation(a,b) << endl;
        cout << exponentiation2(a,b) << endl;
        cout << faster_expo(a,b) << endl;
    }
}


