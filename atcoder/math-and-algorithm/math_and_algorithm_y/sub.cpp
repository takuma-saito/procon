#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 2e5;
int N; double E[MAX_N] = {}; int A[MAX_N]; int B[MAX_N];

// E_N = E_{N-1} + A[N]/3 + B[N]*2/3

int main()
{
    cin >> N;
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    double e=0; rep(i, N) { e += double(A[i])/3 + double(B[i])*2/3; }
    printf("%.12lf", e);
}