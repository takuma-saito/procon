#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_V = 10000;
vector<int> rG[MAX_V];
bool used[MAX_V];

void dfs(int n) {
    if (used[n]) return;
    used[n] = true;
    for(int u: rG[n]) dfs(u);
    printf("%d\n",n);
}

int main()
{
    int V, E; cin >> V >> E;
    rep(i, E) {
        int s, t; cin >> s >> t;
        rG[t].push_back(s);
    }
    fill(used, used+MAX_V, false);
    int k = 0;
    rep(i, V) if (!used[i]) dfs(i);
}