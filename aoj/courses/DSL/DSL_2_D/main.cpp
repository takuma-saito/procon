#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 1<<20;
const int INF = (1u<<31)-1;
int n=1; int A[MAX_N]; int T[MAX_N];

void init(int k) {
    fill(T, T+MAX_N, -1);
    fill(A, A+MAX_N, INF);
    for(;n<k;n<<=1);
}

int find(int i) {
    int ret = INF, t = -1;
    i += n;
    for(;i>0;i>>=1) if (T[i] > t) { t = T[i]; ret = A[i];}
    return ret;
}

void update(int s, int t, int x, int g, int k, int l, int r) {
    if (t <= l || r <= s) return;
    if (s <= l && r <= t) {
        T[k] = g;
        A[k] = x;
    }
    else {
        update(s, t, x, g, 2*k, l, (l+r)/2);
        update(s, t, x, g, 2*k+1, (l+r)/2, r);
    }
}

int main()
{
    int N, Q; cin >> N >> Q;
    init(N);
    rep(i, Q) {
        int op; cin >> op;
        if (op == 0) {
            int s, t, x; cin >> s >> t >> x;
            update(s, t+1, x, i+1, 1, 0, n);
        } else if (op == 1) {
            int x; cin >> x;
            printf("%d\n", find(x));
        } else runtime_error("wrong");
    }
}