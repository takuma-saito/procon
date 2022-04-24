#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
struct Pos {int h, w;};
const int MAX_H = 30;
const int MAX_W = 30;
int H, W; char Maze[MAX_H][MAX_W]; int Mud[MAX_H][MAX_W]; int Mlr[MAX_H][MAX_W];
int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// TRY

int solve() {
    queue<pair<Pos, int>> que;
    que.push({Pos {0, 0}, 1});
    while(!que.empty()) {
        auto [p, n] = que.front(); que.pop();
        if (p.h<0 || p.w<0 || p.h>=H || p.w>=W || Maze[p.h][p.w]!='.') continue;
        if (p.h==H-1&&p.w==W-1) return n;
        Maze[p.h][p.w] = '*';
        for(auto [dh, dw]: direction) {
            int h=p.h+dh, w=p.w+dw; Pos pos={h, w};
            if (dw==0 && !Mud[h][w]) que.push({pos, n+1});
            if (dh==0 && !Mlr[h][w]) que.push({pos, n+1});
        }
    }
    return 0;
}

int main()
{
    for(;;) {
        fill((char*)Maze, (char*)Maze+MAX_H*MAX_W, '.');
        fill((int*)Mud, (int*)Mud+MAX_H*MAX_W, 0);
        fill((int*)Mlr, (int*)Mlr+MAX_H*MAX_W, 0);
        cin >> W >> H;
        if(W==0&&H==0) break;
        rep(h, 2*H-1) {
            if (h&1) rep(w, W)   cin >> Mud[h/2+1][w]; // 上下の通り
            else     rep(w, W-1) cin >> Mlr[h/2][w+1]; // 左右の通り
        }
        printf("%d\n", solve());
    }
}