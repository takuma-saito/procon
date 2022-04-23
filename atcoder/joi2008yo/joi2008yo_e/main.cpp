#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_R = 10;
const int MAX_C = 10000;
int S[MAX_R][MAX_C];
int state[1<<MAX_R];

int main()
{
    fill(state, state+(1<<MAX_R), 0);
    int R, C; cin >> R >> C;
    rep(r, R) rep(c, C) cin >> S[r][c];
    for(int c=0; c<C; c++) {
        int i=0; for(int r=0; r<R; r++) i = (i<<1) + S[r][c];
        state[i]++;
    }
    int64_t ans=0;
    for(int r=0; r<(1<<R); r++) { // ひっくり返す行 r
        int64_t sum=0;
        for (int s=0; s<(1<<R); s++) { // 状態 s
            int v = s^r;
            int cnt=0;
            for(int t: {v, ~v}) {
                int z=0; for(int g=0; g<R; g++) if ((1<<g&t)==0) z++;
                cnt = max(cnt, z);
            }
            sum += state[s] * cnt;
        }
        ans = max(sum, ans);
    }
    printf("%lld\n", ans);
}