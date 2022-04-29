#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 10;
int N; int A[MAX_N]; int B[MAX_N];

void dump(int* A, int N) {
    rep(i, N) printf("%d%s", A[i], i==N-1?"\n":" ");
}

int main()
{
    int count=0;
    vector<int> vec;
    fill(A, A+MAX_N, -1);
    cin >> N; rep(i, N) cin >> A[i];
    copy(A, A+N, B);
    if (prev_permutation(A, A+N)) dump(A, N);
    dump(B, N);
    if (next_permutation(B, B+N)) dump(B, N);
}