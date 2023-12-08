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


int main(){
    //setIO("");
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;

        ll first_num = (sqrt(1 + 8 * n) + 1) /2;
        ll ans = first_num + (n - ((first_num - 1) * (first_num))/2);
        cout << (ll)ans << endl;
    }
}
    // 
    // LESS GOOO
    //int t;
    // cin >> t;
    // while(t--){
    //     int n;
    //     cin >> n;
    //     vector<int> fence(n);
    //     for(int i = 0; i<n;i++) cin >> fence[i];

    //     map<int,int> level_a;
    //     map<int,int> level_b;

    //     //level a

    //     int w = 0;
    //     int h = n;
    //     for(int i = 0; i<n;i++){
    //         // level_a.push_back({fence[i],++w});
    //         level_a[fence[i]] = ++w;
    //     }

    //     //level b
    //     reverse(all(fence));
    //     for(int i = 0; i<n;i++){
    //         level_b[h--] = fence[i];
    //     }

    //     string ans = "YES";

    //     for(auto wh : level_a){
    //         int widht_a = wh.second;
    //         int height_a = wh.first;

    //         if(level_b[height_a] != widht_a){
    //             ans = "NO";
    //         }
    //     }
    //     cout << ans << endl;



/*
6
3


b formed all a_i such that a_i-1 <= a_i
copies a_1

4 6 3
2 4 6 2 3


1 2 3

1 2 3




*/