#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 100000;
int N, S; int A[MAX_N];

int main()
{
    cin >> N >> S;
    rep(i, N) cin >> A[i];
    int sum=0, s=0, ans=N;
    for(int t=0; t<N;) {
        while(t<N && sum<S) sum += A[t++];
        while(s<N && sum>=S) {
            ans = min(ans, t-s);
            sum -= A[s++];
        }
    }
    printf("%d\n", s==0 && sum < S ? 0 : ans);
}