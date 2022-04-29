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
        } else if (op == 1) printf("%d\n", st.count(x)>0); 
        else st.erase(x);
    }
}