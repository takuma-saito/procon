#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
    vector<ll> divs;
    ll N; cin >> N;
    for (ll i=1; i*i<=N; i++) {
        if (!(N%i)) {
            divs.push_back(i);
            if (i!=N/i) divs.push_back(N/i);
        }
    }
    sort(divs.begin(), divs.end());
    rep(i, divs.size()) printf("%lld\n", divs[i]);
}