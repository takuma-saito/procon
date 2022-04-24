#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = (1<<30);
const int MAX_N = 50001;
const int MAX_M = 21;
int N, M; int dp[MAX_N][MAX_M]; int C[MAX_M];

int main()
{
    fill((int*)dp, (int*)dp+MAX_N*MAX_M, INF);
    cin >> N >> M;
    rep(i, M) cin >> C[i+1];
    dp[0][0]=0;
    for (int m=1; m<=M; m++) {
        for (int n=0; n<=N; n++) {
            dp[n][m] = dp[n][m-1];
            if (n-C[m]>=0) dp[n][m] = min(dp[n][m], dp[n-C[m]][m]+1);
        }
    }
    printf("%d\n", dp[N][M]);
}