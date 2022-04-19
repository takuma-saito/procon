#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 100001;
int A[MAX_N];
int n, q;

void add(int i, int x) {
    while (i<=n) {
        A[i] += x;
        i += (-i)&i;
    }
}

int getSum(int i) {
    int sum = 0;
    while (i>0) {
        sum += A[i];
        i &= (i-1);
    }
    return sum;
}

int main()
{
    cin >> n >> q;
    fill(A, A+MAX_N, 0);
    rep(i, q) {
        int com, x, y; cin >> com >> x >> y;
        if (com == 0) add(x, y);
        else if (com == 1) printf("%d\n", (getSum(y) - getSum(x-1)));
        else runtime_error("wrong");
    }
}