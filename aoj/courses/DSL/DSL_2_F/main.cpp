#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = (1u<<31)-1;
const int MAX_N = 1<<20;
int n=1; int lazyUpdate[MAX_N]; int Amin[MAX_N];

void init(int k) {
    for(;n<=k;n*=2);
    fill(lazyUpdate, lazyUpdate+2*n, INF);
    fill(Amin, Amin+2*n, INF);
}

void push(int k) {
    if (lazyUpdate[k] == INF) return;
    if (2*k+1<2*n) {
        Amin[k] = lazyUpdate[k];
        lazyUpdate[2*k]   = lazyUpdate[k];
        lazyUpdate[2*k+1] = lazyUpdate[k];
    }
    lazyUpdate[k] = 0;
}

void update(int s, int t, int x, int k, int l, int r) {
    push(k);
    if (t <= l || r <= s) return;
    if (s <= l && r <= t) {
        lazyUpdate[k] = x; push(k);
    }
    else {
        update(s, t, x, 2*k,   l, (l+r)/2);
        update(s, t, x, 2*k+1, (l+r)/2, r);
    }
}

int find(int s, int t, int k, int l, int r) {
    push(k);
    if (t <= l || r <= s) return INF;
    if (s <= l && r <= t) {
        return Amin[k];
    }
    else {
        int vl = find(s, t, 2*k,   l, (l+r)/2);
        int vr = find(s, t, 2*k+1, (l+r)/2, r);
        return min(vl, vr);
    }
}

int main()
{
    int N, Q; cin >> N >> Q; init(N);
    rep(i, Q) {
        int op; cin >> op;
        if (op == 0) {
            int s, t, x; cin >> s >> t >> x;
            update(s, t+1, x, 1, 0, n);
        } else if (op == 1) {
            int s, t; cin >> s >> t;
            printf("%d\n", find(s, t+1, 1, 0, n));
            rep(i, 2*n) printf("%d %d\n", i, Amin[i]);
            cout << endl;
        } else runtime_error("wrong");
    }
}