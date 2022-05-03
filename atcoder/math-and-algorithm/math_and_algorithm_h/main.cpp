#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// 1<=a+b<=S となる自然数 1<= a, b <= N の数を求めよ
// b を一つ固定した場合、1-b<=a<=S-b より S-b 通りある。よって sum_{1}^{min(N,S-1)} S-b = N*S - N*(N+1)/2 が答え
// S(S-1) - S(S-1)/2 = S(S-1)/2

// a<=S-b<=N

int main()
{
    int N, S; cin >> N >> S;
    int ans=0; for(int b=1; b<=N; b++) {
        if (S-b>0) {
            ans += min(N, S-b);
        }
    }
    printf("%d\n", ans);
}