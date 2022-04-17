#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_V = 10000;
vector<int> rG[MAX_V], G[MAX_V], pord;
int used[MAX_V];

void dfs(int n) {
    if (used[n]) return;
    used[n] = 1;
    for (int u: G[n]) dfs(u);
    pord.push_back(n);
}

void rdfs(int n, int num) {
    if (used[n]) return;
    used[n] = num;
    for(int u: rG[n]) rdfs(u, num);
}

int main()
{
    int V, E; cin >> V >> E;
    rep(i, E) {
        int s, t; cin >> s >> t;
        G[s].push_back(t);
        rG[t].push_back(s);
    }
    fill(used, used+MAX_V, 0);
    rep(i, V) dfs(i);
    fill(used, used+MAX_V, 0);
    int num=1;
    for(int i=V-1; i>=0; i--) {
        if (!used[pord[i]]) rdfs(pord[i], num++);
    }
    int q; cin >> q;
    rep(i, q) {
        int u, v; cin >> u >> v;
        if (used[v] == 0 || used[u] == 0) runtime_error("wrong");
        printf("%d\n", used[u] == used[v]?1:0);
    }
}