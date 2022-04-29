#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    list<int> ls; auto it = ls.end();
    int d, x, Q; cin >> Q; while(Q--) {
        int op; cin >> op;
        if (op == 0) {
            cin >> x; it = ls.insert(it, x);
        } else if (op == 1) {
            cin >> d;
            advance(it, d);
        } else {
            it = ls.erase(it);
        }
    }
    for(int val: ls) printf("%d\n", val);
}