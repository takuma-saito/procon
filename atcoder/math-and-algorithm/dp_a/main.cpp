#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const int MAX_N = 1e5;
int N; int h[MAX_N+1] = {}; ll dp[MAX_N+1] = {};

// dp[n] = 足場 n の最少コスト
// dp[n] = min(dp[n-2]+abs(h[n-2]-h[n]), dp[n-1]+abs(h[n-1]-h[n]))
// dp[N] が解

int main()
{
    cin >> N; rep(i, N) cin >> h[i+1];
    dp[2] = abs(h[2]-h[1]);
    for(int n=3; n<=N; n++) {
        dp[n] = min(dp[n-2]+abs(h[n-2]-h[n]), dp[n-1]+abs(h[n-1]-h[n]));
    }
    printf("%lld\n", dp[N]);
}