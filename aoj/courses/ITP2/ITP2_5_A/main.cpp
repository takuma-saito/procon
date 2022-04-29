#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
struct Pos {int x, y;};
const int MAX_N = 1e5;
int N; Pos A[MAX_N];

int main()
{
    cin >> N; rep(i, N) {
        int x, y; cin >> x >> y;
        A[i] = Pos {x, y};
    }
    sort(A, A+N, [](const Pos &a, const Pos &b) {
        return a.x == b.x ? (a.y < b.y) : a.x < b.x;
    });
    rep(i, N) printf("%d %d\n", A[i].x, A[i].y);
}