#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string t, s; cin >> t >> s;
    rep(i, t.size()) {
        bool match = true;
        if (i+s.size()>t.size()) break;
        rep(j, s.size()) match &= s[j] == t[i+j];
        if (match) printf("%d\n", i);
    }
}