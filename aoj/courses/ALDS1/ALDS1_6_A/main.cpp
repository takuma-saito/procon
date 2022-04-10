#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 2000001, MAX_A = 10000;
int n, A[MAX_N], B[MAX_N], C[MAX_A] = {};

void countingSort() {
    for(int i=1; i<=n; i++) { C[A[i]]++; }
    for(int j=1; j<MAX_A; j++) {C[j] += C[j-1];}
    for(int i=n; i>0; i--) {
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }
    for(int i=1; i<=n; i++) {
        printf("%d%s", B[i], i==n?"\n":" ");
    }
}

int main()
{
    cin >> n;
    rep(i, n) {cin >> A[i+1];}
    countingSort();
}