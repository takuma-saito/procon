#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 10000;
const int INF = 1<<30;
struct edge {int to, cost;};
vector<edge> G[MAX_N];
int d[MAX_N];
bool used[MAX_N];
typedef pair<int, int> P;

int main()
{
    fill(d, d+MAX_N, INF);
    fill(used, used+MAX_N, false);
    int n; cin >> n;
    rep(i, n) {
        int u, k; cin >> u >> k; 
        rep(j, k) {
            int c, v; cin >> v >> c;
            G[u].push_back({v, c});
        }
    }
    priority_queue<P, vector<P>, greater<P>> pq;
    d[0] = 0;
    pq.push({0, 0});
    while(!pq.empty()) {
        auto [cost, v] = pq.top(); pq.pop();
        if (used[v]) continue;
        used[v] = true; d[v] = cost;
        for(auto &g: G[v]) {
            if (g.cost + d[v] < d[g.to]) {
                d[g.to] = g.cost + d[v];
                pq.push({d[g.to], g.to});
            }
        }
    }
    rep(i, n) printf("%d %d\n", i, d[i]);
}