#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int a, b; cin >> a >> b;
    int x=min(a, b), y=max(a, b);
    while (x>0)  { int v=x; x=y%x; y=v; }
    printf("%d\n", y);
}