#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 1<<20;
int A[MAX_N];
int n=1;

void init(int k) {
    for(;n<=k;n<<=1);
    fill(A, A+MAX_N, 0);
}

int get(int i) {
    int sum = 0; i += n;
    for(;i>0;i>>=1) sum += A[i];
    return sum;
}

void add(int s, int t, int x, int k, int l, int r) {
    if (t <= l || r <= s) return;
    if (s <= l && r <= t) {
        A[k] += x;
    } else {
        add(s, t, x, 2*k, l, (l+r)/2);
        add(s, t, x, 2*k+1, (l+r)/2, r);
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
            add(s, t+1, x, 1, 0, n);
        } else if (op == 1) {int x; cin >> x; printf("%d\n", get(x));}
        else runtime_error("wrong");
    }
}