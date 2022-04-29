#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    map<string, int> mp;
    int Q; cin >> Q; while(Q--) {
        int op; string key; cin >> op >> key;
        if (op==0) {
            int x; cin >> x;
            mp[key] = x;
        } else printf("%d\n", mp[key]);
    }
}