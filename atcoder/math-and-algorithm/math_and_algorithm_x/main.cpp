#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 50;
const int MAX_Q = 200;
const int MAX_P = MAX_N*MAX_Q+1;
int N; int P[MAX_N]; int Q[MAX_N]; double dp[MAX_N+1][MAX_P] = {};

// dp[i][p] = {1 ~ i までのテストで p 点を獲得する確率} とする。
// この時 `dp[i][p] = dp[i-1][p] * (P[i]-1)/P[i] + dp[i-1][p-Q[i]]/P[i]` の漸化式が成り立つ
// 答えは `sum_{p=0}^{MAX_Q*MAX_N} dp[N][p] * p`
// 初期値は dp[0][0] = 1.0 とする

int main()
{
    cin >> N;
    rep(i, N) cin >> P[i] >> Q[i];
    dp[0][0] = 1.0;
    for(int i=1; i<=N; i++) {
        for(int p=0; p<MAX_P; p++) {
            dp[i][p] = (dp[i-1][p]/P[i-1])*(P[i-1]-1);
            if (p-Q[i-1]>=0) dp[i][p] += dp[i-1][p-Q[i-1]]/P[i-1];
        }
    }
    double ans=0; rep(p, MAX_P) {ans += dp[N][p] * p;}
    printf("%.12lf\n", ans);
}