#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_H = 1000;
const int MAX_W = 1000;
const int MAX_N = 10;
struct Pos {int h, w;};
int N, H, W; int C[MAX_H][MAX_W];
int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
Pos routes[MAX_N];

int solve(Pos p1, Pos p2) {
    rep(h, H) rep(w, W) if (C[h][w] == '*') C[h][w] = '.';
    queue<pair<Pos, int>> que;
    que.push({p1, 0});
    while (!que.empty()) {
        auto [p, n] = que.front(); que.pop();
        if (p.h < 0 || p.w < 0 || p.h >= H || p.w >= W || C[p.h][p.w] != '.') continue;
        C[p.h][p.w] = '*';
        if (p.h==p2.h&&p.w==p2.w) return n;
        for(auto [dh, dw]: direction) que.push({Pos {p.h+dh, p.w+dw}, n+1});
    }
    runtime_error("wrong route"); return -1;
}

int main()
{
    cin >> H >> W >> N;
    rep(h, H) {
        string s; cin >> s;
        rep(w, s.size()) {
            C[h][w] = s[w]=='S' ? '0' : s[w];
            if (C[h][w]!='X'&&C[h][w]!='.') {
                routes[C[h][w]-'0'] = Pos {h, w};
                C[h][w] = '.';
            }
        }
    }
    int sum=0; rep(i, N) sum += solve(routes[i], routes[i+1]);
    printf("%d\n", sum);
}