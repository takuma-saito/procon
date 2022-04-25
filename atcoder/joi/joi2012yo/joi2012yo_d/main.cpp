#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 101;
const int MAX_P = 4;
int N; int dp[MAX_N][MAX_P][MAX_P]; int A[MAX_N];

// dp[i][a][b] = { i 日目にパスタの場合の数。a, b はそれぞれ当日、昨日に選択したパスタ }
// dp[i][a][b] = sum { dp[i-1][x][a] | x = A[i-2]（A[i-2]==b なら 0） または、x = {a, b, c}　ただし x = a のときは b ≠ a }

int main()
{
    fill((int*)dp, (int*)dp+MAX_N*MAX_P*MAX_P, 0);
    if (A[1]>0&&A[2]>0) dp[1][A[1]][A[2]] = 1;
    else {
        for(int a=1; a<=3; a++) {
            if (A[1]>0) dp[1][A[1]][a] = 1;
            else if (A[2]>0) dp[1][a][A[2]] = 1;
            else {
                for(int b=1; b<=3; b++) {
                    dp[0][a][b] = 1;
                }
            }
        }
    }
    for(int i=3; i<=N; i++) {
        for(int a=1; a<=3; a++) {
            for(int b=1; b<=3; b++) {
                if (A[i]!=0) {
                    dp[i][a][b] = b!=A[i-2] ? dp[i-2][A[i-2]][b] : 0;
                } else {
                    for(int x=1; x<=3; x++) {
                        if (x == a && b == a) continue;
                        dp[i][a][b] += dp[i-1][x][a];
                    }
                }
            }
        }
    }
}
