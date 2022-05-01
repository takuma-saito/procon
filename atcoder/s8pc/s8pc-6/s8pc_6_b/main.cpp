#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 30;
int64_t A[MAX_N]; int64_t B[MAX_N];

int solve(int64_t* X, int n) {
    int64_t pos = 0, ans = (1llu<<63)-1;
    rep(i, n) {
        int64_t sum = 0; rep(j, n) sum += abs(X[i]-X[j]);
        if (ans > sum) {
            ans = sum;
            pos = i;
        }
    }
    return pos;
}

int main()
{
    int N; cin >> N;
    rep(i, N) cin >> A[i] >> B[i];
    int a = solve(A, N), b = solve(B, N);
    int64_t sum = 0; rep(i, N) sum += abs(A[a]-A[i]) + abs(A[i]-B[i]) + abs(B[b]-B[i]);
    printf("%lld\n", sum);
}