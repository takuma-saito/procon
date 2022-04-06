#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MAX_N 100001
bool dp[MAX_N]; // TODO: 初期化

int main()
{
    int N;
    string s;
    cin >> s;
    N = s.size();
    fill(dp, dp+MAX_N, false);
    for(int i = N-1; i>=0; i--) {
        if (s.substr(i, 5) == "dream") {
            if (i+5==N) {dp[i] = true;}
            dp[i] |= dp[i+5];
        }
        if (s.substr(i, 5) == "erase") {
            if (i+5==N) {dp[i] = true;}
            dp[i] |= dp[i+5];
        }
        if (s.substr(i, 7) == "dreamer") {
            if (i+7==N) {dp[i] = true;}
            dp[i] |= dp[i+7];
        }
        if (s.substr(i, 6) == "eraser") {
            if (i+6==N) {dp[i] = true;}
            dp[i] |= dp[i+6];
        }
    }
    cout << (dp[0] ? "YES" : "NO") << endl;
}