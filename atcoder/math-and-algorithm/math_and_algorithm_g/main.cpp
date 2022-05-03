#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N, X, Y; cin >> N >> X >> Y;
    printf("%d\n", (N/X)+(N/Y)-(N*gcd(X,Y)/(X*Y)));
}