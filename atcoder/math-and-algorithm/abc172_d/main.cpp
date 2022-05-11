#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

// K ではなく a を中心に加算する
// sum_{K=1}^{N} K * f(K)
//   = sum_{K=1}^{N} sum_{a=1}^{K} K [a|K]
//   = sum_{a=1}^{N} sum_{K=a}^{N} K [a|K]
//   = sum_{a=1}^{N} sum_{d=1, a*d<=N} K

int main()
{
    int N; cin >> N;
    ll ans=0; for (int a=1; a<=N; a++) for( int d=1; a*d<=N; d++) ans += a*d;
    printf("%lld\n", ans);
}