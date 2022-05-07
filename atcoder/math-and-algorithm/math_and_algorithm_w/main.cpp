#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MAX_N = 1e5;
const int K = 101;
int N; int B[K] = {};  int R[K] = {};

int main()
{
    cin >> N;
    rep(i, N) { int b; cin >> b; B[b]++; };
    rep(i, N) { int r; cin >> r; R[r]++; };
    double ans=0; rep(k, 201) {
        double prob = 0;
        for(int i=0; i<=k; i++) if(k-i>=0 && k-i<K && i<K) {
             prob += double(B[i])/N * double(R[k-i])/N;
        }
        ans += k * prob;
    }
    printf("%0.10f\n", ans);
}