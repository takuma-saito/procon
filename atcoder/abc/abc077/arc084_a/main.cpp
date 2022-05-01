#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 1e5;
int N; int A[MAX_N]; int B[MAX_N]; int C[MAX_N];

int main()
{
    int ans=0;
    cin >> N;
    for(auto &x: {A, B, C}) rep(i, N) cin >> x[i];
    for(auto &x: {A, B, C}) sort(x, x+N);
    for(int i=0; i<N; i++) {
        int d = upper_bound(B, B+N, A[i]) - B;
        for(int j=d; j<N; j++) {
            ans += C + N - upper_bound(C, C+N, B[j]);
        }
    }
    printf("%d\n", ans);
}