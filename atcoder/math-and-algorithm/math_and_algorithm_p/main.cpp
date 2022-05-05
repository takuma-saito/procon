#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const int MAX_N = 1e5;
int N; ll A[MAX_N];

int main()
{
    cin >> N; rep(i, N) cin >> A[i];
    ll g=A[0];
    for(int i=1; i<N; i++) g = gcd(g, A[i]);
    printf("%lld\n", g);
}