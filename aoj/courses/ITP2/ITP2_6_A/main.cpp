#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    set<int> st;
    int N; cin >> N; rep(i, N) {
        int x; cin >> x; st.insert(x);
    }
    int Q; cin >> Q; while(Q--) {
        int x; cin >> x; printf("%d\n", st.count(x)>0);
    }
}