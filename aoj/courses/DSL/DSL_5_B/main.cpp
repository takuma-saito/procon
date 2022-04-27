#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 1e5;
const int MAX_X = 1e3+3;
const int MAX_Y = 1e3+3;
int N; int A[MAX_X][MAX_Y];

int main()
{
    cin >> N;
    fill((int*)A, (int*)A+MAX_X*MAX_Y, 0);
    rep(i, N) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1++; y1++; x2++; y2++;
        A[x1][y1]++;
        A[x2][y1]--;
        A[x1][y2]--;
        A[x2][y2]++;
    }
    int ans=0;
    for(int x=1; x<MAX_X; x++) {
        for(int y=1; y<MAX_Y; y++) {
            A[x][y] += A[x][y-1];
        }
        for(int y=1; y<MAX_Y; y++) {
            A[x][y] += A[x-1][y];
            ans = max(ans, A[x][y]);
        }
    }
    printf("%d\n", ans);
}