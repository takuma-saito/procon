#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const int MAX_N = 2e5;
const int S = 1e5;
int N; int A[MAX_N]; ll B[S+1] = {};

int main()
{
    cin >> N; rep(i, N) {
        int x; cin >> x; B[x]++;
    }
    ll ans=0; for(int i=1; i<S/2; i++) ans += B[i] * B[S-i];
    ll v = B[S/2];
    if (v>0) ans += v*(v-1)/2;
    printf("%lld\n", ans);
}
