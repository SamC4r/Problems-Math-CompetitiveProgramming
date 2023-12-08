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

const int MAX = 1e5;
vector<int> factors[MAX + 1];


//Initialise the fawctors of each number from 1 to 1e5
void init(){
    for(int i = 1; i<=MAX;i++){
        for(int j = i; j<=MAX;j+=i){
            factors[j].push_back(i);
        }
    }
}

void solve(){
    int n,m;
    cin >> n >> m;

    vector<int> a(n);
    forn(n) cin >> a[i];

    sort(all(a));

    int l = 0, r;
    int count = 0;
    vector<int> freq(m + 1,0);

    int ans = 1e9;
    
    for(r = 0; r<n;r++){
        for(auto x : factors[a[r]]){
            if(x > m) break;
            if(freq[x] == 0){ //or !freq[x]++. It first checks for a non zerop and then increments it wow!!!
                count++;
            }
            freq[x]++;
        }
        //while we have all m covered.
        while(count == m){
            int ans_c = a[r] - a[l];
            // /debug(a[r],a[l]);
            ans = min(ans,ans_c);
            //considering removing the left one to minimise sheesh.
            for(int x : factors[a[l]]){
                if(x > m) break;
                freq[x]--;
                if(freq[x] == 0){//if a removal left one topic without a proficierncy
                    count--;
                }
            }
            l++;
        }        
    }

    cout << (ans >= 1e9 ? -1 : ans) << endl;

    /**
     * 
     * sorted array (reversed)
     * 3 4 5 6 7 ---------- 1 2 3 4 5 6 7
     *                      | | | | | | |
     * answer found = 
     * 
     * 
     * 7 3 ---------------- 1 2 3 4
     * ^ ^  --------------- |   |      
     * 
     * not completely covered => -1
     * 
     * 9 7 3 2 ------------ 1 2
     *       ^              | |
     * 
     * increment l if a[l + 1] > m
     * 
     * 
     * 
     * 
    */
   



}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    int t; cin >> t;
    while(t--) solve();
}