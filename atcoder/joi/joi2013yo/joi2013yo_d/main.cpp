#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 2e2+1;
int D, N; int A[MAX_N]; int B[MAX_N]; int C[MAX_N]; int T[MAX_N]; int dp[MAX_N][MAX_N]; // TODO

// dp[i][j] = { 1 〜 i 日目に j の服を着ている時の派手さの最大値 }
// dp[i][j] = max { dp[i-1][k] + abs(C[k] - C[i]) | 1<=k=N, A[k]<=T[i-1]<=B[k]}

int main()
{
    cin >> D >> N;
    rep(d, D) cin >> T[d+1];
    rep(i, N) cin >> A[i] >> B[i] >> C[i];
    fill((int*)dp, (int*)dp+MAX_N*MAX_N, 0);
    for(int d=2; d<=D; d++) {
        for(int n=0; n<N; n++) {
            if (A[n] <= T[d] && T[d] <= B[n]) {
                for (int k=0; k<N; k++) {
                    if (A[k] <= T[d-1] && T[d-1] <= B[k]) {
                        dp[d][n] = max(dp[d][n], dp[d-1][k] + abs(C[k] - C[n]));
                    }
                }
            }
        }
    }
    int ans=0; for(int k=0; k<N; k++) ans = max(ans, dp[D][k]);
    printf("%d\n", ans);
}