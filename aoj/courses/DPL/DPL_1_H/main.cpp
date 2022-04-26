#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const int MAX_N = 40;
const ll INF = 1e18;
ll N, W; ll weight[MAX_N]; ll value[MAX_N];

// TODO: https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_1_H/review/4968199/emtsu_ba/C++17

int main()
{
    vector<P> vec;
    fill(weight, weight+MAX_N, 0);
    fill(value, value+MAX_N, 0);

    cin >> N >> W;
    rep(i, N) cin >> value[i] >> weight[i];
    int D = N/2;

    vec.push_back(P{0, 0});
    for(int i=1; i<(1<<D); i++) {
        ll sw=0, sv=0; for(int j=0; j<D; j++) if (i>>j&1) {
            sw += weight[j];
            sv += value[j];
        }
        vec.push_back({sw, sv});
    }
    sort(vec.begin(), vec.end());

    int m = 1; for(int i=1; i<vec.size(); i++) {
        if (vec[m-1].second < vec[i].second) vec[m++] = vec[i];
    }

    int G = N-D;
    ll ans = 0;
    for(int i=1; i<(1<<G); i++) {
        ll sw=0, sv=0; for(int j=0; j<G; j++) if (i>>j&1) {
            sw += weight[D+j];
            sv += value[D+j];
        }
        if (W-sw<0) continue;
        auto it = lower_bound(vec.begin(), vec.begin()+m, P{W-sw, INF});
        ans = max(ans, (it == vec.begin()) ? sv : sv + (--it)->second);
    }

    printf("%lld\n", ans);
}