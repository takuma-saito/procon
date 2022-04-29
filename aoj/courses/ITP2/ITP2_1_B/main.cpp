#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    deque<int> dq;
    int Q; cin >> Q;
    rep(q, Q) {
        int op; cin >> op;
        if (op == 0) {
            int d, x; cin >> d >> x;
            d ? dq.push_back(x) : dq.push_front(x);
        } else if (op == 1) {
            int p; cin >> p;
            printf("%d\n", dq[p]);
        } else {
            int d; cin >> d;
            d ? dq.pop_back() :dq.pop_front();
        }
    }
}