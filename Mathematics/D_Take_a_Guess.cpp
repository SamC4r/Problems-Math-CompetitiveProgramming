#include<bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define forn(n) for(int i=0;i<int(n);i++)


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


int william_result(int a, int b){
    int annd,orr;
    cout << "and " << a << " " << b << endl;
    cin >> annd;
    cout << "or " << a << " " << b << endl;
    cin >> orr;

    return (annd + orr);
}

int main(){
    //setIO("");
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n,k;
    cin >> n >> k;

    int a_b = william_result(1,2);
    int a_c = william_result(1,3);
    int b_c = william_result(2,3);

    int first_pos = (a_b + a_c - b_c) /2;

    vector<int> array(n + 1);

    array[1] = first_pos;
    array[2] = a_b - first_pos;
    array[3] = a_c - first_pos;

    for(int i = 4; i<=n;i++){
        array[i] = william_result(i-1,i) - array[i-1];
    }

    sort(all(array));

    cout << "finish " << array[k] << endl;

}
