#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 10000;
struct Edge {int to, cost;};
vector<Edge> G[MAX_N];
bool used[MAX_N];
typedef pair<int, int> P;

int main()
{
    fill(used, used+MAX_N, false);
    int V, E; cin >> V >> E;
    rep(i, E) {
        int s, t, d; cin >> s >> t >> d;
        G[s].push_back(Edge{t, d});
        G[t].push_back(Edge{s, d});
    }
    priority_queue<P, vector<P>, greater<P>> que;
    que.push({0, 0});
    int64_t ans=0;
    while(!que.empty()) {
        auto [cost, u] = que.top(); que.pop();
        if (used[u]) continue;
        used[u] = true;
        ans += cost;
        for (auto e: G[u]) que.push({e.cost, e.to});
    }
    printf("%d\n", ans);
}