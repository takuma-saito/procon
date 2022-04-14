#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 100000;
vector<int> graph[MAX_N];
int used[MAX_N];

void dfs(int n, int t) {
    used[n] = t;
    for(int x: graph[n]) if (!used[x]) dfs(x, t);
}

int main()
{
    int n, m; cin >> n >> m;
    fill(used, used+MAX_N, 0);
    rep(i, m) {
        int x, y; cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int t=1; rep(i, n) if (!used[i]) dfs(i, t++);
    int q; cin >> q;
    rep(i, q) {
        int x, y; cin >> x >> y;
        printf("%s\n", used[x] == used[y] ? "yes" : "no");
    }
}