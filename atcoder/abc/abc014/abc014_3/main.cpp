#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 1e6+2;
int N; int A[MAX_N];

int main()
{
    cin >> N;
    fill(A, A+MAX_N, 0);
    rep(i, N) {
        int a, b; cin >> a >> b;
        A[a]++; A[b+1]--;
    }
    int sum=0, ans=0; rep(i, MAX_N) {
        sum += A[i];
        ans = max(ans, sum);
    }
    printf("%d\n", ans);
}