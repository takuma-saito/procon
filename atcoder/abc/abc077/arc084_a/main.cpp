#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const int MAX_N = 1e5;
int N; int A[MAX_N]; int B[MAX_N]; int C[MAX_N]; int tmp[MAX_N] = {};

int main()
{
    ll ans=0;
    cin >> N;
    for(auto &x: {A, B, C}) rep(i, N) cin >> x[i];
    for(auto &x: {A, B, C}) sort(x, x+N);
    for(int i=0; i<N; i++) {
        int v = upper_bound(B, B+N, A[i]) - B;
        tmp[v]++;
    }
    ll d=0; for(int j=0; j<N; j++) {
        d += tmp[j];
        ans += d * (C + N - upper_bound(C, C+N, B[j]));
    }
    printf("%lld\n", ans);
}