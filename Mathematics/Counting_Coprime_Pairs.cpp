#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define forn(n) for (int i = 0; i < int(n); i++)
#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

// For debugging
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

const int L = 1e6 + 7;

ll divs[L];

int main()
{
    // setIO("");
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    // sieve
    vector<int> spf(L);
    // spf[1] = 1;
    for (int i = 2; i <= L; i++)
    {
        if (spf[i] == 0)
        {
            for (int j = i; j <= L; j += i)
            {
                if (spf[j] == 0)
                    spf[j] = i;
            }
        }
    }
    // debug(spf);
    int n;
    cin >> n;

    ll pairs = (ll)n * (n - 1) / 2;

    ll cnt = 0;
    for (int num = 0; num < n; num++){
        int x;
        cin >> x;

        vector<int> primes;
        primes.clear();
        while (x > 1){
            int num = spf[x];
            primes.push_back(num);
            while(x % num == 0){
                x/=num;
            }
        }

        // bit mask PIE
        // debug(primes);

        ll s = primes.size();
        for (int mask = 1; mask < (1 << s); mask++){
            int prod = 1;
            for (long k = 0; k < s; k++){
                if (mask & (1 << k)){
                    prod *= primes[k];
                }
            }
            cnt += (__builtin_popcount(mask) & 1 ? divs[prod] : -divs[prod]);//*(divs[prod]>1);
            divs[prod]++;
            // debug(xs,prod, cnt);
        }
    }
    // debug(divs);
    // cout << cnt << " " << pairs << endl;

    cout << pairs - cnt;

//     //     
// 1955198094 704982704
// -1250215390
    //int x;
    //     cin >> x;
    //     vector<int> a;
    //     a.clear();
    //     for(int i = 2; i*i <= x;i++){
    //         if(x % i == 0){
    //             divs[i]++;
    //             x/=i;
    //             // // if(divs[i] > 1) cnt+=divs[i]-1;
    //             // a.push_back(i);
    //             // if(i * i != x){
    //             //     divs[x / i]++;
    //             //     // if(divs[x / i] > 1) cnt+=divs[x/i]-1;
    //             //     a.push_back(x / i);
    //             // }
    //         }
    //     }
    //     if(x > 1)divs[x]++;
    //     // if(divs[x] > 1) cnt+=divs[x] - 1;
    //    // debug(x,a);
    // }
    // debug(divs);
}
