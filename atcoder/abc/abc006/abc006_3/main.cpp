#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// (1) a+b+c=N
// (2) 2a+3b+4c=M
// を満たす a, b, c が探索できればよい。 2 x (1) - (2) より b + 2c = M - 2N
// よって、b = M-2N-2c として c を探索することで、 b が一意に求まる。a = N - (b+c) で a も求まる

int main()
{
    int N, M; cin >> N >> M;
    for(int c=0; c<=N; c++) {
        int b = M-2*N-2*c;
        int a = N-(b+c);
        if (b<0||a<0) continue;
        printf("%d %d %d\n", a, b, c);
        return 0;
    }
    printf("-1 -1 -1\n");
}