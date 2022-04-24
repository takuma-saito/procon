#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const int MAX_N = 101;
const int MAX_K = 21;
ll dp[MAX_N][MAX_K]; int A[MAX_N]; int N;

int main()
{
    fill((int*)dp , (int*)dp+MAX_N*MAX_K, 0);
    cin >> N;
    rep(i, N) cin >> A[i];
    dp[1][A[0]] = 1;
    for(int i=1; i<N; i++) {
        for(int j=0; j<MAX_K; j++) {
            if (j+A[i-1]<=20) dp[i][j] += dp[i-1][j+A[i-1]];
            if (j-A[i-1]>=0)  dp[i][j] += dp[i-1][j-A[i-1]];
        }
    }
    printf("%lld\n", dp[N-1][A[N-1]]);
}