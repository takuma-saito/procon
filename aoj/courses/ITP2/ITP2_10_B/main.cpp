#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void dump(int b) {
    for(int i=31; i>=0; i--) printf("%d%s", b>>i&1, i==0?"\n":"");
}

int main()
{
    uint32_t a, b; cin >> a >> b;
    for(auto x: {a&b, a|b, a^b}) dump(x);
}