#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const int MAX_N = 1e5;
int N, Q; ll A[MAX_N+1] = {};

int main()
{
    cin >> N >> Q; rep(i, N) cin >> A[i+1];
    for(int i=1; i<=N; i++) A[i] += A[i-1];
    rep(i, Q) {
        int l, r; cin >> l >> r;
        printf("%lld\n", A[r] - A[l-1]);
    }
}