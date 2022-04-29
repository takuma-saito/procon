#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 1e4;
int N, M; int A[MAX_N]; int B[MAX_N];

int main()
{
    cin >> N; rep(i, N) cin >> A[i];
    cin >> M; rep(i, M) cin >> B[i];
    int ans = -1, k = min(N, M);
    for(int i=0; i<k; i++) {
        if (A[i] != B[i]) {
            ans = A[i] < B[i];
            break;
        }
    }
    if (ans == -1) ans = (N!=M&&k==N);
    printf("%d\n", ans);
}
