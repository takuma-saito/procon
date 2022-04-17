#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 10000;
struct Edge {int to, cost;};
struct Node {int parent, max_cost_root, max_cost;};
typedef pair<int, int> P;
vector<Edge> G[MAX_N];
Node V[MAX_N]; // TODO: init

void dfs(int n, int parent) {
    Node node = {parent, 0};
    for(auto &e: G[n]) {
        if (e.to == parent) continue;
        dfs(e.to, n);
        node.max_cost_root = max(node.max_cost_root, V[e.to].max_cost_root + e.cost);
    }
    V[n] = node;
}

int main()
{
    int N; cin >> N;
    rep(i, N) {
        int s, t, w; cin >> s >> t >> w;
        G[s].push_back({t, w});
        G[t].push_back({s, w});
    }
    rep(i, MAX_N) V[i] = Node {-1, -1, -1};
    dfs(0, -1);
    V[0].max_cost = V[0].max_cost_root;
    queue<int> que;
    vector<P> ans;
    for(auto &e: G[0]) que.push(e.to);
    while (!que.empty()) {
        int x = que.front(); que.pop();
        int parent = V[x].parent;
        int parent_edge_cost = 0, max_cost = 0;
        for (auto &e: G[parent]) {
            if (e.to == x) {
                parent_edge_cost = e.cost;
            } else max_cost = max(max_cost, V[e.to].max_cost_root);
        }
        max_cost += parent_edge_cost;
        for (auto &e: G[x]) {
            if (V[e.to].parent == x) continue;
            max_cost = max(max_cost, V[e.to].max_cost_root);
            que.push(e.to);
        }
        V[x].max_cost = max_cost;
    }
    rep(i, N) printf("%d\n", V[i].max_cost);
}