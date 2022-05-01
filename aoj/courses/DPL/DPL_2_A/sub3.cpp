#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1e9;
const int MAX_V = 15;
int V, E, M; int G[MAX_V][MAX_V]; int dp[1<<MAX_V][MAX_V];

int rec(int S, int v) {
    if (dp[S][v]>=0) return dp[S][v];
    if (S==(1<<V)-1 && v == 0) return dp[S][v] = 0;
    int res=INF; rep(u, V) {
        if (!(S>>u&1)) res = min(res, rec(S|(1<<u), u) + G[v][u]);
    }
    return dp[S][v] = res;
}

int main()
{
    cin >> V >> E;
    fill((int*)G, (int*)G+MAX_V*MAX_V, INF);
    fill((int*)dp, (int*)dp+(1<<MAX_V)*MAX_V, -1);
    rep(i, E) {
        int s, t, d; cin >> s >> t >> d;
        G[s][t] = d;
    }
    int ans = rec(0, 0);
    printf("%d\n", ans==INF?-1:ans);
}