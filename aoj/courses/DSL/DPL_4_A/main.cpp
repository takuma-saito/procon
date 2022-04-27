#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const int MAX_N = 1e4;
int N; ll C[4][MAX_N]; ll V;

int main()
{
    vector<ll> vec; ll ans=0;
    cin >> N >> V;
    rep(k, 4) rep(i, N) cin >> C[k][i];
    rep(i, N) rep(j, N) vec.push_back(C[0][i] + C[1][j]);
    sort(vec.begin(), vec.end());
    rep(i, N) rep(j, N) {
        ll x = C[2][i]+C[3][j];
        int d = upper_bound(vec.begin(), vec.end(), V-x) - 
                lower_bound(vec.begin(), vec.end(), V-x);
        ans += d;
    }
    printf("%lld\n", ans);
}