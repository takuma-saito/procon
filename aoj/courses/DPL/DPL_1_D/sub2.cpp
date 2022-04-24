#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1<<30;
const int MAX_N = 100001;
int dp[MAX_N]; int A[MAX_N]; int N;

int main()
{
    fill((int*)dp, (int*)dp+MAX_N, INF);
    cin >> N; rep(i, N) cin >> A[i];
    for(int n=0; n<=N; n++) {
        int lb=-1, ub=N;
        while(ub-lb>1) {
            int mid = (ub+lb)/2;
            if (dp[mid]<A[n]) lb=mid;
            else ub=mid;
        }
        dp[ub]=A[n];
    }
    int ans=0; for(;ans<N && dp[ans]!=INF; ans++);
    printf("%d\n", ans);
}