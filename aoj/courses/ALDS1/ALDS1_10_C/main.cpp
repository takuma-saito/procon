#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 1001;

int solve(string& s, string& t) {
    int dp[MAX_N][MAX_N];
    fill((int*)dp, (int*)dp+MAX_N*MAX_N, 0);
    for(int i=1; i<=s.size(); i++) {
        for(int j=1; j<=t.size(); j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (s[i-1] == t[j-1]) dp[i][j] = max(dp[i-1][j-1]+1, dp[i][j]);
        }
    }
    return dp[s.size()][t.size()];
}

int main()
{
    int n; cin >> n;
    rep(i, n) {
        string s, t; cin >> s >> t;
        printf("%d\n", solve(s, t));
    }
}