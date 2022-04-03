#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int X, prev = -1;
    rep(i, 5)  {
        cin >> X;
        if (X == prev) {
            cout << "YES" << endl;
            exit(0);
        }
        prev = X;
    }
    cout << "NO" << endl;
}