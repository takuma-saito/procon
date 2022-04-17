#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 201;
vector<int> G[MAX_N];
int match[MAX_N];
bool used[MAX_N];

// 増加パスを探す
bool dfs(int n) {
    used[n] = true;
    for (auto u: G[n]) {
        int w = match[u];
        if (w < 0 || !used[w] && dfs(w)) {
            match[n] = u;
            match[u] = n;
            return true;
        }
    }
    return false;
}

int main()
{
    int X, Y, E; cin >> X >> Y >> E;
    rep(i, E) {
        int x, y; cin >> x >> y;
        int s=2*x, t=2*y+1;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    int ans=0;
    fill(match, match+MAX_N, -1);
    rep(i, X) {
        fill(used, used+MAX_N, false);
        if (dfs(i*2)) ans++;
    }
    printf("%d\n", ans);
}