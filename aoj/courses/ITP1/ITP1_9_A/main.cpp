#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int ans=0;
    string t; cin >> t;
    while(true) {
        string s; cin >> s;
        if (s == "END_OF_TEXT") {break; }
        for(char &c: s) {if (c>='A' && c<='Z') {c -='A'-'a';}}
        if (t == s) {ans++;}
    }
    cout << ans << endl;
}