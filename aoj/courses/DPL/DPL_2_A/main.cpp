#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1e9;
const int MAX_V = 15;
int V, E; int G[MAX_V][MAX_V]; int dp[1<<MAX_V][MAX_V][MAX_V];

int solve(int S, int s, int t) {
    if (dp[S][s][t]!=-1) return dp[S][s][t];
    if (S==((1<<s)|(1<<t))) {
        return dp[S][s][t] = G[s][t];
    }
    int ans=INF;
    for(int u=0; u<V; u++) {
        if (S>>u&1 && u!=s && u!=t) ans = min(ans, solve(S-(1<<s), u, t) + G[s][u]);
    }
    return dp[S][s][t] = ans;
}

int main()
{
    cin >> V >> E;
    rep(u, V) rep(v, V) G[u][v] = INF;
    rep(d, 1<<V) rep(u, V) rep(v, V) dp[d][u][v] = -1;
    rep(i, E) {
        int s, t, d; cin >> s >> t >> d;
        G[s][t] = d;
    }
    int ans=INF; rep(u, V) rep(v, V) {
        if (u!=v) ans = min(ans, solve((1<<V)-1, u, v) + G[v][u]);
    }
    printf("%d\n", ans==INF?-1:ans);
}