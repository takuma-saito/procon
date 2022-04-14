#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int B[8][8];
int n;

bool solve(int x, int y, int cnt) {
    int t=min(x, y);
    rep(i, 8) {
        int u = x-t+i, v = y-t+i;
        if (u==x&&v==y) continue;
        if (u<8 && v<8 && B[u][v]) return false;
        if ((i != x && B[i][y]) || (i != y && B[x][i])) return false;
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