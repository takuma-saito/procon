#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const int MAX_N = 101;
const int MAX_W = 1e5+1;
int N, W; ll dp[MAX_W] = {}; int Weight[MAX_N]; int Value[MAX_N];

// dp[n][w] = max(dp[n-1][w], dp[n-1][w-W[n]]+V[n])

int main()
{
    cin >> N >> W; rep(i, N) cin >> Weight[i] >> Value[i];
    for(int n=0; n<N; n++) {
        for(int w=W;  w>=0; w--) {
            if (w-Weight[n]>=0) dp[w] = max(dp[w], dp[w-Weight[n]]+Value[n]);
        }
    }
    printf("%lld\n", dp[W]);
}