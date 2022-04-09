#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int cols[100];

int main()
{
    int r, c; cin >> r >> c;
    fill(cols, cols+100, 0);
    rep(i, r) {
        int row = 0;
        rep(j, c) {
            int val; cin >> val;
            cols[j] += val;
            row += val;
            cout << val << " ";
        }
        cout << row << endl;
    }
    int sum = 0;
    rep(i, c) {
        cout << cols[i] << " ";
        sum += cols[i];
    }
    cout << sum << endl;
}
