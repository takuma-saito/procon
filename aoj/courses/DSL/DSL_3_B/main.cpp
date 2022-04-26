#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 1e5;
const int MAX_K = 1e5;
int N, K; int A[MAX_N];

int main()
{
    int s=0, t=0; map<int, int> used;
    cin >> N >> K; rep(i, N) cin >> A[i];
    int ans = N+1;
    for(;;) {
        while (t<N && used.size()<K) {
            if (A[t] >= 1 && A[t] <= K) used[A[t]]++;
            t++;
        }
        if (used.size() < K) break;
        ans = min(ans, t-s);
        if (A[s]>=1 && A[s]<= K && --used[A[s]] == 0) used.erase(A[s]);
        s++;
    }
    printf("%d\n", ans>N?0:ans);
}
