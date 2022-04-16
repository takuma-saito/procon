#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int H = 107;

int main()
{
    string t, p; cin >> t >> p;
    uint64_t tu = 0, pu = 0, b = 1, ps = p.size(), ts = t.size();
    rep(i, ps) {
        pu = pu * H + p[i];
        tu = tu * H + t[i];
        b *= H; // b = H^|P|
    }
    rep(j, ts-ps+1) { // TODO
        if (tu==pu) printf("%d\n", j);
        tu = tu*H - b*t[j] + t[j+ps];
    }
}