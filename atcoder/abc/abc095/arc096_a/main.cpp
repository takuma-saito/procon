#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// X: A が X-k 枚 AB が k 枚
// Y: B が Y-k 枚 AB が k 枚

int main()
{
    int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
    int ans = (1u<<31)-1; rep(k, max(X, Y)+1) {
        int d = 0;
        if (X-k>=0) d+=(X-k)*A;
        if (Y-k>=0) d+=(Y-k)*B;
        d += 2*k*C;
        ans = min(ans, d);
    }
    printf("%d\n", ans);
}