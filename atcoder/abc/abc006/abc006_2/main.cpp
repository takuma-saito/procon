#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 10007;
int A[3] = {0, 0, 1};

int main()
{
    int N; cin >> N;
    rep(i, N-1) {
        int sum = 0; rep(j, 3) {
            sum = (sum+A[j])%MOD;
        }
        for(int i=0; i<2; i++) A[i] = A[i+1];
        A[2] = sum;
    }
    printf("%d\n", A[0]);
}