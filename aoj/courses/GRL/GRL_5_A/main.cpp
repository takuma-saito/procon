#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 100000;
struct Edge {int to, cost;};
typedef pair<int, int> P;
vector<Edge> G[MAX_N];
P Dist[MAX_N];
bool used[MAX_N];

P dfs(int n, int parent) {
    if (used[n]) return Dist[n];
    P x = {n, 0};
    used[n] = true;
    for(auto e: G[n]) {
        if (e.to == parent) continue;
        auto dn = dfs(e.to, n);
        if (x.second < dn.second + e.cost) {
            x.first = dn.first;
            x.second = dn.second + e.cost;
        }
    }
    return Dist[n] = x;
}

int main()
{
    int n; cin >> n;
    if (n==1) { printf("0\n"); return 0; }
    rep(i, n-1) {
        int s, t, w; cin >> s >> t >> w;
        G[s].push_back(Edge {t, w});
        G[t].push_back(Edge {s, w});
    }
    fill(used, used+MAX_N, 0);
    auto p = dfs(0, -1);
    fill(used, used+MAX_N, 0);
    p = dfs(p.first, -1);
    printf("%d\n", p.second);
}