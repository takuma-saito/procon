#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int ans=1; rep(i, 3) {
        int x; cin >> x; ans*=x;
    }
    printf("%d\n", ans);
}