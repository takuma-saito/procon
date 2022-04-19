#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 1<<20;
const uint32_t INF = (1u<<31)-1;
int A[MAX_N];
int n;

void init(int N) {
    int count=0;
    for(;N>0;N>>=1) count++;
    n = 1<<count;
    rep(i, 2*n) A[i] = INF;
}

void update(int i, int x) {
    i += n; A[i] = x;
    for(int j=i>>1;j>0;j>>=1) A[j] = min(A[2*j], A[2*j+1]);
}

// [s, t), [l, r)
int find(int s, int t, int k, int l, int r) {
    if (t <= l || r <= s) return INF;
    if (s <= l && r <= t) return A[k];
    else {
        int m1 = find(s, t, 2*k,   l, (l+r)/2);
        int m2 = find(s, t, 2*k+1, (l+r)/2, r);
        return min(m1, m2);
    }
}

int main()
{
    int N, Q; cin >> N >> Q;
    init(N);
    rep(i, Q) {
        int op, x, y; cin >> op >> x >> y;
        if (op == 0) update(x, y);
        else if (op == 1) printf("%d\n", find(x, y+1, 1, 0, n));
        else runtime_error("wrong");
    }
}