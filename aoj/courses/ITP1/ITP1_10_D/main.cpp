#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    cout << fixed << std::setprecision(20);
    int n; cin >> n;
    double a=0, b=0, c=0, d=0;
    vector<int> xs, ys;
    rep(i, n) {int x; cin >> x; xs.push_back(x);}
    rep(i, n) {int y; cin >> y; ys.push_back(y);}
    rep(i, n) {
        double v = abs(xs[i]-ys[i]);
        a += v;
        b += pow(v, 2);
        c += pow(v, 3);
        d = max(d, v);
    }
    b = sqrt(b);
    c = pow(c, 1/3.0);
    for(auto ans: {a, b, c, d}) {
        cout << ans << endl;
    }
}