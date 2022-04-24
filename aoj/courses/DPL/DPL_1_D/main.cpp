#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1<<30;
const int MAX_N = 100001;
int dp[MAX_N][MAX_N]; int A[MAX_N]; int N;

int main()
{
    fill((int*)dp, (int*)dp+MAX_N, INF);
    cin >> N; rep(i, N) cin >> A[i];
    for(int n=1; n<=N; n++) {
        for(int k=0; k<N; k++) {
            if (k==0 || dp[n-1][k-1] < A[n]) dp[n][k] = min(dp[n-1][k], A[n]);
            else dp[n][k] = dp[n-1][k];
        }
    }
    int ans=0; for(;ans<N && dp[N][ans]!=INF; ans++);
    printf("%d\n", ans);
}