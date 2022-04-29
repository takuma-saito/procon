#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N, Q; cin >> N >> Q;
    vector<list<int>> lists(N);
    while(Q--) {
        int op, t; cin >> op >> t;
        auto &ls = lists[t];
        if (op==0) {
            int x; cin >> x; ls.push_back(x);
        } else if (op==1) {
            if (ls.size()) {
                for(auto it = ls.begin(); it != ls.end(); it = next(it)) {
                    printf("%s%d", it==ls.begin()?"":" ", *it);
                }
            }
            printf("\n");
        } else {
            int s; cin >> s;
            auto &ls2 = lists[s];
            ls.splice(ls.begin(), ls2);
            ls2.clear();
            swap(lists[t], lists[s]);
        }
    }
}