#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int a[100][100] = {};
int b[100] = {};

int main()
{
    int n, m; cin >> n >> m;
    rep(i, n) {rep(j, m) {cin >> a[i][j];}}
    rep(i, m) {cin >> b[i];}
    rep(i, n) {
        int v = 0;
        rep(j, m) {
            v += a[i][j] * b[j];
        }
        cout << v << endl;
    }
}