#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
    ll A[3] = {};
    int N; cin >> N; while(N--) {
        int x; cin >> x; A[--x]++;
    }
    ll ans=0; rep(i, 3) { ans += (A[i] * (A[i]-1))/2;}
    printf("%lld\n", ans);
}