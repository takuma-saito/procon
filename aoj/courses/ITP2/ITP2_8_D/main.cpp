#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    multimap<string, int> mp;
    int Q; cin >> Q; while(Q--) {
        int op; string key; cin >> op >> key;
        if (op==0) {
            int x; cin >> x;
            mp.insert({key, x});
        } else if (op==1) {
            auto [l, r] = mp.equal_range(key);
            for(auto it=l; it!=r; it++) printf("%d\n", it->second);
        } else if (op==2) mp.erase(key);
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