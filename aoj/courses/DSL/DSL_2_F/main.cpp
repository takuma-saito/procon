#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = (1u<<31)-1;
const int MAX_N = 1<<20;
int n=1; int lazyT[MAX_N]; int lazyUpdate[MAX_N]; int Amin[MAX_N];

void init(int k) {
    for(;n<=k;n*=2);
    fill(lazyT, lazyT+2*n, 0);
    fill(lazyUpdate, lazyUpdate+2*n, 0);
    fill(Amin, Amin+2*n, INF);
}

void push(int k, int l, int r) {
    if (lazyUpdate[k] != 0 && 2*k+1<2*n) {
        if (lazyT[2*k]   < lazyT[k]) lazyUpdate[2*k]   = lazyUpdate[k];
        if (lazyT[2*k+1] < lazyT[k]) lazyUpdate[2*k+1] = lazyUpdate[k];
    }
    lazyT[k] = 0;
    lazyUpdate[k] = 0;
}

void update(int s, int t, int x, int g, int k, int l, int r) {
    if (t <= l || r <= s) return;
    if (s <= l && r <= t) { lazyUpdate[k] = x; lazyT[k] = g; }
    else {
        update(s, t, x, g, 2*k,   l, (l+r)/2);
        update(s, t, x, g, 2*k+1, (l+r)/2, 4);
    }
}

int find(int s, int t, int k, int l, int r) {
    push(k, l, r);
    if (t <= l || r <= s) return INF;
    if (s <= l && r <= t) {
        if (lazyUpdate[k] > 0) Amin[k] = lazyUpdate[k];
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
            update(s, t+1, x, i+1, 1, 0, n);
            rep(i, 2*n) printf("%d %d\n", lazyUpdate[i]);
            cout << endl;
        } else if (op == 1) {
            int s, t; cin >> s >> t;
            printf("%d\n", find(s, t+1, 1, 0, n));
        } else runtime_error("wrong");
    }
}