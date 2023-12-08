//HARD



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


//Segment Trees solution
/*
#include <bits/stdc++.h>
using namespace std;

struct node {
	int P, S, A, L;
} val0{0, 0, 0, 1}, val1{1, 1, 1, 1};

node operator+(const node &a, const node &b) {
	return {a.P == a.L ? a.L + b.P : a.P, b.S == b.L ? b.L + a.S : b.S,
	        max(max(a.A, b.A), a.S + b.P), a.L + b.L};
}

template <typename T, size_t N> class SegmentTree {
  private:
	T tree[4 * N], dval;
	function<T(const T &, const T &)> merge;

	void build(int t, int tl, int tr) {
		if (tl == tr) {
			tree[t] = dval;
			return;
		}
		build(t << 1, tl, (tl + tr) >> 1);
		build(t << 1 | 1, ((tl + tr) >> 1) + 1, tr);
		tree[t] = merge(tree[t << 1], tree[t << 1 | 1]);
	}

	void update(int i, T v, int t, int tl, int tr) {
		if (tl == tr) {
			tree[t] = v;
			return;
		}
		if (i <= (tl + tr) >> 1) update(i, v, t << 1, tl, (tl + tr) >> 1);
		else update(i, v, t << 1 | 1, ((tl + tr) >> 1) + 1, tr);
		tree[t] = merge(tree[t << 1], tree[t << 1 | 1]);
	}

	T query(int l, int r, int t, int tl, int tr) {
		if (r < tl || tr < l) return dval;
		if (l <= tl && tr <= r) return tree[t];
		return merge(query(l, r, t << 1, tl, (tl + tr) >> 1),
		             query(l, r, t << 1 | 1, ((tl + tr) >> 1) + 1, tr));
	}

  public:
	SegmentTree(function<T(const T &, const T &)> merge, T dval = 0)
	    : merge(merge), dval(dval) {
		build();
	}

	inline void build() { build(1, 0, N - 1); }

	inline void update(int i, T v) { update(i, v, 1, 0, N - 1); }

	inline T query(int l, int r) { return query(l, r, 1, 0, N - 1); }
};

string S;
int Q;
SegmentTree<node, 200005>
    ST0([](const node &a, const node &b) { return a + b; }, val0);
SegmentTree<node, 200005>
    ST1([](const node &a, const node &b) { return a + b; }, val0);

int main() {
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '0') {
			ST0.update(i, val1);
			ST1.update(i, val0);
		} else if (S[i] == '1') {
			ST0.update(i, val0);
			ST1.update(i, val1);
		}
	}
	cin >> Q;
	while (Q--) {
		int x;
		cin >> x;
		x--;
		if (S[x] == '0') {
			ST0.update(x, val0);
			ST1.update(x, val1);
			S[x] = '1';
		} else if (S[x] == '1') {
			ST1.update(x, val0);
			ST0.update(x, val1);
			S[x] = '0';
		}
		cout << max(ST0.query(0, S.size() - 1).A, ST1.query(0, S.size() - 1).A)
		     << ' ';
	}
}



#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()

string s;
int m;
set<int> dif;
priority_queue<int> ret;
int cnt[200005];

void ad(int x) {
	cnt[x]++;
	ret.push(x);
}
void modify(int x) {
	if (x == 0 || x == sz(s)) return;
	auto it = dif.find(x);
	if (it != end(dif)) {
		int a = *prev(it), b = *next(it);
		dif.erase(it);
		cnt[x - a]--, cnt[b - x]--;
		ad(b - a);
	} else {
		it = dif.insert(x).first;
		int a = *prev(it), b = *next(it);
		cnt[b - a]--, ad(x - a), ad(b - x);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> m;
	dif.insert(0);
	dif.insert(sz(s));
	for (int i = 0; i < sz(s) - 1; ++i) {
		if (s[i] != s[i + 1]) dif.insert(i + 1);
	}
	for (auto it = dif.begin(); next(it) != dif.end(); it++) {
		ad(*next(it) - *it);
	}

	for (int i = 0; i < m; ++i) {
		int x;
		cin >> x;
		modify(x - 1);
		modify(x);
		while (!cnt[ret.top()]) ret.pop();
		// pop elements that should no longer be present in priority queue
		cout << ret.top() << " ";
	}
}

*/





string s;
int m;
set<int> dif; //all indices i such that s_i != s_(i-1)
multiset<int> ret;

void modify(int x){
    if(x == 0 || x == s.size()) return;

    auto it = dif.find(x);

    if(it != dif.end()){
        int a = *prev(it), b = *next(it);
        ret.erase(ret.find(x - a)), ret.erase(ret.find(b - x));
        ret.insert(b - a);
        dif.erase(it);
    }else{
        it = dif.insert(x).first;
        int a = *prev(it), b = *next(it);
        ret.erase(ret.find(b - a));
        ret.insert(x - a),ret.insert(b - x);
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> s >> m;
    dif.insert(0);
    dif.insert(s.size());
    forn(s.size() - 1){
        if(s[i] != s[i + 1]) dif.insert(i + 1);
    }
	debug(dif);
    for(auto it = dif.begin(); next(it) != dif.end();it++){
        ret.insert(*next(it) - *it);
    }


    forn(m){
        int x;
        cin >> x;
        modify(x - 1);
        modify(x);
		debug(ret);
		auto it = ret.end();
		it--;
        cout << *(it) << " "; //or ret.rbegin()
    }

    //rbegin() returns a reversed iterator pointing to the last element

}