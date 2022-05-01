#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const int MAX_N = 1e5;
int N; int H[MAX_N]; int S[MAX_N];

bool hittable(ll h) {
    vector<double> vec;
    rep(i, N) vec.push_back(double(h-H[i])/S[i]);
    sort(vec.begin(), vec.end());
    rep(i, N) if (vec[i] <= i) return false;    
    return true;
}

int main()
{
    cin >> N;
    rep (i, N) cin >> H[i] >> S[i];
    ll lb=-1, ub=1ll<<61;
    while(ub-lb>1) {
        ll mid = (ub+lb)/2;
        if (hittable(mid)) ub=mid;
        else lb=mid;
    }
    printf("%lld\n", lb);
}
