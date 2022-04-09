#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    while(true) {
        int a, b, ans;
        char op;
        cin >> a >> op >> b;
        if (op == '?') { break; }
        if (op == '+') {
            ans = a+b;
        } else if (op == '-') {
            ans = a-b;
        } else if (op == '/') {
            ans = a/b;
        } else if (op == '*') {
            ans = a*b;
        } else {
            runtime_error("error: op="+op);
        }
        cout << ans << endl;
    }
}