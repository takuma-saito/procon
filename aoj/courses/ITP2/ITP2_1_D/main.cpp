#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 1001;

int main()
{
    int op, t, x, N, Q;
    cin >> N >> Q;
    vector<vector<int>> vecs(N);
    while(Q--) {
        cin >> op >> t;
        auto &vec = vecs[t]; int s = vec.size();
        if (op == 0) {
            cin >> x; vec.push_back(x);
        } else if (op == 1) {
            if (s) rep(i, s) printf("%d%s", vec[i], i!=s-1?" ":"\n");
            else printf("\n");
        } else {
            if (s) vec.clear();
        }
    }
}