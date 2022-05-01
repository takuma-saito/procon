#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1ll<<61;
const int MAX_N = 16;
int V, M; P G[MAX_N][MAX_N]; P dp[1<<MAX_N][MAX_N];

// v ∈ S, {最短経路,場合の数}
P solve(int S, int v) {
    if (dp[S][v].first>=0) return dp[S][v];
    if (S==(1<<V)-1 && v==0) return dp[S][v] = {0,1};
    P res={INF,0}; for(int u=0; u<V; u++) {
        if (S>>u&1 || u==v) continue;
        auto [dist, route] = solve(S|(1<<u), u);
        ll now = dist+G[v][u].first;
        if (G[v][u].second < now) continue;
        if (now == res.first) res.second += route;
        else if (now < res.first) {
            res.first = now;
            res.second = route;
        }
    }
    return dp[S][v] = res;
}

int main()
{
    cin >> V >> M;
    fill((P*)G, (P*)G+MAX_N*MAX_N, P {INF, 0});
    fill((P*)dp, (P*)dp+(1<<MAX_N)*MAX_N, P {-1, 0});
    rep(m, M) {
        ll s, t, d, time; cin >> s >> t >> d >> time;
        G[s-1][t-1] = {d, time};
        G[t-1][s-1] = {d, time};
    }
    auto [dist, route] = solve(0, 0);
    dist==INF ? printf("IMPOSSIBLE\n") : printf("%lld %lld\n", dist, route);
}