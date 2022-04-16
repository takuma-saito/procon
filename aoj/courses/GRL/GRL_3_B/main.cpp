#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_V = 100000;
vector<int> G[MAX_V];
int ord[MAX_V], low[MAX_V], used[MAX_V];
int V, E;
typedef pair<int, int> P;
vector<P> ans;

void dfs(int parent, int n, int& d) {
    used[n] = true;
    ord[n] = d++;
    low[n] = ord[n];
    for (auto u: G[n]) {
        if (!used[u]) {
            dfs(n, u, d);
            low[n] = min(low[n], low[u]);
            if (ord[n] < low[u]) {
                n < u ? ans.push_back({n, u}) : ans.push_back({u, n});
            }
        } else if (u != parent) {
            low[n] = min(low[n], ord[u]);
        }
    }
}

int main()
{
    fill(used, used+MAX_V, false);
    cin >> V >> E;
    rep(i, E) {
        int s, t; cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    int d = 0;
    dfs(-1, 0, d);
    sort(ans.begin(), ans.end(), [](P &a, P &b){ return a.first == b.first ? a.second < b.second : a.first < b.first;});
    rep(i, ans.size()) printf("%d %d\n", ans[i].first, ans[i].second);
}