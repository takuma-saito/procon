#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// E_{i} = E_{i-1} + N/i
// p=i/N に従う幾何分布の期待値は N/i

int main()
{
    int N; cin >> N;
    double e=0; for(int i=1; i<=N; i++) { e += (N/double(i)); }
    printf("%.12lf\n", e);
}