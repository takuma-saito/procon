#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int ans = 0;
    string s;
    char op = '+';
    cin >> s;
    for(char& c: s) {
        if (c == '1' || c == '0') {
            if (op == '+') {
                ans += c - '0';
            } else if (op == '-') {
                ans -= c - '0';
            } else {
                cout << "[ERROR] op: " << op << endl;
                exit(1);
            }
        } else {
            op = c;
        }
    }
    cout << ans << endl;
}