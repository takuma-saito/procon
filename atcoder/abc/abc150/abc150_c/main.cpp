#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 9;
int qnum, pnum, N, P[MAX_N], Q[MAX_N], used[MAX_N];

bool solve(int depth, int& num, bool is_q, bool is_p) {
    if (depth==N) {
        num++;
        if (is_p) qnum=num;
        if (is_q) pnum=num;
        return qnum>0&&pnum>0;
    }
    for(int i=0; i<N; i++) {
        if (used[i]) continue;
        used[i] = true;
        if (solve(depth+1, num, is_q && (Q[depth] == i+1), is_p && (P[depth] == i+1))) return true;
        used[i] = false;
    }
    return false;
}

int main()
{
    cin >> N;
    rep(i, N) cin >> P[i];
    rep(i, N) cin >> Q[i];
    int num=0;
    solve(0, num, true, true);
    printf("%d\n", abs(qnum-pnum));
}