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
        } else if (op==1) printf("%d\n", mp.count(key)?mp[key]:0);
        else if (op==2) mp.erase(key);
        else {
            string l=key, r; cin >> r;
            auto vl = mp.lower_bound(l);
            auto vr = mp.upper_bound(r);
            for(auto it=vl; it!=vr; ++it) {
                printf("%s %d\n", it->first.c_str(), it->second);
            }
        }
    }
}