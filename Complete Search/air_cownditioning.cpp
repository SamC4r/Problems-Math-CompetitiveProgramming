#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int MX = 101;
int answer = 1e9;
int N, M;

vector<int> cow_range(MX, 0);
vector<pair<int, int>> air_range;
vector<pair<int, int>> red_cost;
vector<bool> chosen;

bool valid()
{
    for (int i = 0; i < MX; i++)
    {
        if (cow_range[i] > 0)
        {
         //   cout << i << " " << cow_range[i] <<endl;
            return false;
        }
    }
    // cout << 's';
    return true;
}

void solve(int m, int total_cost)
{

    if (m==M)
    {
        if(total_cost == 0) return;
        if(valid())
            answer = min(answer, total_cost);
        return;
    }
    
    for (int i = air_range[m].first; i <= air_range[m].second; i++)
    {
        cow_range[i] -= red_cost[m].first;
    }

    solve(m + 1,total_cost + red_cost[m].second);


    for (int i = air_range[m].first; i <= air_range[m].second; i++)
    {
        cow_range[i] += red_cost[m].first;
    }
   // cout << "wea: " << red_cost[m].second << " " << total_cost << " " << endl;
    solve(m + 1 ,total_cost);// + red_cost[m].second);

// solve(m + 1, total_cost + red_cost[m].second);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N >> M;
    cow_range.resize(N);
    air_range.resize(M);
    
    red_cost.resize(M);
    chosen.resize(M);

    for (int i = 0; i < N; ++i)
    {
        int s, t, c;
        cin >> s >> t >> c;
        for (int k = s; k <= t; k++)
            cow_range[k] = c;
    }

    for (int i = 0; i < M; i++)
    {
        int a, b, p, m;
        cin >> a >> b >> p >> m;
        air_range[i] = pair<int, int>(a, b);
        red_cost[i] = pair<int, int>(p, m);
    }

    solve(0,0);

    cout << answer;
}