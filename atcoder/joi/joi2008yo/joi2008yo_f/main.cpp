#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;
const int INF = 1e9;
const int MAX_N = 1e3;
int N, K; int dist[MAX_N]; int G[MAX_N][MAX_N];

int dijkstra(int s, int t) {
    priority_queue<P, vector<P>, greater<P>> pque;
    fill(dist, dist+MAX_N, INF);
    dist[s] = 0;
    pque.push({0, s});
    while(!pque.empty()) {
        auto [d, u] = pque.top(); pque.pop();
        if (dist[u] < d) continue;
        if (u==t) return d;
        for(int v=0; v<N; v++) {
            if (G[u][v] != INF && dist[v]>dist[u]+G[u][v]) {
                dist[v] = dist[u]+G[u][v];
                pque.push({dist[v], v});
            }
        }
    }
    return -1;
}

int main()
{
    fill((int*)G, (int*)G+MAX_N*MAX_N, INF);
    cin >> N >> K; while(K--) {
        int op; cin >> op;
        if (op==0) {
            int s, t; cin >> s >> t; s--; t--;
            cout << dijkstra(s, t) << endl;
        } else {
            int c, d, e; cin >> c >> d >> e; c--; d--;
            G[c][d] = min(G[c][d], e);
            G[d][c] = min(G[d][c], e);
        }
    }
}
