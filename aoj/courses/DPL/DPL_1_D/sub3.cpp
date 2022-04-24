#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1<<30;
const int MAX_N = 100001;
int dp[MAX_N]; int A[MAX_N]; int N;

int main()
{
    fill((int*)dp, (int*)dp+MAX_N, INF);
    cin >> N; rep(i, N) cin >> A[i];
    for(int n=0; n<N; n++) {
        *lower_bound(dp, dp+N, A[n]) = A[n];
    }
    printf("%d\n", lower_bound(dp, dp+N, INF) - dp);
}