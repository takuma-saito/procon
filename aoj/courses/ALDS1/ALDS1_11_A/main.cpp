#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int A[100][100];

int main()
{
    fill((int *)A, (int *)A+100*100, 0);
    int n; cin >> n;
    rep(i, n) {
        int k, id; cin >> id >> k;
        rep(j, k) {int x; cin >> x; A[id-1][x-1]++;}
    }
    rep(i, n) {rep(j, n) {printf("%d%s", A[i][j], j==n-1?"\n":" ");}}
}