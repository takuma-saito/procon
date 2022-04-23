#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 12;
int R[MAX_N][MAX_N];

int main()
{
    fill((int*)R, (int*)R+MAX_N*MAX_N, 0);
    int N, M, ans=0; cin >> N >> M;
    rep(i, M) {
        int x, y; cin >> x >> y;
        R[x-1][y-1]++; R[y-1][x-1]++;
    }
    for(int i=1; i<(1<<N); i++) {
        bool check = true;
        for(int j=0; j<N; j++) if (1<<j&i) {
            for(int k=0; k<N; k++) if (j!=k && 1<<k&i && !R[j][k]) {
                check = false;
                break;
            }
            if (!check) break;
        }
        if (check) {
            int k=0; for(int j=0;j<N;j++) if(1<<j&i) k++;
            ans = max(ans, k);
        }
    }
    printf("%d\n", ans);
}