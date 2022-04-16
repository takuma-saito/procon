#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;
const int MAX_N = 100000;
const int INF = 1<<30;
struct Edge {int to, cost;};
vector<Edge> G[MAX_N];
int d[MAX_N];
bool used[MAX_N];

int main()
{
    priority_queue<P, vector<P>, greater<P>> que;
    int V, E, r; cin >> V >> E >> r;
    fill(d, d+MAX_N, INF);
    fill(used, used+MAX_N, false);
    rep(i, E) {
        int s, t, d; cin >> s >> t >> d;
        G[s].push_back(Edge{t, d});
    }
    que.push(P {0, r}); d[r] = 0;
    while (!que.empty()) {
        auto [cost, u] = que.top(); que.pop();
        if (used[u]) continue;
        used[u] = true;
        for(auto edge: G[u]) {
            if (d[edge.to] > d[u] + edge.cost) {
                d[edge.to] = d[u] + edge.cost;
                que.push(P {d[edge.to], edge.to});
            }
        }
    }
    rep(i, V) {
        d[i]==INF ? printf("INF\n") : printf("%d\n", d[i]);
    }
}