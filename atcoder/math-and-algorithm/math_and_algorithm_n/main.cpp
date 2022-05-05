#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
    ll N; cin >> N;
    vector<ll> divs;
    for(ll i=2; i*i<=N; i++) {
        while(N%i==0) {
            divs.push_back(i);
            N /= i;
        }
    }
    if (N!=1) divs.push_back(N);
    rep(i, divs.size()) printf("%lld%s", divs[i], i==divs.size()-1?"\n":" ");
}