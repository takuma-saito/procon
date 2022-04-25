#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 101;
const int MAX_P = 4;
const int mod = 10000;
int N, K; int dp[MAX_N][MAX_P][MAX_P]; int A[MAX_N];

int main()
{
    fill((int*)dp, (int*)dp+MAX_N*MAX_P*MAX_P, 0);
    fill(A, A+MAX_N, 0);
    cin >> N >> K;
    rep(i, K) {
        int a, b; cin >> a >> b;
        A[a] = b;
    }
    dp[0][0][0] = 1;
    for(int i=1; i<=N; i++) {
        for(int a=0; a<=3; a++) {
            for(int b=1; b<=3; b++) {
                if (A[i]!=0&&b!=A[i]) continue;
                for(int x=0; x<=3; x++) {
                    if (x == a && b == a) continue;
                    dp[i][a][b] += dp[i-1][x][a] % mod;
                }
            }
        }
    }
    int ans=0;
    for(int a=1; a<=3; a++) {
        for(int b=1; b<=3; b++) {
            ans = (ans+dp[N][a][b]) % mod;
        }
    }
    printf("%d\n", ans);
}
