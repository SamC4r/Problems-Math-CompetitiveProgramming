//Hard 2600



#include<bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define forn(n) for(int i=0;i<int(n);i++)
#define endl "\n"



using namespace std;

typedef long long ll;

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

const int mod = 1e9 + 7;

ll ans = 0;
int rl= 0;

ll binpow(ll a, int x){
    ll ans0 = 1;
    while(x){
        if(x % 2){
            ans0 *= a;
            ans0 %= mod;
        }
        a*=a;
        a%=mod;
        x/=2;
    }
    return ans0;
}

void norm(vector<int> &b){//substract for each position the minimum element
    int mn = b[0];
    ans += (int) ((ll) mn * binpow(2, rl - 1) % mod);
    if(ans >= mod) ans -= mod;
    for(auto &x : b){
        x -= mn;
    }
}


void F(vector<int> &b, int sub = 0){
    --rl;
    vector<int> cnd;
    for(int i = 0; i < (int) b.size();i++){
        for(int j = i + 1; j < (int)b.size();j++){
            if(i*j >= (int) b.size()) break;
            cnd.push_back(b[i] + b[j]);
        }
    }
    sort(all(cnd));
    vector<int> b2((int) b.size() - sub);
    for(int i = 0; i<(int)b.size() - sub;i++){
        b2[i] = cnd[i];
    }
    norm(b2);
    b = b2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n; 
    cin >> n;

    vector<int> a(n);

    forn(n) cin >> a[i];

    sort(all(a));

    int K = 64;

    vector<int> b(min(n,K));

    for (int i = 0; i < min(n, K); i++) {
        b[i] = a[i];
    }
    rl = n;

    norm(b);
    while((int) b.size() < rl){
        if(b[1] + b[2] > b.back()){
           F(b,1);
           F(b,1);
        }else{
            F(b);
        }
    }
    while(rl > 1){
        F(b,1);
    }
    ans+=b[0];
    ans %= mod;
    cout << ans << endl;

    
}