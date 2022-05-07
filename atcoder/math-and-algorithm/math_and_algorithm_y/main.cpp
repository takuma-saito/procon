#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 2e5;
const int MAX_S = 24;
const int MAX_P = MAX_S * MAX_N;
int N; double dp[MAX_P+1] = {}; int A[MAX_N]; int B[MAX_N];

// dp[i][p] = {1 ~ i 日で p 時間勉強する確率}
// この場合次の漸化式が成り立つ `dp[i][p] = dp[i-1][p-A[i]]/3 + dp[i-1][p-B[i]]*2/3`
// 期待値: sum_{p=0}^{MAX_N*24} dp[N][p] * p
// 初期値 dp[0][0] = 1.0 とする
// dp(p) = dp(p-A[i])/3 + dp(p-B[i])/3

int main()
{
    cin >> N;
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    dp[0] = 1.0;
    for(int i=0; i<N; i++) {
        for(int p=(i+1)*MAX_S; p>=0; p--) {
            dp[p] = 0;
            if (p-A[i]>=0) dp[p] += dp[p-A[i]]/3;
            if (p-B[i]>=0) dp[p] += dp[p-B[i]]*2/3;
        }
    }
    double ans=0; for(int p=0; p<=MAX_P; p++) ans += dp[p] * p;
    printf("%.12lf", ans);
}