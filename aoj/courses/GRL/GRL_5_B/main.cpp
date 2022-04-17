#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 10000;
struct Edge {int to, cost;};
struct Node {int parent, max_cost, parent_edge_cost;};
typedef pair<int, int> P;
vector<Edge> G[MAX_N];
Node V[MAX_N];

void dfs(int n, int parent, int parent_edge_cost) {
    Node node = {parent, 0, parent_edge_cost};
    for(auto &e: G[n]) {
        if (e.to == parent) continue;
        dfs(e.to, n, e.cost);
        node.max_cost = max(node.max_cost, V[e.to].max_cost + e.cost);
    }
    V[n] = node;
}

int dfs2(int n, int from) {
    int m = 0;
    int parent = V[n].parent;
    for (auto &e: G[n]) {
        if (e.to != parent && e.to != from) m = max(m, V[e.to].max_cost+e.cost);
    }
    int val = max(m, parent!=-1 ? (dfs2(parent, n) + V[n].parent_edge_cost) : 0);
    return val;
}

int main()
{
    int N; cin >> N;
    rep(i, N-1) {
        int s, t, w; cin >> s >> t >> w;
        G[s].push_back({t, w});
        G[t].push_back({s, w});
    }
    dfs(0, -1, 0);
    printf("%d\n", V[0].max_cost);
    for (int i=1; i<N; i++) printf("%d\n", dfs2(i, -1));
}