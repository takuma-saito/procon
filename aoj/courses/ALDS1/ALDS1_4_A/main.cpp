#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    map<int, bool> S;
    int ans = 0;
    int n; cin >> n;
    rep(i, n) {int x; cin >> x; S[x] = true;}
    int q; cin >> q;
    rep(i, q) {int x; cin >> x; if (S[x]) {ans++;}}
    printf("%d\n", ans);
}