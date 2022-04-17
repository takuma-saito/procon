#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_V = 100000;
const int MAX_LOG_V = 20;
vector<int> G[MAX_V];
int parents[MAX_LOG_V][MAX_V]; // TODO: init
int depth[MAX_V];
int N;

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v); // u > v
    for(int k = 0; k<MAX_LOG_V; k++) {
        if((depth[u] - depth[v]) >> k & 1) u = parents[k][u];
    }
    if (u == v) return u;
    if (depth[u] != depth[v]) runtime_error("wrong");
    while(parents[0][u] != parents[0][v]) {
        int i = MAX_LOG_V-1;
        for(; i>0; i--) if (parents[i][u] != parents[i][v]) break;
        u = parents[i][u];
        v = parents[i][v];
    }
    return parents[0][u];
}

void dfs(int n, int d) {
    if(depth[n]>=0) return;
    depth[n] = d++;
    for (auto u: G[n])  dfs(u, d);
}

int main()
{
    fill((int*)parents, (int*)parents+MAX_LOG_V*MAX_V, -1);
    fill((int*)depth, (int*)depth+MAX_V, -1);
    cin >> N;
    parents[0][0] = 0;
    rep(i, N) {
        int K; cin >> K;
        rep(j, K) {
            int x; cin >> x;
            parents[0][x] = i;
            G[i].push_back(x);
        }
    }
    dfs(0, 0);
    for(int i=1; i<MAX_LOG_V; i++) {
        for(int j=0; j<N; j++) {
            int k = parents[i-1][j];
            parents[i][j] = parents[i-1][k];
        }
    }
    int q; cin >> q;
    rep(i, q) {
        int u, v; cin >> u >> v;
        printf("%d\n", lca(u, v));
    }
}