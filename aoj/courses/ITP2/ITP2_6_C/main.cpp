#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 1e5;
int N; int A[MAX_N];

int main()
{
    cin >> N; rep(i, N) cin >> A[i];
    int Q; cin >> Q; while(Q--) {
        int k; cin >> k;
        printf("%d\n", lower_bound(A, A+N, k) - A);
    }
}