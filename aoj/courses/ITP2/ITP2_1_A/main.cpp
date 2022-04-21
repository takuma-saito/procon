#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    vector<int> vec;
    int Q; cin >> Q;
    rep(i, Q) {
        int op; cin >> op;
        if (op == 0) {
            int x; cin >> x; vec.push_back(x);
        } else if (op == 1) {
            int x; cin >> x; printf("%d\n", vec[x]);
        } else if (op == 2) vec.pop_back();
        else runtime_error("wrong");
    }
}