#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_V = 100;
vector<int> G[MAX_V];
int used[MAX_V];
bool cycle = false;

void dfs(int n) {
    if (used[n]) {
        if(used[n]==1) cycle=true;
        return;
    }
    used[n] = 1;
    for(int u: G[n]) dfs(u);
    used[n] = 2;
}

int main()
{
    int V, E; cin >> V >> E;
    rep(i, E) {
        int s, t; cin >> s >> t;
        G[s].push_back(t);
    }
    fill(used, used+MAX_V, 0);
    rep(i, V) if (!used[i]) dfs(i);
    printf("%d\n", cycle?1:0);
}