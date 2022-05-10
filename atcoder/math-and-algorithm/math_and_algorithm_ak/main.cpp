#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const int MAX_N = 2e5+1;
int N, M; ll A[MAX_N] = {}; int B[MAX_N];

int main()
{
    cin >> N; rep(i, N-1) cin >> A[i+1];
    cin >> M; rep(i, M) {
        int b; cin >> b; B[i] = --b;
    }
    for(int i=1; i<N; i++) {A[i]+=A[i-1];}
    ll ans=0; for(int i=1; i<M; i++) { ans += abs(A[B[i]] - A[B[i-1]]); }
    printf("%lld\n", ans);
}