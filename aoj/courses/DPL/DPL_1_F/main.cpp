#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const ll INF = (1ll<<62)-1;
const int MAX_V = 10001;
const int MAX_N = 101;
ll dp[MAX_N][MAX_V]; int value[MAX_N]; ll weight[MAX_N];
int N; ll W;

int main()
{
    fill((ll*)dp, (ll*)dp+MAX_N*MAX_V, INF);
    cin >> N >> W;
    rep(i, N) cin >> value[i] >> weight[i];
    dp[0][0]=0;
    for(int n=1; n<=N; n++) {
        for(int v=0; v<MAX_V; v++) {
            if (value[n-1] > v) {
                dp[n][v] = dp[n-1][v];
            } else  {
                dp[n][v] = min(dp[n-1][v-value[n-1]]+weight[n-1], dp[n-1][v]);
            }
        }
    }
    ll ans=0; for(int v=0; v<MAX_V; v++) if (dp[N][v] <= W) ans=v;
    printf("%lld\n", ans);
}