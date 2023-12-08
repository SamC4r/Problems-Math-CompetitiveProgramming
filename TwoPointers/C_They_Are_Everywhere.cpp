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



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n; cin >> n;
    string s;
    cin >> s;

    unordered_map<char,int> letters;


    unordered_set<char> diff;
    for(char c : s) diff.insert(c);

    int size = diff.size();
    int l = 0, r = 0;
    int ans = 1e9;  
    unordered_set<char> counting;

    for(int r = 0; r<n;r++){
        char c = s[r];
        letters[c]++;
        while(l < r && letters[s[l]] > 1){
            letters[s[l]]--;
            l++;
        }

        debug(letters);//will never have a non zero element!

        if((int) letters.size() == size){
            ans = min(ans, r - l + 1);
        }

        

    }    

    cout << ans;
    

}