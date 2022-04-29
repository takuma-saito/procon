#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 1e4;
int N; int A[MAX_N];

int main()
{
    cin >> N;
    rep(i, N) cin >> A[i];
    int Q; cin >> Q; while(Q--) {
        int b, e, k, ans=0;
        cin >> b >> e >> k;
        for(int i=b; i<e; i++) if (A[i]==k) ans++;
        printf("%d\n", ans);
    }
}