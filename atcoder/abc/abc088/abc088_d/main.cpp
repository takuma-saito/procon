#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
struct Pos {int h, w;};
const int MAX_H = 50;
const int MAX_W = 50;
int H, W, GOAL_H, GOAL_W; char C[MAX_H][MAX_W]; Pos prev_route[MAX_H][MAX_W];
int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int solve() {
    bool complete = false;
    queue<tuple<int, int, Pos>> que;
    que.push({0, 0, Pos {0, 0}});
    while (!que.empty()) {
        auto [h, w, pos] = que.front(); que.pop();
        if (h<0 || w<0 || h>=H || w>=W || C[h][w] != '.') continue;
        C[h][w] = '+'; prev_route[h][w] = pos;
        if (h==GOAL_H&&w==GOAL_W) { complete = true; break; }
        for (auto [dh, dw]: direction) que.push({h+dh, w+dw, Pos {h, w}});
    }
    if (!complete) return -1;
    C[0][0] = 'D';
    for(Pos route = {GOAL_H, GOAL_W}; !(route.h==0&&route.w==0); route = prev_route[route.h][route.w]) {
        C[route.h][route.w] = 'D';
    }
    int ans=0; rep(h, H) rep(w, W) if (C[h][w]=='+'||C[h][w]=='.') ans++;
    return ans;
}

int main()
{
    cin >> H >> W;
    rep(h, H) {
        string s; cin >> s;
        rep(w, s.size()) C[h][w] = s[w];
    }
    GOAL_H = H-1; GOAL_W = W-1;
    printf("%d\n", solve());
}