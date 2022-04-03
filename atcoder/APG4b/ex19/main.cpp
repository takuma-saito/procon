#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define N 9

int main()
{
    int ok = 0;
    rep(i, N) {
        rep(j, N) {
            int A;
            cin >> A;
            if (i*j==A) {ok++;}
            cout << i*j << (j == N ? "" : " ");
        }
        cout << endl;
    }
    cout << ok << endl;
    cout << N*N-ok << endl;
}