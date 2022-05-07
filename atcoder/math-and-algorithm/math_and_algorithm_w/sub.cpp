#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 1e5;
int N; double B[MAX_N] = {}; double R[MAX_N] = {};

// E_{N} = E_{N-1} + B_N/N + R_N/N

int main()
{
    cin >> N;
    rep(i, N) cin >> B[i];
    rep(i, N) cin >> R[i];
    double e=0; rep(i, N) { e += B[i]/N + R[i]/N; }
    printf("%.12lf\n", e);
}