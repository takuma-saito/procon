#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const int MAX_N = 1e5;
int N, Q; ll A[MAX_N];

ll solve(ll x) {
    int r=0; ll sum=0, res=0;
    for(int l=0;l<N;l++) {
        while (r<N && sum+A[r]<=x) sum += A[r++];
        res += r-l;
        r==l ? r++ : sum -= A[l];
    }
    return res;
}

int main()
{
    cin >> N >> Q;
    rep(i, N) cin >> A[i];
    rep(i, Q) {
        ll x; cin >> x;
        printf("%lld\n", solve(x));
    }
}