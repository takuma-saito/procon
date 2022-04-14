#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
struct Mat {long int r, c;};
const long int INF = 1<<20;
const int MAX_N = 101;
pair<long int, Mat> dp[MAX_N][MAX_N];

pair<long int, Mat> solve(int i, int j) {
    if (j==i+1 || dp[i][j].first < INF) return dp[i][j];
    for(int k=i+1; k<j; k++) {
        auto [x, mx] = solve(i, k);
        auto [y, my] = solve(k ,j);
        long int g = (mx.r*mx.c*my.c)+x+y;
        if (g!=0 && dp[i][j].first>g) {
            dp[i][j] = {g, Mat({mx.r, my.c})};
        }
    }
    return dp[i][j];
}

int main()
{
    int n; cin >> n;
    rep(i, n+1) rep(j, n+1) dp[i][j] = {INF, Mat({0, 0})};
    rep(i, n) {
        int r, c; cin >> r >> c;
        dp[i][i+1] = {0, Mat({r, c})}; // [i, i+1)
    }
    printf("%d\n", solve(0, n).first);
}