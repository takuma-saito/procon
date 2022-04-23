#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 11;
bool S[MAX_N][MAX_N];
int P[MAX_N];

int main()
{
    fill((bool*)S, (bool*)S+MAX_N*MAX_N, false);
    int N, M, ans=0; cin >> N >> M;
    rep(i, M) {
        int K; cin >> K;
        rep(j, K) {
            int s; cin >> s;
            S[i][s-1]=true;
        }
    }
    rep(i, M) cin >> P[i];
    for(int i=0; i<(1<<N); i++) {
        bool check = true;
        for(int k=0; k<M; k++) {
            int p=0; for(int j=0; j<N; j++) if(((1<<j)&i)!=0 && S[k][j]) p++;
            if(P[k]!=(p%2)) {
                check = false;
                break;
            }
        }
        if (check) ans++;
    }
    printf("%d\n", ans);
}