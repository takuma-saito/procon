#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    while(true) {
        int ans=0;
        string s; cin >> s;
        if (s=="0") {break;}
        rep(i, s.size()) {ans+=s[i]-'0';}
        cout << ans << endl;;
    }
}