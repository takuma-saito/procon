#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_S=1e5+1;
const int MAX_N=61;
int N, S; bool dp[MAX_N][MAX_S]; int A[MAX_N];

int main()
{
    cin >> N >> S; rep(i, N) cin >> A[i];
    fill((bool*)dp, (bool*)dp+MAX_S*MAX_N, false);
    dp[0][0] = true;
    for (int n=1; n<=N; n++) {
        for(int s=0; s<=S; s++) {
            int t = s-A[n-1];
            dp[n][s] = dp[n-1][s];
            if (t>=0) dp[n][s] |= dp[n-1][t];
        }
    }
    printf("%s\n", dp[N][S]?"Yes":"No");
}