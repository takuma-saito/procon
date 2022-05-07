#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const int V = 1e3+1;
const int K = 5+1;
const int MAX_N = 1e2;
int N; ll dp[K][V] = {}; int A[MAX_N];

int main()
{
    cin >> N; rep(i, N) cin >> A[i];
    dp[0][0] = 1;
    for (int i=0; i<N; i++) {
        for(int k=K-1; k>0; k--) {
            for(int j=V-1; j>0; j--) {
                if (j-A[i]>=0) dp[k][j] += dp[k-1][j-A[i]];
            }
        }
    }
    printf("%lld\n", dp[K-1][V-1]);
}