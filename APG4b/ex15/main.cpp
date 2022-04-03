#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N;
    int X, A = 0, B = 0, C = 0;
    cin >> N;
    rep(i, N) { cin >> X; A+=X; }
    rep(i, N) { cin >> X; B+=X; }
    rep(i, N) { cin >> X; C+=X; }
    cout << A*B*C << endl;
}