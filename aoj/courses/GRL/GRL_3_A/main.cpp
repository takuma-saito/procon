#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_V = 100000;
vector<int> G[MAX_V];
int ord[MAX_V], low[MAX_V], used[MAX_V];
int V, E;
vector<int> ans;

void dfs(int parent, int n, int& d) {
    int children = 0;
    used[n] = true;
    ord[n] = d++;
    low[n] = ord[n];
    bool is_articulation = false;
    for (auto u: G[n]) {
        if (!used[u]) {
            children++;
            dfs(n, u, d);
            low[n] = min(low[n], low[u]);
            is_articulation |= parent!=-1 && ord[n] <= low[u];
        } else if (u != parent) {
            low[n] = min(low[n], ord[u]);
        }
    }
    is_articulation |= (parent==-1 && children > 1);
    if (is_articulation) ans.push_back(n);
    //printf("%d %d %d\n", n, ord[n], low[n]);
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
    sort(ans.begin(), ans.end());
    rep(i, ans.size()) printf("%d\n", ans[i]);
}