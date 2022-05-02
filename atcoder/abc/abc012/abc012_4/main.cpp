#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1e9;
const int MAX_N = 300;
int N, M; int G[MAX_N][MAX_N];

// 1. 出発するバス停 u を固定した時に、最長のバス停 v までの距離を longest[u] で表す
// 2. longest[u] が最少になるような u を選択すればよい
// 1 の計算にはワーシャルフロイド法、2 は線形探索でそれぞれ探す

int main()
{
    cin >> N >> M;
    fill((int*)G, (int*)G+MAX_N*MAX_N, INF);
    rep(i, N) G[i][i] = 0;
    rep(i, M) {
        int a, b, t; cin >> a >> b >> t; a--; b--;
        G[a][b] = t;
        G[b][a] = t;
    }
    for(int k=0; k<N; k++) {
        for(int u=0; u<N; u++) {
            for (int v=0; v<N; v++) {
                G[u][v] = min(G[u][v], G[u][k]+G[k][v]);
            }
        }
    }
    int ans=INF; rep(u, N) {
        int longest=0;
        rep(v, N) {
            longest = max(longest, G[u][v]);
        }
        ans = min(ans, longest);
    }
    printf("%d\n", ans);
}