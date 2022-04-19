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

void dfs2(int n, int parent, int parent_cost) {
    vector<int> vec;
    for (auto &e: G[n]) {
        if (e.to == parent) vec.push_back(dist[e.to]+parent_cost);
        else vec.push_back(dist[e.to]+e.cost);
    }
    sort(vec.begin(), vec.end(), greater<int>{});
    dist2[n] = vec[0];
    for(auto &e: G[n]) if (e.to != parent) dfs2(e.to, n, vec[dist[e.to]+e.cost==vec[0]]);
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
    rep(i, N) printf("%d\n", dist2[i]);
}
