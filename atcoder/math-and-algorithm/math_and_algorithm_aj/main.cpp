#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 1e5+1;
int A[MAX_N] = {};

int main()
{
    int N, Q; cin >> N >> Q; while(Q--) {
        int l, r, x; cin >> l >> r >> x;
        A[l] += x; A[r+1] -= x;
    }
    for(int i=1; i<=N; i++) { A[i] += A[i-1]; }
    for(int i=1; i<N; i++) {
        string s;
        if (A[i] < A[i+1]) s="<";
        else if (A[i] > A[i+1]) s=">";
        else s="=";
        printf("%s", s.c_str());
    }
    printf("\n");
}