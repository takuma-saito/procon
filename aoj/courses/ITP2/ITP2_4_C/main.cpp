#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 1e4;
int N; int A[MAX_N];

int main()
{
    cin >> N; rep(i, N) cin >> A[i];
    int Q; cin >> Q; while(Q--) {
        int b, e, t; cin >> b >> e >> t;
        for(int k=0; k<(e-b); k++) {
            swap(A[b+k], A[t+k]);
        }
    }
    rep(i, N) printf("%d%s", A[i], i==N-1?"\n":" ");
}