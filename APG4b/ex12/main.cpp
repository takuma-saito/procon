#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N, A;
    cin >> N;
    cin >> A;
    rep(i, N) {
        string op;
        int B;
        cin >> op >> B;
        if (op == "+") { A += B; }
        else if (op == "-") { A -= B; }
        else if (op == "*") { A *= B; }
        else if (op == "/") {
            if (B == 0) {
                cout << "error" << endl;
                exit(1);
            }
            A /= B;
        } else {
            runtime_error("unknown op: " + op);
        }
        cout << (i+1) << ":" << A << endl;
    }
}