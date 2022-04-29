#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void dump(int b) {
    for(int i=31; i>=0; i--) printf("%d%s", b>>i&1, i==0?"\n":"");
}

int main()
{
    uint32_t x; cin >> x;
    for(auto a: {x, ~x, x<<1, x>>1}) dump(a);
}