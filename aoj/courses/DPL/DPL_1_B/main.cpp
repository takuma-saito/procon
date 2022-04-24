#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 101;
const int MAX_V = 1001;
const int MAX_W = 10001;
int dp[MAX_N][MAX_W];
int value[MAX_N]; int weight[MAX_N]; int N, W;

int main()
{
    fill((int*)dp, (int*)dp+MAX_N*MAX_W, 0);
    cin >> N >> W;
    rep(i, N) cin >> value[i+1] >> weight[i+1];
    for(int i=1; i<=N; i++) {
        for(int w=0; w<=W; w++) {
            dp[i][w] = dp[i-1][w];
            if (w-weight[i]>=0) dp[i][w] = max(dp[i][w], dp[i-1][w-weight[i]]+value[i]);
        }
    }
    printf("%d\n", dp[N][W]);
}