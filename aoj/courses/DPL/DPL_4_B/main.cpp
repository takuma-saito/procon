#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const int MAX_N = 40;
int N, K; ll L, R; ll A[MAX_N];

int main()
{
    map<int, vector<ll>> mp;
    cin >> N >> K >> L >> R;
    rep(i, N) cin >> A[i];
    int n1 = N/2;
    for(int i=0; i<(1<<n1); i++) {
        int k=0; ll sum=0;
        for(int j=0; j<n1; j++) if (i>>j&1) { sum += A[j]; k++; }
        mp[k].push_back(sum);
    }
    for(auto &[k, vec]: mp) sort(vec.begin(), vec.end());
    int n2 = N-n1; ll ans=0;
    for(int i=0; i<(1<<n2); i++) {
        int k=0; ll sum=0;
        for(int j=0; j<n2; j++) if (i>>j&1) { sum += A[n1+j]; k++; }
        auto &vec = mp[K-k];
        if (!vec.size() || R-sum<0) continue;
        ll v = upper_bound(vec.begin(), vec.end(), R-sum) -
            lower_bound(vec.begin(), vec.end(), max(L-sum, 0ll));
        if (v) ans += v;
    }
    printf("%lld\n", ans);
}