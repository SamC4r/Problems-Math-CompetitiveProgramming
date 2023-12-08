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


// struct Customer{
//     int arr;
//     int leave;
//     friend bool operator<(const Customer &c1, const Customer &c2){
//         return c1.leave < c2.leave;
//     };
// }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<pii,int>> a(n);
    multiset<pii> ending; 
    //stores ending, room number
    vector<int> ans(n,1);

    forn(n){
        int s,e;
        cin >> s >> e;
        a[i] = {{s,e},i};
    }

    sort(all(a));
    int rooms = 0;
    forn(n){

        int customer_starting = a[i].first.first;
        int customer_ending = a[i].first.second;

        pair<int,int> top = *ending.begin();

        if(ending.empty()){
            ending.insert({customer_ending,++rooms});   
        }else if(customer_starting > top.first){
            ending.erase(ending.begin());
            ending.insert({customer_ending,top.second});
            ans[a[i].second] = top.second;
        }else{
            ending.insert({customer_ending,++rooms});
            ans[a[i].second] = rooms;
        }
    }
    cout << rooms << endl;
    forn(n) cout << ans[i] << " ";



    
/*
    forn(n){
        
    }

    vector<int> ans;
    int s = 0;
    int answ = 0;

    for(auto times : a){
        int arr = times.first;
        int leave = times.second;

        auto it = ending.lower_bound(arr);
        if(it != ending.begin()) it--;

        if(!ending.empty() && arr > *it){
            ending.erase(it);
            s--;
            ans.push_back(s);
        }

        ending.insert(leave);
        s++;
        answ = max(answ,s);
    }

    cout << answ << endl;

    for(int i = 0; i<n;i++) cout << ans[i] << " "; 


*/
}