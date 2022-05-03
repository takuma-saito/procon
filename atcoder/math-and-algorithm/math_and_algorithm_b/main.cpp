#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int sum=0; rep(i, 3) {
        int x; cin >> x; sum+=x;
    }
    printf("%d\n", sum);
}