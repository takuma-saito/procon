#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 1e5+1;
int N, T; int A[MAX_N];

int main()
{
    int ans=0;
    fill(A, A+MAX_N, 0);
    cin >> N >> T;
    rep(i, N) {
        int l, r; cin >> l >> r;
        A[l]++; A[r]--;
    }
    int sum=0; rep(i, T) {
        sum += A[i];
        ans = max(ans, sum);
    }
    printf("%d\n", ans);
}