#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_V = 200001;
typedef long long ll;
vector<int> G[MAX_V];
int N, Q; ll cost[MAX_V];

void dfs(int n, int prev, ll c) {
    cost[n] += c; for(auto i: G[n]) if (i != prev) dfs(i, n, cost[n]);
}

int main()
{
    cin >> N >> Q;
    fill(cost, cost+MAX_V, 0);
    rep(i, N-1) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    rep(i, Q) {
        int p, x; cin >> p >> x;
        cost[p] += x;
    }
    dfs(1, -1, 0); for(int i=1; i<=N; i++) printf("%lld%s", cost[i], i!=N?" ":"\n");
}