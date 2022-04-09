#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int D = 'A' - 'a';

int main()
{
    string s; getline(cin, s);
    rep(i, s.size()) {
        if ('a' <= s[i] && s[i] <= 'z') {
            cout << char(s[i]+D);
        } else if ('A' <= s[i] && s[i] <= 'Z') {
            cout << char(s[i]-D);
        } else {
            cout << s[i];
        }
    }
    cout << endl;
}