#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    map<char, int> ans;
    while(true) {
        string s; getline(cin, s);
        if (s.empty()) {break;}
        rep(i, s.size()) {
            char c = s[i];
            if (c>='A'&&c<='Z') {c-=('A'-'a');}
            if(ans.find(c) == ans.end()) {ans[c] = 1;}
            else {ans[c]++;}
        }
    }
    for(char c='a'; c<='z'; c++) {
        cout << c << " : " << (ans.find(c) == ans.end() ? 0 : ans[c]) << endl;
    }
}