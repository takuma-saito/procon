#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int U, N, K;

int main()
{
    vector<int> vec;
    cin >> N >> K;
    rep(i, K) {int t; cin >> t; U |= (1<<t);}
    int x = U;
    do {
        vec.push_back(x);
        x = U&(x-1);
    } while (x!=U);
    reverse(vec.begin(), vec.end());
    for(int x: vec) {
        printf("%d:", x);
        for(int i=0; i<N; i++) if (x>>i&1) printf(" %d", i);
        printf("\n");
    }
}