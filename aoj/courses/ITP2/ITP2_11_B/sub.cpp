#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int K, N, U;

int main()
{
    cin >> N >> K; int x=0;
    while(K--) {int t; cin >> t; U |= 1<<t;}
    for(int i=0; i<(1<<N); i++) {
        if ((i&U) != U) continue;
        printf("%d:", i);
        for(int j=0; j<N; j++) if (i>>j&1) printf(" %d", j);
        printf("\n");
    }
}