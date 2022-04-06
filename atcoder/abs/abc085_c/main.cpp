#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MAX_N 2001
#define MAX_Y 20001
bool dp[MAX_N][MAX_Y] = {};
int link[MAX_N][MAX_Y] = {};
int ans[11] = {};

int main()
{
    int N, Y;
    cin >> N >> Y;
    dp[0][0] = 1;
    Y /= 1000;
    for(int n=1; n<=N; n++) {
        for(int k=1; k<=Y; k++) {
            dp[n][k] = dp[n-1][k-1];
            if (dp[n-1][k-1]) {
                link[n][k] = 1;
            }
            if (k-5>=0) {
                dp[n][k] |= dp[n-1][k-5];
                if(dp[n-1][k-5]) { link[n][k] = 5; }
            }
            if (k-10>=0) {
                dp[n][k] |= dp[n-1][k-10];
                if(dp[n-1][k-10]) { link[n][k] = 10; }
            }
        }
    }
    if (dp[N][Y]) {
        int y=Y, n=N;
        while(n > 0) {
            int p = link[n][y];
            ans[p] += 1;
            n -= 1;
            y -= p;
        }
        cout << ans[10] << " " << ans[5] << " " << ans[1] << endl;
    } else {
        cout << "-1 -1 -1" << endl;
    }
}