#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

// dp[n] = n 段目まで上がった場合の場合の数とする
// `dp[n] = dp[n-1] + dp[n-2]` の漸化式が成り立つ。フィボナッチ数の漸化式となる
// 初期値は dp[0] = 0, dp[1] = 1

int main()
{
    int N; cin >> N;
    ll a=0,b=1; rep(i, N) { int tmp=b; b=a+b; a=tmp; }
    printf("%lld\n", b);
}