#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 10000;
struct Edge {int to, cost;};
vector<Edge> G[MAX_N];
int dist[MAX_N], dist2[MAX_N];

void dfs(int n, int parent) {
    int max_cost = 0;
    for(auto &e: G[n]) {
        if (e.to == parent) continue;
        dfs(e.to, n);
        max_cost = max(max_cost, dist[e.to] + e.cost);
    }
    dist[n] = max_cost;
}

// parent を除いた最大
int dfs2(int n, int parent, int parent_cost) {
    int max_cost = 0;
    for (auto &e1: G[n]) {
        if (e1.to == parent) continue;
        int node_cost = 0;
        for(auto &e2: G[n]) if (e2.to != e1.to && e2.to != parent) { node_cost = max(node_cost, dist[e2.to]+e2.cost); }
        max_cost = max(max_cost, dfs2(e1.to, n, node_cost+e1.cost)+e1.cost);
    }
    dist2[n] = max(max_cost, parent_cost);
    return max_cost;
}

int main()
{
    int N; cin >> N;
    rep(i, N-1) {
        int s, t, w; cin >> s >> t >> w;
        G[s].push_back({t, w});
        G[t].push_back({s, w});
    }
    dfs(0, -1);
    dfs2(0, -1, 0);
    dist2[0] = dist[0];
    rep(i, N) printf("%d\n", dist2[i]);
}
