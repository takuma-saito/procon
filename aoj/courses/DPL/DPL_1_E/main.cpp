#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1<<30;
const int MAX_N = 1001;
int dp[MAX_N][MAX_N];

int main()
{
    string S, T; cin >> S >> T;
    fill((int*)dp, (int*)dp+S.size()*T.size(), INF);
    for(int t=0; t<=T.size(); t++) dp[0][t] = t;
    for(int s=0; s<=S.size(); s++) dp[s][0] = s;
    for(int s=1; s<=S.size(); s++) {
        for(int t=1; t<=T.size(); t++) {
            dp[s][t] = min({dp[s-1][t-1]+(S[s-1]!=T[t-1]), dp[s-1][t]+1, dp[s][t-1]+1});
        }
    }
    printf("%d\n", dp[S.size()][T.size()]);
}