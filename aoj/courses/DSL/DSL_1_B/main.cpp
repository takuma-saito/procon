#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 10000;
int utree[MAX_N], urank[MAX_N], uweight[MAX_N]; // TODO: 初期化

void init(int N) {
    rep(i, N) { urank[i] = 0; utree[i] = i; uweight[i] = 0;}
}

int find(int n) {
    if (utree[n] == n) return n;
    else return utree[n] = find(utree[n]);
}

void unite(int x, int y, int z) {
    x = find(x);
    y = find(y);
    if (urank[x] > urank[y]) {
        utree[x] = y;
    } else {
        utree[y] = x;
        if (urank[x] == urank[y]) urank[x]++;
    }
}

bool same(int x, int y) {
    return find(x) == find(y);
}

int main()
{
    int N, Q; cin >> N >> Q;
    init(N);
    rep(i, Q) {
        int x, y, com; cin >> com >> x >> y;
        if (com == 0) unite(x, y);
        else if (com == 1) printf("%d\n", same(x,y)?1:0);
        else runtime_error("wrong op");
    }
}