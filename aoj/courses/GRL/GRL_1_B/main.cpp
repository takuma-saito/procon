#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int N_MAX = 1000;
const int INF = 1<<30;
struct Edge {int to, cost;};
vector<Edge> G[N_MAX];
int d[N_MAX];

int main()
{
    fill(d, d+N_MAX, INF);
    int V, E, r; cin >> V >> E >> r;
    rep(i, E) {
        int s, t, d; cin >> s >> t >> d;
        G[s].push_back(Edge {t, d});
    }
    d[r]=0;
    bool cycle=false;
    rep(i, E) {
        rep(j, V) {
            for(auto edge: G[j]) {
                if (d[j] != INF && d[edge.to] > d[j] + edge.cost) {
                    d[edge.to] = d[j] + edge.cost;
                    if (i==E-1) {
                        cycle=true;
                    }
                }
            }
        }
    }
    if (cycle) printf("NEGATIVE CYCLE\n");
    else rep(i, V) d[i] == INF ? printf("INF\n") : printf("%d\n", d[i]);
}