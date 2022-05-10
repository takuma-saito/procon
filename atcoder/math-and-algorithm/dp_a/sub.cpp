#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const int INF = 1<<30;
const int MAX_N = 1e5;
int N; int h[MAX_N+2]; ll dp[MAX_N+2] = {};

// dp[n] = 足場 n の最少コスト
// dp[n] = min(dp[n-2]+abs(h[n-2]-h[n]), dp[n-1]+abs(h[n-1]-h[n]))
// dp[N] が解

int main()
{
    fill(dp, dp+MAX_N+1, INF);
    cin >> N; rep(i, N) cin >> h[i+1];
    dp[0] = 0; dp[1] = 0;
    for(int n=1; n<N; n++) {
        dp[n+2] = min(dp[n]+abs(h[n+2]-h[n]), dp[n+2]);
        dp[n+1] = min(dp[n]+abs(h[n+1]-h[n]), dp[n+1]);
    }
    printf("%lld\n", dp[N]);
}