#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 100;
const int INF = 1<<30;
struct edge {int to, cost;};
vector<edge> G[MAX_N];
int d[MAX_N];
bool used[MAX_N];

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
    d[0] = 0;
    for(;;) {
        int v = -1;
        for(int u=0; u<n; u++) if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
        if (used[v]) continue;
        if (v == -1) break;
        used[v] = true;
        for (auto g: G[v]) {
            d[g.to] = min(d[g.to], g.cost + d[v]);
        }
    }
    rep(i, n) printf("%d %d\n", i, d[i]);
}