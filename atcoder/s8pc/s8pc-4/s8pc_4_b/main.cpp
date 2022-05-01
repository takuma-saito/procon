#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 15;
const int64_t INF = (1ll<<62)-1;
int A[MAX_N];
int N, K; 

int64_t solve(int curr, int height, int k) {
    if (k==0) return 0;
    if (curr>=N) return INF;
    if (A[curr] > height) return solve(curr+1, A[curr], k-1);
    else {
        int64_t v1 = solve(curr+1, height+1, k-1) + height-A[curr]+1;
        int64_t v2 = solve(curr+1, height, k);
        return min(v1, v2);
    }
}

int main()
{
    int64_t ans = (1ul<<63)-1;
    cin >> N >> K;
    rep(i, N) cin >> A[i];
    printf("%lld\n", solve(1, A[0], K-1));
}