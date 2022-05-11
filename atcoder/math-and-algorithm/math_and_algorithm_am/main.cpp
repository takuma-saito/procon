#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 1e5;
int N, M; vector<int> G[MAX_N]; bool used[MAX_N];

int dfs(int n) {
    if (used[n]) return 0;
    used[n] = true;
    int res=1;
    for(int d: G[n]) res += dfs(d);
    return res;
}

int main()
{
    cin >> N >> M; rep(i, M) {
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b); G[b].push_back(a);
    }
    fill(used, used+MAX_N, false);
    printf("The graph is%sconnected.\n", dfs(0) == N ? " " : " not ");
}