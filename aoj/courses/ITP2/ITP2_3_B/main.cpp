#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 1e4;
const int INF=1e9+1;
int N; int A[MAX_N];

int main()
{
    cin >> N; rep(i, N) cin >> A[i];
    int Q; cin >> Q; while(Q--) {
        int b, e, com, x=INF, y=-INF;
        cin >> com >> b >> e;
        for(int i=b; i<e; i++) {
            if (A[i] < x) x = A[i];
            if (A[i] > y) y = A[i];
        }
        printf("%d\n", com==0?x:y);
    }
}