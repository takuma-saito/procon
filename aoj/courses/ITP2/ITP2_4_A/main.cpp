    #include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 1e4;
int N; int A[MAX_N];

int main()
{
    int N; cin >> N; rep(i, N) cin >> A[i];
    int Q; cin >> Q; while(Q--) {
        int b, e; cin >> b >> e;
        reverse(A+b, A+e);
    }
    rep(i, N) printf("%d%s", A[i], i==N-1?"\n":" ");
}