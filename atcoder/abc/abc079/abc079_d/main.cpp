#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1e9;
typedef pair<int, int> P;
const int N = 10;
int W, H; int costs[N]; int freq[N]; int C[N][N];

// 数字 i の頻度分布を freq[i] で表す
// 数字 i を数字 1 に変換するための最少コストを dp[i] とした時に、sum { dp[i]*freq[i] | 0<=i<=9 } が答えになる
// dp[i] の求め方は次の通り。数字を頂点、数字 i から数字 j までの辺として C[i][j] を貼ったグラフを考える
// このグラフに対して、数字 1 から i までダイクストラ法を適用すればよい

void dijkstra(int n) {
    priority_queue<P, vector<P>, greater<P>> pque;
    fill(costs, costs+N, INF);
    costs[n] = 0;
    pque.push({0, n});
    while(!pque.empty()) {
        auto [cost, u] = pque.top(); pque.pop();
        if (costs[u] < cost) continue;
        for(int v=0; v<N; v++) {
            if (costs[v] > costs[u]+C[v][u]) {
                costs[v] = costs[u]+C[v][u];
                pque.push({costs[v], v});
            }
        }
    }
}

int main()
{
    fill(freq, freq+N, 0);
    int H, W; cin >> H >> W;
    rep(i, N) rep(j, N) cin >> C[i][j];
    rep(h, H) rep(w, W) {
        int digit; cin >> digit;
        if (digit!=-1) freq[digit]++;
    }
    dijkstra(1);
    int sum=0; rep(i, N) sum += costs[i] * freq[i];
    printf("%d\n", sum);
}