#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const int MAX_R = 21;
ll dp[MAX_R] = {};
// dp(n, r) = dp(n-1, r-1) + dp(n-1, r);
// dp(r) = dp'(r-1) + dp'(r);
// dp(r) += dp(r-1) // 上から下

int main()
{
    int N, R; cin >> N >> R;
    dp[0] = 1;
    for(int n=1; n<=N; n++) {
        for(int r=R; r>0; r--) {
            dp[r] += dp[r-1];
        }
    }
    printf("%lld\n", dp[R]);
}