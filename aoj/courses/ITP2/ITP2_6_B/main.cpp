#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 2e5;
int N, M; int A[MAX_N]; int B[MAX_N];

int main()
{
    cin >> N; rep(i, N) cin >> A[i];
    cin >> M; rep(i, M) cin >> B[i];
    printf("%d\n", includes(A, A+N, B, B+M));
}