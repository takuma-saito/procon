#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const int MAX_N = 20;
ll N, W; ll weight[MAX_N]; ll value[MAX_N];

int main()
{
    vector<P> vec, vec2;
    fill(weight, weight+MAX_N, 0);
    fill(value, value+MAX_N, 0);

    cin >> N >> W;
    rep(i, N) cin >> value[i] >> weight[i];
    int D = N/2;

    for(int i=1; i<(1<<D); i++) {
        ll sw=0, sv=0; for(int j=0; j<D; j++) if (i>>j&1) {
            sw += weight[j];
            sv += value[j];
        }
        vec.push_back({sw, sv});
    }
    sort(vec.begin(), vec.end(), [](const P& l, const P& r) {
        return l.first == r.first ? (l.second > r.second) : (l.second < r.second);
    });

    int G = N-D;
    ll ans = 0;
    for(int i=1; i<(1<<G); i++) {
        ll sw=0, sv=0; for(int j=0; j<G; j++) if (i>>j&1) {
            sw += weight[D+j];
            sv += value[D+j];
        }
        auto it = lower_bound(vec.begin(), vec.end(),
            P{W-sw, -1}, [](const P& l, const P& r){ return l.first < r.first; });
        int idx = distance(vec.begin(), it);
        ans = max(ans, sv+vec[idx].second);
    }

    printf("%lld\n", ans);
}