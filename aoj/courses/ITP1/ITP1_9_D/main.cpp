#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string s; cin >> s;
    vector<char> vec(s.begin(), s.end());
    int q; cin >> q;
    rep(i, q) {
        string op; cin >> op;
        if (op == "replace") {
            string p;
            int a, b; cin >> a >> b >> p;
            for(int i=a; i<=b; i++) {
                vec[i] = p[i-a];
            }
        } else if (op == "reverse") {
            int a, b; cin >> a >> b;
            for(int i=a; i<=(a+b)/2; i++) {
                swap(vec[i], vec[a+b-i]);
            }
        } else if (op == "print") {
            int a, b; cin >> a >> b;
            for(int i=a; i<=b; i++) {
                cout << vec[i];
            }
            cout << endl;
        } else {
            runtime_error("unknwon op "+op);
        }
    }
}