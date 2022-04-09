#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1<<30

int main()
{
    int ans, n, m; cin >> n;
    int a, b; cin >> a >> b;
    ans = b-a;
    m = min(a, b);
    rep(i, n-2) {
        int r; cin >> r;
        ans = max(r-m, ans);
        if (m>r) {m=r;}
    }
    cout << ans << endl;
}