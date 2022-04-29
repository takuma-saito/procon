#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N, Q; cin >> N >> Q;
    vector<queue<int>> ques(N);
    while(Q--) {
        int op, t, x; cin >> op >> t;
        auto &que = ques[t]; int size = que.size();
        if (op == 0) {
            cin >> x; que.push(x);
        } else if (op == 1 && size) printf("%d\n", que.front());
        else if (size) que.pop();
    }
}