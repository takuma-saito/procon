#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 100001;
bool dp[MAX_N];
int items[] = {100, 101, 102, 103, 104, 105};

int main()
{
    fill(dp, dp+MAX_N, false);
    int X; cin >> X;
    for(int item: items) dp[item] = true;
    for(int x=106; x<=X; x++) for(int item: items) dp[x] |= dp[x-item];
    printf("%d\n", dp[X]);
}