#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 101;
vector<int> graph[MAX_N];
int used[MAX_N];

int main()
{
    fill(used, used+MAX_N, -1);
    queue<pair<int, int>> que;
    int n; cin >> n;
    rep(i, n) {
        int id, k; cin >> id >> k;
        rep(j, k) {int x; cin >> x; graph[id].push_back(x);}
    }
    que.push({1, 0});
    while(!que.empty()) {
        auto [x, t] = que.front(); que.pop();
        if (used[x]>=0) continue;
        used[x] = t;
        for(auto a: graph[x]) {
            que.push({a, t+1});
        }
    }
    for(int i=1; i<=n; i++) printf("%d %d\n", i, used[i]);
}