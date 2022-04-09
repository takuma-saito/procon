#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int flr[4][3][10];

int main()
{
    int n; cin >> n;
    fill((int*)flr, (int*)flr+4*3*10, 0);
    rep(i, n) {
        int b, f, r, v;
        cin >> b >> f >> r >> v;
        flr[b-1][f-1][r-1] += v;
    }
    rep(b, 4) {
        rep(f, 3) {
            rep(r, 10) {
                cout << " " << flr[b][f][r];
            }
            cout << endl;
        }
        if (b<3) {
            cout << "####################" << endl;
        }
    }
}