#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int B[8][8];
int n;
int d[8][2] = {{1, -1}, {1, 0}, {1, 1}, {0, -1}, {0, 1}, {-1, -1}, {-1, 0}, {-1, 1}};

bool solve(int x, int y, int cnt) {
    int t=min(x, y);
    for(int i=1; i<8; i++) {
        for(auto [dx, dy]: d) {
            int nx = x+dx*i, ny = y+dy*i;
            if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8) continue;
            if (B[nx][ny]) return false;
        }
    }
    B[x][y]++;
    if (cnt >= 8) return true;
    rep(i, 8) {
        rep(j, 8) {
            if (B[i][j]) continue;
            B[i][j]++;
            if (solve(i, j, cnt+1)) return true;
            B[i][j]--;
        }
    }
    B[x][y]--;
    return false;
}

int main()
{
    cin >> n;
    fill((int*)B, (int*)B+8*8, 0);
    rep(i, n) {int x, y; cin >> x >> y; B[x][y]++;}
    rep(i, 8) rep(j, 8) if (solve(i, j, n)) break;
    rep(i, 8) rep(j, 8) printf("%s%s", B[i][j]?"Q":".", j==7?"\n":"");
}