#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define N_MAX 120
char ans[N_MAX][N_MAX];

int main()
{
    int N, M;
    cin >> N >> M;
    memset(ans, '-', sizeof(ans));
    rep(i, M) {
        int A, B;
        cin >> A >> B;
        ans[A][B] = 'o';
        ans[B][A] = 'x';
    }
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cout << ans[i][j] << (j != N ? " " : "");
        }
        cout << endl;
    }

}