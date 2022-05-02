#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1e9;
const int MAX_N = 3e4+1;
int N; int C[MAX_N]; int dp[MAX_N];

int main()
{
    cin >> N; rep(i, N) cin >> C[i];
    fill(dp, dp+MAX_N, INF);
    for(int i=0; i<N; i++) {
        *lower_bound(dp, dp+N, C[i]) = C[i];
    }
    int len = lower_bound(dp, dp+N, INF) - dp;
    printf("%d\n", N-len);
}