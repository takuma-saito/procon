#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MAX_N 1001
int dp[MAX_N], A[MAX_N], P[MAX_N];

int main()
{
    int N, S;
    cin >> N >> S;
    rep(i, N) { cin >> A[i]; }
    rep(i, N) { cin >> P[i]; }
    dp[0] = 1;
    dp[A[0]] = 1;
    dp[P[0]] = 1;
    dp[A[0]+P[0]] = 1;
    for(int i=1; i<N; i++) {
        for(int p=S; p>=0; p--) {
            if (p-A[i]>=0) {
                dp[p] += dp[p-A[i]];
            }
            if (p-P[i]>=0) {
                dp[p] += dp[p-P[i]];
            }
            if (p-A[i]-P[i]>=0) {
                dp[p] += dp[p-A[i]-P[i]];
            }
        }
    }
    cout << dp[S] << endl;
}