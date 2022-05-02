#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;
const int INF = 1e9;
const int MAX_N = 5e3;
const int MAX_K = 1e4;
struct Edge {int to, cost;};
int N, K; int C[MAX_N]; int R[MAX_N]; vector<int> G1[MAX_N];
vector<Edge> G2[MAX_N]; bool used[MAX_N]; int dist[MAX_N];

// 幅優先探索で v から u まで行けるか全頂点で判断
// v から u まで C[v] のコストがかかるとして、ダイクストラ法を実施

void bfs(int v, int route, int cost) {
    queue<P> que;
    fill(used, used+MAX_N, false);
    que.push(P {0, v});
    while (!que.empty()) {
        auto [dist, u] = que.front(); que.pop();
        if (dist > route || used[u]) continue;
        used[u] = true;
        G2[v].push_back(Edge {u, cost});
        for (int x: G1[u]) {
            que.push({dist+1, x});
        }
    }
}
void dijkstra() {
    fill(dist, dist+MAX_N, INF);
    fill(used, used+MAX_N, false);
    priority_queue<P, vector<P>, greater<P>> pque;
    dist[0] = 0;
    pque.push(P {0, 0});
    while(!pque.empty()) {
        auto [cost, u] = pque.top(); pque.pop();
        if (used[u]) continue;
        if (u==N-1) {
            printf("%d\n", cost);
            return;
        }
        used[u] = true;
        for(auto& e: G2[u]) {
            if (dist[e.to] > dist[u] + e.cost) {
                dist[e.to] = dist[u] + e.cost;
                pque.push({dist[e.to], e.to});
            }
        }
    }
}

int main()
{
    cin >> N >> K;
    rep(i, N) cin >> C[i] >> R[i];
    rep(i, K) {
        int s, t; cin >> s >> t;
        G1[s-1].push_back(t-1);
        G1[t-1].push_back(s-1);
    }
    rep(u, N) bfs(u, R[u], C[u]);
    dijkstra();
}