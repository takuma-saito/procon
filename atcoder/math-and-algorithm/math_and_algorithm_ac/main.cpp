#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const int MAX_N = 5e5;
int N; ll dp[MAX_N+1][2] = {}; ll A[MAX_N];

// dp[n][0] = max(dp[n+1][1]+A[n], dp[n+1][0])
// dp[n][1] = dp[n+1][0]

int main()
{
    cin >> N; rep(i, N) cin >> A[i];
    for(int n=N-1; n>=0; n--) {
        dp[n][0] = max(dp[n+1][1]+A[n], dp[n+1][0]);
        dp[n][1] = dp[n+1][0];
    }
    printf("%lld\n", max(dp[0][1], dp[0][0]));
}