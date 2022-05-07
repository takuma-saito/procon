#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// E_N = E_{N-1} + Q[i]/P[i];

int main()
{
    int N; cin >> N;
    double e=0; rep(i, N) {
        double p, q; cin >> p >> q;
        e += q/p;
    }
    printf("%.12lf\n", e);
}