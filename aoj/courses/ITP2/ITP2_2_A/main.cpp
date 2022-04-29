#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N, Q; cin >> N >> Q;
    vector<stack<int>> stacks(N);
    while(Q--) {
        int op, t, x; cin >> op >> t;
        auto &st = stacks[t]; int size = st.size();
        if (op == 0) {
            cin >> x;
            st.push(x);
        } else if(op == 1) {
            if (size) printf("%d\n", st.top());
        } else if (size) st.pop();
    }
}