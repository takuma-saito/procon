#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_H = 50;
const int MAX_W = 50;
int C[MAX_H][MAX_W], H, W;
pair<int, int> direction[8];

void dfs(int num, int h, int w) {
    if (h < 0 || w < 0 || h >= H || w >= W || C[h][w] != 1) return;
    C[h][w] = num;
    for(auto [dh, dw]: direction) dfs(num, h+dh, w+dw);
}

int main()
{
    int k=0;
    for(int i=-1; i<=1; i++) {
        for(int j=-1; j<=1; j++) {
            if (i==0&&j==0) continue;
            direction[k++] = {i, j};
        }
    }
    for(;;) {
        int num=2; cin >> W >> H;
        if (W==0&&H==0) break;
        rep(h, H) rep(w, W) cin >> C[h][w];
        rep(h, H) rep(w, W) if (C[h][w]==1) dfs(num++, h, w);
        printf("%d\n", num-2);
    }
}