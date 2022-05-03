#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    long long N, ans=1; cin >> N; while(--N) {ans*=(N+1);} printf("%lld\n", ans);
}