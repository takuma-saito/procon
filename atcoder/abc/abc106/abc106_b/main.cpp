#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N; cin >> N;
    int ans = 0;
    for(int i=3; i<=N; i++) {
        if (i%2==0) continue;
        int d = 2;
        for(int j=3; j<i; j++) if (i%j==0) d++;
        if (d == 8) ans++;
    }
    printf("%d\n", ans);
}