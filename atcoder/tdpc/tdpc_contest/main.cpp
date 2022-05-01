#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 101;
const int MAX_P = 10001;
int N; bool dp[MAX_P]; int p[MAX_P];

int main()
{
    cin >> N; rep(i, N) cin >> p[i];
    fill(dp, dp+MAX_P, false);
    dp[0] = true;
    for(int i=0; i<N; i++) {
        for(int n=MAX_P; n>0; n--) {
            if (n-p[i]>=0) dp[n] |= dp[n-p[i]];
        }
    }
    int ans=0; for(int n=0; n<=MAX_P; n++) if (dp[n]) ans++;
    printf("%d\n", ans);
}