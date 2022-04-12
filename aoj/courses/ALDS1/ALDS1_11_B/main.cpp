#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 101;
vector<int> graph[MAX_N];
bool used[MAX_N];
int f[MAX_N], d[MAX_N];

int dfs(int n, int t) {
    if (used[n]) return f[n];
    used[n] = true;
    d[n] = t;
    for(int k: graph[n]) if (!used[k]) t = dfs(k, t+1);
    f[n] = t+1;
    return f[n];
}

int main()
{
    int n; cin >> n;
    rep(i, n) {
        int id, k; cin >> id >> k;
        rep(j, k) {int x; cin >> x; graph[id].push_back(x);}
    }
    int t = 0;
    for(int i=1; i<=n; i++) if (!used[i]) t = dfs(i, t+1);
    for(int i=1; i<=n; i++) printf("%d %d %d\n", i, d[i], f[i]);
}