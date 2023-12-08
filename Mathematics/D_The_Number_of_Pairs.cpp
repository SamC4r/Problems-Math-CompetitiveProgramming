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

const int L = 2e7 + 7;


int main(){
    //setIO("");
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;

    vector<int> spf(L + 1,-1);
    vector<int> prime_divisors(L + 1);

    spf[1] = 1;

    for(int i = 2;i<=L;i++){
        if(spf[i] == -1){
            for(int j = i; j<=L;j+=i){
                if(spf[j] == -1){
                    spf[j] = i;
                }
            }
        }
    }

    for(int i = 2; i<=L;i++){
        int a = i / spf[i];
        prime_divisors[i] = prime_divisors[a] + (spf[a] != spf[i]); 
    }
   // debug(prime_divisors);





    while(t--){
        int c,d,x;
        cin >> c >> d >> x;

        int ans = 0;
        for(int g = 1; g*g <= x;g++){
            if(x % g == 0){
                
                // x / g and g are divisors of x
                int rhs = x/g + d;

                if(rhs % c == 0){
                    int m = rhs/c;
                    ans += (1 << prime_divisors[m]); 
                }

                if(g * g != x){
                    int m = (g + d);
                    if(m % c == 0)ans += (1 << prime_divisors[m/c]);
                }
            }
        }
        cout << ans << endl;
        
    }
}
