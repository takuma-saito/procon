#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N, Q; cin >> N >> Q;
    vector<priority_queue<int>> pques(N);
    while (Q--) {
        int op, t, x; cin >> op >> t;
        auto &pque = pques[t]; int size = pque.size();
        if (op == 0) {
            cin >> x; pque.push(x);
        } else if (op == 1 && size) printf("%d\n", pque.top());
        else if (size) pque.pop();
    }
}