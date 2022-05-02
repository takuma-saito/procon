#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const ll INF = 1l<<60;
const int MAX_N = 1e5;
typedef pair<ll, int> Pair;
int N, Q, P, K, M, S; vector<int> zombie;
int risk_town[MAX_N] = {}; vector<int> G[MAX_N]; bool used[MAX_N]; ll cost[MAX_N];

// メモ：無向グラフ、町1から町N
// 1. ゾンビのいる町から幅優先探索で危険な町をチェック。（※ この時点で町 i が Q 円か P 円かの判断が可能）
// 2. 町と町の間をつなぐグラフと 1 で計算した宿泊料金の情報を使って、町1から町Nまで到達した場合の最少コストをダイクストラ法で判断

void bfs() {
    fill(used, used+MAX_N, false);
    queue<Pair> que;
    for(auto zu: zombie) {
        risk_town[zu] = S+1;
        que.push({S+1, zu});
    }
    while (!que.empty()) {
        auto [route, u] = que.front(); que.pop();
        if (used[u] || route<=0) continue;
        used[u] = true;
        risk_town[u] = route;
        for(int v: G[u]) que.push({route-1, v});
    }
}

void dijkstra() {
    fill(used, used+MAX_N, false);
    fill(cost, cost+MAX_N, INF);
    priority_queue<Pair, vector<Pair>, greater<Pair>> pque;
    cost[0] = 0;
    pque.push({0, 0});
    while (!pque.empty()) {
        auto [c, u] = pque.top(); pque.pop();
        if (used[u]||risk_town[u]==S+1) continue;
        used[u] = true;
        ll cost_town = risk_town[u]>0 ? Q : P;
        if (u==0) cost_town=0;
        for(int v: G[u]) {
            if (cost[v] > cost[u]+cost_town) {
                cost[v] = cost[u]+cost_town;
                pque.push({cost[v], v});
            }
        }
    }
}

int main()
{
    cin >> N >> M >> K >> S >> P >> Q;
    rep(i, K) { int x; cin >> x; zombie.push_back(x-1); }
    rep(i, M) {
        int s, t; cin >> s >> t;
        G[s-1].push_back(t-1);
        G[t-1].push_back(s-1);
    }
    bfs();
    dijkstra();
    cout << cost[N-1] << endl;
}