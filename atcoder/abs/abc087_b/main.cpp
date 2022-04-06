#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MAX_N 1000
int dp[MAX_N];

int main()
{
    int A,B,C,X;
    cin >> A;
    cin >> B;
    cin >> C;
    cin >> X;
    rep(i, A+1) {
        rep(j, B+1) {
            rep(k, C+1) {
                dp[i*10+j*2+k] += 1;
            }
        }
    }
    cout << dp[X/50] << endl;
}