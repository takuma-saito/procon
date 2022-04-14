#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 10000;
const int MAX_N = 100;
int G[MAX_N][MAX_N];
bool used[MAX_N];
int mincost[MAX_N];
typedef pair<int, int> P;

int main()
{
    fill(used, used+MAX_N, 0);
    fill(mincost, mincost+MAX_N, INF);
    int init, n; cin >> n;
    rep(i, n) rep(j, n) {
        cin >> G[i][j];
        if (i != -1 && j != -1) init = i;
    }
    priority_queue<P, vector<P>, std::greater<P>> pq;
    int ans = 0;
    pq.push({0, init});
    while(!pq.empty()) {
        auto [t, i] = pq.top(); pq.pop();
        if (used[i]) continue;
        ans += t; used[i]=true;
        for(int v=0; v<n; v++) {
            if (G[i][v] == -1) continue;
            int m = mincost[v] = min(mincost[v], G[i][v]);
            pq.push({m, v});
        }
    }
    cout << ans << endl;
}