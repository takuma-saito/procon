#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MAX_N 1000
int A[MAX_N], P[MAX_N];

int main()
{
    int N, S, ans = 0;
    cin >> N >> S;
    rep(i, N) {cin >> A[i];}
    rep(i, N) {cin >> P[i];}
    rep(i, N) {rep(j, N) {if (A[i]+P[j]==S) {ans++;}}}
    cout << ans << endl;
}
