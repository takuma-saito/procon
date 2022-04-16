#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int64_t INF = (int64_t)1<<60;
const int MAX_N = 100;
int64_t d[MAX_N][MAX_N];

int main()
{
    fill((int64_t*)d, (int64_t*)d+MAX_N*MAX_N, INF);
    int V, E; cin >> V >> E;
    rep(i, E) {
        int s, t, dist; cin >> s >> t >> dist;
        d[s][t] = dist;
    }
    rep(i, V) d[i][i] = 0;
    for(int k=0; k<V; k++) {
        for(int i=0; i<V; i++) {
            for (int j=0; j<V; j++) {
                if (d[i][k] != INF && d[k][j] != INF && 
                    d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    rep(i, V) {
        if(d[i][i]<0) {
            printf("NEGATIVE CYCLE\n");
            return 0;
        }
    }
    rep(i, V) rep(j, V) printf("%s%s", d[i][j]==INF?"INF":to_string(d[i][j]).c_str(), j==V-1?"\n":" ");
}