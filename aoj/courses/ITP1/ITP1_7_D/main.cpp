#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MAX_N 100
long int A[MAX_N][MAX_N], B[MAX_N][MAX_N], C[MAX_N][MAX_N];

int main()
{
    int n, m, l; cin >> n >> m >> l;
    fill((int*)C, (int*)C+100*100, 0);
    rep(i, n) {rep(j, m) {cin >> A[i][j]; }}
    rep(i, m) {rep(j, l) {cin >> B[i][j]; }}
    rep(i, n) {
        rep(j, l) {
            int sum = 0;
            rep(k, m) {
                C[i][j] += A[i][k]*B[k][j];
            }
            cout << C[i][j] << (j==l-1?"":" ");
        }
        cout << endl;
    }
}