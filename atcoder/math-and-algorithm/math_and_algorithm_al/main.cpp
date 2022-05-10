#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_T = 5e5+1;
int A[MAX_T] = {};

int main()
{
    int T, N; cin >> T >> N; rep(i, N) {
        int l, r; cin >> l >> r;
        A[l]++; A[r]--;
    }
    for(int t=1; t<=T; t++) {
        printf("%d\n", A[t-1]);
        A[t] += A[t-1];
    }
}