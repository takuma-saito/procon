#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 301;
int N; int dp[MAX_N][MAX_N]; int W[MAX_N];

int solve(int l, int r) {
    if (dp[l][r]>=0) return dp[l][r];
    if (r-l<=1) return dp[l][r] = 0;
    int ans = solve(l+1, r-1)==(r-l-2) ? (r-l-2+2*(abs(W[l]-W[r-1])<=1)):0;
    for(int k=l+1; k<r; k++) ans = max(ans, solve(l, k)+solve(k, r));
    return dp[l][r] = ans;
}

int main()
{
    for(;;) {
        cin >> N; if(!N) break;
        rep(i, N) cin >> W[i];
        fill((int*)dp, (int*)dp+MAX_N*MAX_N, -1);
        printf("%d\n", solve(0, N));
    }
}