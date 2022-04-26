#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 100000;
int N, S; int A[MAX_N];

int main()
{
    cin >> N >> S;
    rep(i, N) cin >> A[i];
    int t=0, sum=0, s=0, ans=N+1;
    for(;;) {
        while(t<N && sum<S) sum += A[t++];
        if (sum < S) break;
        ans = min(ans, t-s);
        sum -= A[s++];
    }
    printf("%d\n", ans>N?0:ans);
}