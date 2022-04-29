#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 1e5;
int N; int A[MAX_N];

int main()
{
    cin >> N; rep(i, N) cin >> A[i];
    sort(A, A+N);
    int E = unique(A, A+N) - A;
    rep(i, E) printf("%d%s", A[i], i==E-1?"\n":" ");
}