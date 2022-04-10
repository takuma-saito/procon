#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N=100000;
int A[MAX_N];

// [l, r)
int partition(int l, int r) {
    int x = A[r-1];
    int k = l;
    for(int i=l; i<r-1; i++) {
        if (A[i]<=x) {swap(A[i], A[k++]);}
    }
    swap(A[k], A[r-1]);
    return k;
}

int main()
{
    int n; cin >> n;
    rep(i, n) {cin >> A[i];}
    int k = partition(0, n);
    rep(i, n) {printf("%s%d%s%s", k==i?"[":"", A[i], k==i?"]":"", i==n-1?"\n":" ");}
}