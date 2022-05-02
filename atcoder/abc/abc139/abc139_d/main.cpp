#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// k が固定された時に i % k を最大にする i を考える 0<=i<k なので、この時取れる最大値は i=k-1
// k=1 の時は i=N とすればよい
// よって、この時 M[1] 〜 M[N] までの和は 1 〜 N-1 までの和を取ったらよいので、N(N-1)/2

int main()
{
    long long N; cin >> N; printf("%lld\n", N*(N-1)/2);
}