#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    set<int> st;
    int Q; cin >> Q; while(Q--) {
        int op, x; cin >> op >> x;
        if (op == 0) {
            st.insert(x);
            printf("%d\n", st.size());
        }
        else if (op == 1) printf("%d\n", st.count(x)>0);
        else if (op == 2) st.erase(x);
        else {
            int l=x, r; cin >> r;
            for(auto it = st.lower_bound(l); it!=st.upper_bound(r); it++) printf("%d\n", *it);
        }
    }
}