#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int M1, D1, M2, D2; cin >> M1 >> D1 >> M2 >> D2;
    printf("%d\n", (M2 == M1+1 && D2 == 1));
}