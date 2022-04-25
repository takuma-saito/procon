#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 101;
const int MAX_P = 4;
int N, K; int dp[MAX_N][MAX_P][MAX_P]; int A[MAX_N];

// f(i, a, b) = { i 日目にパスタの場合の数。b, a はそれぞれ当日、前日に選択したパスタ }
// f(i, a, b) = sum { f(i-1, x, a) | 1<=x<=3, !(a == x && a == b) } // A[i] が空
//   b == A[i] のときは 0

int main()
{
    fill((int*)dp, (int*)dp+MAX_N*MAX_P*MAX_P, 0);
    fill(A, A+MAX_N, 0);
    cin >> N >> K;
    rep(i, K) {
        int a, b; cin >> a >> b;
        A[a] = b;
    }
    if (A[1]>0&&A[2]>0) dp[2][A[1]][A[2]] = 1;
    else {
        for(int a=1; a<=3; a++) {
            if (A[1]>0) dp[2][A[1]][a] = 1;
            else if (A[2]>0) dp[2][a][A[2]] = 1;
            else {
                for(int b=1; b<=3; b++) {
                    dp[2][a][b] = 1;
                }
            }
        }
    }
    for(int i=3; i<=N; i++) {
        for(int a=1; a<=3; a++) {
            for(int b=1; b<=3; b++) {
                if (A[i]!=0&&b!=A[i]) { dp[i][a][b] = 0; continue; }
                for(int x=1; x<=3; x++) {
                    if (x == a && b == a) continue;
                    dp[i][a][b] += dp[i-1][x][a] % 10000;
                }
            }
        }
    }
    int ans=0;
    for(int a=1; a<=3; a++) {
        for(int b=1; b<=3; b++) {
            ans += dp[N][a][b];
        }
    }
    printf("%d\n", ans % 10000);
}
