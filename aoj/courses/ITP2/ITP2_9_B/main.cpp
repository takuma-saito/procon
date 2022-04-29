#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 2e5;
int N, M; int A[MAX_N]; int B[MAX_N];

int main()
{
    vector<int> vec;
    cin >> N; rep(i, N) cin >> A[i];
    cin >> M; rep(i, M) cin >> B[i];
    set_intersection(A, A+N, B, B+M, inserter(vec, vec.end()));
    rep(i, vec.size()) printf("%d\n", vec[i]);
}