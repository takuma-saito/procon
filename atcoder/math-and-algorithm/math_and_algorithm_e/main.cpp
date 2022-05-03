#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N, sum=0; cin >> N; while(N--) {
        int x; cin >> x; sum=(sum+x)%100;
    }
    printf("%d\n", sum);
}