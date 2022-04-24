#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_H = 90;
const int MAX_W = 90;
int C[MAX_H][MAX_W]; int H, W;
int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int dfs(int h , int w) {
    if (h < 0 || h >= H || w < 0 || w >= W || C[h][w]==0) return 0;
    C[h][w] = 0;
    int ans = 0; for(auto [dh, dw]: direction) ans = max(ans, dfs(h+dh, w+dw));
    C[h][w] = 1;
    return ans+1;
}

int main()
{
    cin >> W >> H;
    rep(h, H) rep(w, W) cin >> C[h][w];
    int ans = 0; rep(h, H) rep(w, W) ans = max(ans, dfs(h, w));
    printf("%d\n", ans);
}