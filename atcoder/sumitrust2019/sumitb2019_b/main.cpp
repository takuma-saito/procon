#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// N = FLOOR(X*1.08)

int main()
{
    int N; cin >> N;
    double ans = N/1.08;
    if (int(floor(floor(ans)*1.08)) == N) printf("%d\n", int(floor(ans)));
    else if (int(floor(ceil(ans)*1.08)) == N) printf("%d\n", int(ceil(ans)));
    else printf(":(\n");
}