#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1e9;
const int MAX_V = 15;
int V, E; int G[MAX_V][MAX_V]; int dp[1<<MAX_V][MAX_V];

int solve(int S, int s, int prev) {
    if (S==(1<<V)-1) return G[prev][s];
    if (dp[S][prev]>=0) return dp[S][prev];
    int ans=INF; for (int u=0; u<V; u++) {
        if (!(S>>u&1)) ans = min(ans, solve(S|(1<<u), s, u)+G[prev][u]);
    }
    return dp[S][prev] = ans;
}

int main()
{
    cin >> V >> E;
    fill((int*)G, (int*)G+MAX_V*MAX_V, INF);
    rep(u, V) G[u][u] = 0;
    rep(i, E) {
        int s, t, d; cin >> s >> t >> d;
        G[s][t] = d;
    }
    int ans=INF; rep(u, V) {
        fill((int*)dp, (int*)dp+(1<<MAX_V)*MAX_V, -1);
        ans = min(ans, solve(1<<u, u, u));
    }
    printf("%d\n", ans==INF?-1:ans);
}