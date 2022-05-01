#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1ll<<61;
const int MAX_N = 16;
int V, M; P G[MAX_N][MAX_N];

// v ∈ S, {最短経路,場合の数}
P solve(int S, int v, ll time) {
    if (S==(1<<V)-1 && v == 0) return {0ll,1ll};
    P res={INF,0}; for(int u=0; u<V; u++) {
        ll new_time = time+G[v][u].first;
        if (!(S>>u&1) && u!=v && G[v][u].second >= new_time) {
            auto [dist, route] = solve(S|(1<<u), u, new_time);
            ll g = dist+G[v][u].first;
            if (g == res.first) res.second += route;
            else if (g < res.first) {
                res.first = g;
                res.second = route;
            }
        }
    }
    return res;
}

int main()
{
    cin >> V >> M;
    fill((P*)G, (P*)G+MAX_N*MAX_N, P {INF, 0});
    rep(m, M) {
        ll s, t, d, time; cin >> s >> t >> d >> time;
        G[s-1][t-1] = {d, time};
        G[t-1][s-1] = {d, time};
    }
    auto [dist, route] = solve(0, 0, 0);
    dist==INF ? printf("IMPOSSIBLE\n") : printf("%lld %lld\n", dist, route);
}