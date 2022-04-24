#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 101;
const int MAX_W = 10001;
int dp[MAX_N][MAX_W]; int N, W;
int value[MAX_N]; int weight[MAX_N]; int ulimit[MAX_N];

// TRY
// dp[n][w] = {n 番目までで w を作る際に余る最大の n 番目の個数 }

int main()
{
    fill((int*)dp, (int*)dp+MAX_N*MAX_W, 0);
    cin >> N >> W;
    rep(i, N) cin >> value[i] >> weight[i] >> ulimit[i];
    for (int n=1; n<=N; n++) {
        for (int w=0; w<=W; w++) {
            for (int k=0; k<=ulimit[n-1]; k++) {
                int _w = w-k*weight[n-1];
                if (_w>=0) dp[n][w] = max(dp[n][w], dp[n-1][_w]+value[n-1]*k);
            }
        }
    }
    printf("%d\n", dp[N][W]);
}